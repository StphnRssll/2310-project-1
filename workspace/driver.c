/*****************
Stephen Russell
SRUSSE5 
Ciara Morrissey
CIARA4 
CPSC 2310 F21 - section 002
PA1 - DUE OCT. 8
*****************/
/* This file was provided by the starter code */
// your declarations (and certain types of definitions) here
#include <stdio.h>
#include "./utils.h"
#define EXIT_SUCCESS 0 


int main(int argc, char* argv[])
{
    checkArgs(argc, 3);
    FILE* in = fopen(argv[1], "r");
    checkFile(in);
    FILE* out = fopen(argv[2], "w");
    checkFile(out);
    /*This is my test message.  It can be something different*/
    char* msg = "I hope this works!";
    // encodeMsg(in, out, msg);

    // from stephen: this reads the file we just made into [dec]
    FILE* dec = fopen(argv[3], "r");
    checkFile(dec);
    decodeMsg(dec);

    // fclose(in);
    // fclose(out);
    // fclose(dec);

    return EXIT_SUCCESS;
}