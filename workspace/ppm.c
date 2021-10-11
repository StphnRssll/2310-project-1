/*****************
Stephen Russell
SRUSSE5 
Ciara Morrissey
CIARA4 
CPSC 2310 F21 - section 002
PA1 - DUE OCT. 8
*****************/
/* This file is where we implement the functions listed in the ppm.h file. */
#include <stdio.h>
#include <stdlib.h>
#include "./utils.h"

/* 
Parameters:
    - in: a pointer to the input ppm file
Returns:
    - header_t containing the ppm's following information:
        - magicNum[3]
        - int width
        - int height
        - int maxVal
Reads the header information of a ppm file.*/
header_t readHeader(FILE* in){
    header_t *header = (header_t *)malloc(sizeof(header_t));
    char lineSkipper[50];
    // 1st line: get magicNum
    fscanf(in, "%s\n", header->magicNum);
    // 2nd line: skip
    fgets(lineSkipper,256,in);
    // 3rd line: get width and height
    fscanf(in, "%d %d", &header->width, &header->height);
    // 4th line: get maxVal
    fscanf(in, "%d", &header->maxVal);
    return *header;
}

/* 
Parameters: 
    -filePointer:
    -hdr:
Returns: 
Reads the values of the pixels in the ppm image by:
    - Dynamically allocating the memory for the 2D array. 
    - Reads in the pixels from the image storing the pixels in the 2D array 
    - Returns the 2D array. */
// note: DON'T ALLOCATE MEMORY FOR THE POINTERS ON THE STACK
// pixel_t** readPixel(FILE* filePointer, header_t hdr){
//     // FROM STEPHEN: commented this out so i can compile w/out warnings
//      pix = malloc(hdr.height * sizeof(struct pixel*));

//     for (int i=0; i<hdr.height; i++) {
//         pix[i] = malloc(hdr.width * sizeof(struct pixel));
//     }
    

// }

/*
Parameters:
    - out: the output file we are writing the header for
    - hdr: the hdr we are writing to the output ppm
Returns: void
Writes header information to the output ppm file using fprintf*/
void writeHeader(FILE* out, header_t hdr){
    fprintf(out,"%d %d %d %d\n", hdr.maxVal, hdr.width, hdr.height, hdr.maxVal);
}

/*
Parameters: 
Returns: 
Writes the pixels to the output ppm file using fprintf*/
void writePixels(FILE* filePointer, pixel_t** pix, header_t hdr){
   
}

// extra credit, something to do with ignoring comments
// void ckws_comments (FILE* filePointer){

// }

/*
Parameters: 
Returns: 
Frees memory used during program*/
void freeMemory(pixel_t** pix, header_t hdr){

}