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
channel in the pixel and replace it with 0. (What???)  Consider the following:
    - If the red channel of the first pixel has an integer value of 255, you 
    need to reduce the value by 5 to equal 250.*/
void removeDigit(pixel_t** , header_t );

/*
As shown in the above image, for each character, this function should add 
a 1 or 0 to the value of each of the three channels for the three pixels. 
Below are the steps I took in my function.
1.	Create the local variables needed for this function.  
    This included a couple counters, one for the character counter, 
    which came in handy when accessing the char * msg, which is holding 
    the literal string that represents the message you will encode. 
    One for the bit counter. I also have an int array to hold the 9 
    values that will be added to the 3 RGB values for the 3 pixels. 
2.	Call writeHeader.
3.	For each character in the message convert the character to it’s 
    binary number equivalent. (charToBinary function).  
4.	Encode the binary number in the image.  
5.	After you have looped through all the pixels and there are no 
    more characters to encode write the new pixels to the output 
    file by calling writePixels. 
    You will need nested loops and some if statements for this function. 
*/
void encodeMsg(FILE* in, FILE* out, char* msg);

void charToBinary(char , int *);

/* This function is used to convert a binary number to decimal. 
   Notice this is returned as an unsigned char.  
   Remember we are working with three pixels which equals 9 bits,
   but the most significant bit is always 0. Why???*/
unsigned char binToCharacter(int*);

/* This function is called by decodeMsg.
    As the decodeMsg function grabs the onesdigit of each pixel channel 
    (red,green, and blue) it passes that value to queue as “n”.
    This function keeps track of the “n’s” passed to the function. 
    Notice bin is an array which should be of size 9. An array created in decodeMsg
    is passed to queue, a.k.a. bin.
    Also, “index” is a pointer that is pointing to a variable passed to queue by decodeMsg.
    The queue function will continue to add the digit represented by “n” to bin
    until 9 digits have been added. Once 9 digits (1 or 0) are received you now
    have the binary bits needed to convert the content of bin to a character by calling binToCharacter. Obviously, the character returned from binToCharacter should be less than 256. 
    If the value retuned from binToCharacter is less than 256 then queue prints the character. 
*/
void queue(int, int*, int*);

// This function converts a decimal number to binary storing the bits in an array.  
void dec2bin(int*, int);

/*
There are several steps needed to decode the message.  
1.	Since this is an ppm file that the message is encoded in you first 
    should call readHeader to read the header of the encoded ppm image. 
2.	Allocate the memory for the pixels of the encoded ppm image. 
        Suggestion:  you could create a function that allocates the memory 
        for the pixels then return the double pointer. 
3.	Call readPixel to read the pixels of the encoded ppm image storing 
    them in the memory you just allocated.
4.	Grab the last digit of the red, green, and blue numbers. When you grab 
    these digits save them as integers. 
    You should have an integer variable each for red, green, and blue. 
5.	For each number you grab send it to the queue function. 
6.	You will continue this process for all pixels in the image. 
    As an example, for the first red digit I grab I will call queue passing 
    in the digit, an array that will be used by queue to store this digit 
    and the address of a variable that will be used to keep track of the 
    number of digits passed to queue. 
*/
void decodeMsg(FILE*);
#endif
