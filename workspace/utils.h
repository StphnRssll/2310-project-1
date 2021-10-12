/*****************
Stephen Russell
SRUSSE5 
Ciara Morrissey
CIARA4 
CPSC 2310 F21 - section 002
PA1 - DUE OCT. 8
*****************/
/* This file was provided by the starter code.
Provides the prototypes for two functions needed to check the number of 
command line arguments passed to the program. It also
contains a function that check if the file pointers opened successfully. */
#include "./EncodeDecode.h"
#include "./ppm.h"

/* This function checks that the appropriate number of command line arguments 
   were used when running the program. 
   If the appropriate number of command line arguments are not passed 
   to the command line you should print a message to stderr that tells 
   the user that there were not enough command line arguments 
   and exit the program. */
void checkArgs(int actualArgCount, int desiredArgCount);

/* This function should check if the file pointer opened successfully. 
   Basically, check if the file pointer is NULL.  
   If it is NULL, print to stderr a message that states the file 
   did not open correctly and exit the program. 
*/
void checkFile(FILE*);