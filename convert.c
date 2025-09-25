#include "convert.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void oct_to_bin(const char* oct, char* out) {
    int pos = 0;
    
        if (oct[0] == '0' && oct[1] == '\0') {   //handles 0 case
            out[0] = '0';
            out[1] = '\0';
            return;
        }
        for (int i = 0; oct[i] != '\0'; i++) {    //converts each octal digit to its 3 bit binary equivalent
            int octal_digit = oct[i] - '0';
            out[pos++] = (octal_digit >> 2) & 1 ? '1' : '0';
            out[pos++] = (octal_digit >> 1) & 1 ? '1' : '0';
            out[pos++] = (octal_digit >> 0) & 1 ? '1' : '0';
        }
        out[pos] = '\0';
}

void oct_to_hex(const char* oct, char* out) {
    char temp[65];
    int pos = 0;
    
    for (int i = 0; oct[i] != '\0'; i ++) {     //converts each octal digit to its 3 bit binary equivalent and stores it in a temporary string
        int octal_digit = oct[i] - '0';
        temp[pos++] = (octal_digit >> 2) & 1 ? '1' : '0';
        temp[pos++] = (octal_digit >> 1) & 1 ? '1' : '0';
        temp[pos++] = (octal_digit >> 0) & 1 ? '1' : '0';
    }
    temp[pos] = '\0';

    int fourbit_groups = (4 - (pos % 4)) % 4;    //breaks the binary string into groups of 4 bits, padding with leading zeros if necessary
    for (int i = pos - 1; i >= 0; i--) {
        temp[i + fourbit_groups] = temp[i];
    }
    for (int i = 0; i < fourbit_groups; i++) { 
        temp[i] = '0';
    }

    int hex_pos = 0;
    int start = 0;
    for (int i = 0; i < pos + fourbit_groups; i += 4) {       //converts each group of 4 bits to its hexadecimal equivalent
        int hex_digit = (temp[i] - '0') * 8 + (temp[i + 1] - '0') * 4 + (temp[i + 2] - '0') * 2 + (temp[i + 3] - '0');
        if (!start && hex_digit == 0) {
            continue;
        }
        start = 1;
        if (hex_digit < 10) {
            out[hex_pos++] = '0' + hex_digit;
        } else {
            out[hex_pos++] = 'A' + (hex_digit - 10);
        }
    }
    if (hex_pos == 0) {                                       //handles 0 case
        out[hex_pos++] = '0';
    }
    out[hex_pos] = '\0';
}

void hex_to_bin(const char* hex, char* out) {
    int pos = 0;

    for (int i = 0; hex[i] != '\0'; i++) {        //converts each hex digit to its 4 bit binary equivalent
        int hex_digit = 0;
        if (hex[i] >= '0' && hex[i] <= '9') {
            hex_digit = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            hex_digit = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            hex_digit = hex[i] - 'a' + 10;
        } else {
            continue;
        }
        out[pos++] = (hex_digit >> 3) & 1 ? '1' : '0';
        out[pos++] = (hex_digit >> 2) & 1 ? '1' : '0';
        out[pos++] = (hex_digit >> 1) & 1 ? '1' : '0';
        out[pos++] = (hex_digit >> 0) & 1 ? '1' : '0';
    }
    out[pos] = '\0';
}

void to_sign_magnitude(const char* in, char* out) {
    int num = strtol(in, NULL, 0);                   //converts string to long integer
    if (num >= 0) {                                  //handles positive numbers
        out[0] = '0';
        for (int i = 30; i >= 0; i--) {
            out[31 - i] = ((num >> i) & 1) ? '1' : '0';
        }
    } else {                                         //handles negative numbers
        out[0] = '1';
        int abs_n = -num;
        for (int i = 30; i >= 0; i--) {
            out[31 - i] = ((abs_n >> i) & 1) ? '1' : '0';
        }
    }
    out[32] = '\0';
}

void to_ones_complement(const char* in, char* out) {
    int num = strtol(in, NULL, 0);                    //converts string to long integer
    if (num >= 0) {                                   //handles positive numbers
        out[0] = '0';
        for (int i = 30; i >= 0; i--) {
            out[31 - i] = ((num >> i) & 1) ? '1' : '0';
        }
    } else {                                          //handles negative numbers
        out[0] = '1';
        int abs_n = -num;
        for (int i = 30; i >= 0; i--) {
            out[31 - i] = ((abs_n >> i) & 1) ? '0' : '1';
        }
    }
    out[32] = '\0';
}

void to_twos_complement(const char* in, char* out) {
    int num = strtol(in, NULL, 0);                   //converts string to long integer                
    unsigned int val;   
    if (num >= 0) {                                  //handles positive numbers
        out[0] = '0';
        val = num;                                   //handles negative numbers
    } else {
        out[0] = '1';                                 
        val = (unsigned int)num;
    }
    for (int i = 30; i >= 0; i--) {                 //converts each bit to its 2's complement equivalent           
        out[31 - i] = ((val >> i) & 1) ? '1' : '0';
    }
    out[32] = '\0';
}