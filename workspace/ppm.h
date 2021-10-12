/*****************
Stephen Russell
SRUSSE5 
Ciara Morrissey
CIARA4 
CPSC 2310 F21 - section 002
PA1 - DUE OCT. 8
*****************/
/* This file was provided by the starter code.
Contains the prototypes of the functions we implement. 
These functions deal specifically with a ppm file. 
It also provides the definition of two structs:
a.	One for the header.
b.	One for the pixels */
#ifndef PPM_H
#define PPM_H

typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}pixel_t;

typedef struct
{
    char magicNum[3];
    int width;
    int height;
    int maxVal;
}header_t;

// This function reads the header information of a ppm file. 
header_t readHeader(FILE*);

/* This function reads the values of the pixels in the ppm image. 
Notice this function has a return value. It is in this function, 
that you will dynamically allocate the memory for the 2D array. 
We discussed several versions of allocating memory for a 2D array.  
You may use any of these methods EXCEPT the one that allocates 
memory for the pointers on the stack. 
If you are not sure about which method not to use, you should come see me. 

You will then read in the pixels from the image storing 
the pixels in the 2D array you just created and return the 2D array. 
*/
pixel_t** readPixels(FILE*, header_t);

// This function will be used to write the header to the output ppm file. 
// Use fprintf to write the header information to the output file.
void writeHeader(FILE*, header_t);

// This function will be used to write the pixels to the output ppm file.
// Use fprintf to write the pixels to the output file.
void writePixels(FILE*, pixel_t**, header_t);
void ckws_comments (FILE *);
void freeMemory(pixel_t**, header_t);
#endif
