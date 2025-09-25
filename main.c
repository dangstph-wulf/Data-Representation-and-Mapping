#include "convert.c"
#include <stdio.h>

int main() {
    FILE *testFile = fopen("A2_tests.txt", "r");       //opens the test file to read
    FILE *outFile = fopen("output.txt", "w");          //creates an output file to display results

    if (testFile == NULL || outFile == NULL) {                //handles if either files are missing/not correct
        printf("Error: File could not be open or found");
        return 1;
    }

    int testNum = 1;          
    int passCount = 0;            
    char line[256];
    while (fgets(line, sizeof(line), testFile) != NULL) {
        line[strcspn(line, "\n")] = '\0';                     //removes newline

        char *tokens[50];
        int count = 0;

        char *token = strtok(line, " ");        //divides the variables in each line by the " " delimiter and setting them to the tokens array
        while (token != NULL && count < 50) {
            tokens[count++] = token;
            token = strtok(NULL, " ");
        }

        if (count == 0) continue;

        char *func = tokens[0];
        char output[256];

        if (strcmp(func, "oct_to_bin") == 0) {         //checks to see which function to call before setting variables and calling the tests to run
            const char *input = tokens[1];
            const char *expected = tokens[2];
            oct_to_bin(input, output);
            if (strcmp(output, expected) == 0) {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got: %s [PASS]\n", testNum, func, input, expected, output);
                passCount++;
            }
            else {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got: %s [FAILED]\n", testNum, func, input, expected, output);
            }
        } 
        else if (strcmp(func, "oct_to_hex") == 0) {     
            const char *input = tokens[1];
            const char *expected = tokens[2];
            oct_to_hex(input, output);
            if (strcmp(output, expected) == 0) {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got: %s [PASS]\n", testNum, func, input, expected, output);
                passCount++;
            }
            else {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got: %s [FAILED]\n", testNum, func, input, expected, output);
            }
        }    
        else if (strcmp(func, "hex_to_bin") == 0) {
            const char *input = tokens[1];
            const char *expected = tokens[2];
            hex_to_bin(input, output);
            if (strcmp(output, expected) == 0) {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got: %s [PASS]\n", testNum, func, input, expected, output);
                passCount++;
            }
            else {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got %s [FAILED]\n", testNum, func, input, expected, output);
            }
        }
        else if (strcmp(func, "to_sign_magnitude") == 0) {
            const char *input = tokens[1];
            const char *expected = tokens[2];
            to_sign_magnitude(input, output);
            if (strcmp(output, expected) == 0) {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got %s [PASS]\n", testNum, func, input, expected, output);
                passCount++;
            }
            else {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got %s [FAILED]\n", testNum, func, input, expected, output);
            }
        }
        else if (strcmp(func, "to_ones_complement") == 0) {
            const char *input = tokens[1];
            const char *expected = tokens[2];
            to_ones_complement(input, output);
            if (strcmp(output, expected) == 0) {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got %s [PASS]\n", testNum, func, input, expected, output);
                passCount++;
            }
            else {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got %s [FAILED]\n", testNum, func, input, expected, output);
            }
        }
        else if (strcmp(func, "to_twos_complement") == 0) {
            const char *input = tokens[1];
            const char *expected = tokens[2];
            to_twos_complement(input, output);
            if (strcmp(output, expected) == 0) {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got %s [PASS]\n", testNum, func, input, expected, output);
                passCount++;
            }
            else {
                fprintf(outFile, "Test %d: %s(%s) -> Expected: %s, Got %s [FAILED]\n", testNum, func, input, expected, output);
            }
        }
        testNum++;
    }
    
    fprintf(outFile, "\nSummary: %d/%d tests passed\n", passCount, testNum - 1);

    fclose(outFile);
    fclose(testFile);
    fprintf(stderr, "File was successfully written to.\n");
    
    return 0;
}