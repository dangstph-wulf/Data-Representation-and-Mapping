
# CS 3503 Assignment 2 - Data Representation and Mapping

## Author
[Stephen Dang]

## Description
My personal implementation of a more adavanced number base conversion system written in C using Visual Studio Code. It takes in a constant string and converts it from either octal to binary, octal to hexadecimal, hexadecimal to binary, or into its signed magnitude, ones complement, or twos complement forms.

## Build Instructions

### Prerequisites
- gcc (MinGW or MSYS2) on Windows
- All source files (`main.c`, `convert.c`, `convert.h`) within the same folder

### Build
Open a terminal in your project directory and run:
```bash
gcc convert.c main.c -o Assignment2
```
This will create an executable named `Assignment2.exe`.

### Run
To run the program:
```
Assignment2
```
Included in the repo is template document called `a2_test_file` which contains the tests that need to be put within a separate .txt called `A2_tests.txt`.

Make sure `A2_tests.txt` is in the same directory as the executable.

### Output
Results will be written to `output.txt` in the same directory.

## Test Results
[Summary: 51/51 tests passed]
