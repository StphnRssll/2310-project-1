/*****************
Stephen Russell
SRUSSE5
Ciara Morrissey
CIARA4
CPSC 2310 F21 - section 002
PA1 - DUE OCT. 8
*****************/
/* This file was provided by Feaster
Contains additional prototypes of functions she needed to encode and
decode a message in an image. */
#include "./ppm.h"
#ifndef ENCODEDECODE_H
#define ENCODEDECODE_H


/* This function will be used to remove the value of the ones place of each
channel in the pixel and replace it with 0.
  Example:
    -If the red channel of the first pixel has an integer value of 255, you
    need to reduce the value by 5 to equal 250.*/
/* Parameters:
  - pixel: pixel_t struct pointer to the pixel we want to modify
  - header: header_t struct of the pixel we want to modify
Return: void, no return*/
/*Removes the value of the ones place of each channel in the pixel
and replaces it with 0. For example, if the red channel of the first pixel
has an integer value of 255, it reduces the value by 5 to equal 250.*/
void removeDigit(pixel_t** , header_t );





/*
Parameters:
    -in: input file pointer with data to encode
    -out: output file pointer to write the data to
    -msg: char pointer, message to be encoded

Return: void

Implements the logic described in the image in the PA1Specs document.
For each character, adds a 1 or 0 to the value of each of the three channels
for the three pixels.

Steps:
1.	Declare necessary local variables
    - character counter, helpful when accessing the char * msg which holds
      the literal string that represents the message you will encode.
    - a bit counter
    - an int array to hold the 9 values that will be added to the 3 RGB
      values for the 3 pixels
2.	Call writeHeader
3.	Use charToBinary() to convert each character in the message to its
    binary number equivalent.
4.	Encode the binary number in the image.
5.	After looping through all pixels, when there are no more characters left...
    Use writePixels() to write the new pixels to the output file
    (You will need nested loops and some if statements for this function)
*/
void encodeMsg(FILE* in, FILE* out, char* msg);




/*
Parameters:
  -character: character value to be converted
  -binArray: array that will hold the binary value
Returns: void
*/
/*No description in doc specs, simple purpose function that will convert a
character value to an array value and store that in an integer pointer, hence
the void return*/
void charToBinary(char character, int * binArray);





/*
Parameters: one int* parameter will be the binary value being converted
Returns: unsigned char return */
/* This function is used to convert a binary number to decimal.*/
unsigned char binToCharacter(int*);

/*
Parameters:
Returns: void
(Called by decodeMsg... As the decodeMsg function grabs the onesdigit of each
pixel channel (red,green, and blue) it passes that value to queue as “n”.)

Keeps track of the “n’s” passed to the function.

Notice bin is an array which should be of size 9.

An array created in decodeMsg is passed to queue, a.k.a. bin.

Also, “index” is a pointer that is pointing to a variable passed to
queue by decodeMsg.

The queue function will continue to add the digit represented by “n” to bin
until 9 digits have been added.

Once 9 digits (1 or 0) are received you now have the binary bits needed
to convert the content of bin to a character by calling binToCharacter.

Obviously, the character returned from binToCharacter should be less than 256.

If the value retuned from binToCharacter is less than 256 then
queue prints the character.
*/
void queue(int, int*, int*);

/*
Parameters:
  -bitArray: int* that will serve as the array for the binary value to be
  stored in
  -num: int that will be the decimal number to be converted
Returns: void
Converts a decimal number to binary, storing the bits in an array. */
/*This function converts a decimal number to binary storing the bits in
an array.*/
void dec2bin(int*, int);

/*
Parameter:
  -in: input file pointer

Returns: void
1.	Calls readHeader() to read the header of the encoded ppm image
2.	Allocates the memory for the pixels of the encoded ppm image.
        Suggestion:  you could create a function that allocates the memory
        for the pixels then return the double pointer.
3.	Uses readPixel() calls to read the pixels of the encoded ppm image,
    storing them in the memory it just allocated.
4.	Grabs the last digit of the red, green, and blue numbers,
    saves them as integers (int red, int green, int blue)
5.	Sends each number it's grabbed to the queue function.
6.	Continues this process for all pixels in the image.
    As an example:
    for the first red digit I grab I will:
        - call queue(digit, arr, address),
          where [digit] is the digit
                [arr] is an array that'll be used by queue to store this digit
            and [address] is the address of a variable that will be used to
                keep track of the number of digits passed to queue.*/
void decodeMsg(FILE*);
#endif
