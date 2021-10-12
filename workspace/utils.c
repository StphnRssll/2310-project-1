/*****************
Stephen Russell
SRUSSE5 
Ciara Morrissey
CIARA4 
CPSC 2310 F21 - section 002
PA1 - DUE OCT. 8
*****************/
/* This file is where we implement the functions for utils.h */
#include <stdio.h>
#include <stdlib.h>
#include "./utils.h"

/* 
Parameters: 
    - argCount: integer representing actual count of arguments
    - desiredArgPassedCount: integer representing desired count of arguments
Returns: void
Checks that the appropriate number of command line arguments were used when 
running the program. If the appropriate number of command line arguments are 
not passed, the function prints a message to stderr that tells the user that
there were not enough command line arguments and exits the program. */
void checkArgs(int argCount, int desiredArgPassedCount){
    if(argCount != desiredArgPassedCount+1){
        fprintf(stderr, "You passed %d arg(s). You must pass %d args.\n", argCount, desiredArgPassedCount);
        exit(-1);
    }
};

/* 
Parameters: 
    - filePointer: the pointer to the file being checked
Returns: void
Checks if the file pointer opened successfully. 
If the file pointer is NULL, prints a message to stderr stating the file
did not open correctly and exits the program. */
void checkFile(FILE* filePointer){
    if(filePointer == NULL){
        fprintf(stderr, "The file did not open correctly\n");
        exit(-1);
    }
};