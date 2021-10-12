/****************
Stephen Russell
SRUSSE5
Ciara Morrissey
CIARA4
CPSC 2310 F21 - section 002
PA1 - DUE OCT. 8
*****************/
/* This file is where we implement the functions listed in EncodeDecode.h */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./EncodeDecode.h"
#include "./utils.h"

/*Removes the value of the ones place of each channel in the pixel
and replaces it with 0.*/
void removeDigit(pixel_t** pixel, header_t header){

};

/*
1.	Declare necessary local variables
2.	Call writeHeader
3.	Use charToBinary() to convert each character in the message to its
    binary number equivalent.
4.	Encode the binary number in the image.
5.	Use writePixels() to write the new pixels to the output file
  
*/
void encodeMsg(FILE* in, FILE* out, char* msg){
    // step 1: declare variables
     int charCounter = 0;
     int bitCounter = 7;
     /*nine values to be added to RGB pixels*/
     int vals[9];
     pixel_t** pix;

    // step 2: call readHeader, passing in our original ppm's header
    header_t h = readHeader(in);
    pix = readPixel(in, h)

    // step 3: write the header info to output file
    writeHeader(out, h);

    /*removes last digit from data containing pixels*/
    removeDigit(pix, h);

    /*calculate char count of msg*/
    while(msg[charCounter+1] != '\0'){
      charCounter = charCounter+1;
    }

    /*loop through pixel data in order to Encode
    add last digit of message to pixels*/
    for(int i = 0; i<charCounter+1; i++){
      charToBinary(msg[i], temp);
    }

  /**************I STOPPED WORKING HERE - CM**********************/

    // allocate msgAs2DArrayOfBinary
    int msgLength = strlen(msg);
    int rows = msgLength;
    int cols = 8;
    int* msgAs2DArrayOfBinary[rows];
    for (int i = 0; i < rows; i++){
        msgAs2DArrayOfBinary[i] = (int*)malloc(cols * sizeof(int));
    }
    // Loop through msg[] for the length of the message, store each character
    // in its binary form in msgAs2DArrayOfBinary[]
    for(int i = 0; i < msgLength; i++){
        charToBinary(msg[i],msgAs2DArrayOfBinary[i]);
    }

    // testing that msg[] is properly populated
    // for(int i = 0; i < msgLength; i++){
    //    printf("msg[i]: %c",msg[i]);
    //     for(int j=0;j<8;j++){
    //         printf("%d", msgAs2DArrayOfBinary[i][j]);
    //     }
    //     printf("\n");
    // }

    // testing that charToBin and binToCharacter work correctly
    // for(int i = 0; i < msgLength; i++){
    //     printf("msg[i]: %c ... ",(unsigned char)msg[i]);
    //     // printf("binToCharacter(msgAs2DArrayOfBinary[i]): %hhu", (char)binToCharacter(msgAs2DArrayOfBinary[i]));
    //     printf("binToChar msgAs2DArr[0]: %c", binToCharacter(msgAs2DArrayOfBinary[i]));
    //     printf("\n");
    // }

    // step 4: Encode the binary number in the image
    //  - 4.1 get original image
    //      - 4.1.1 test this before moving on
}


/*convert from a character to binary value */
void charToBinary(char character, int *binArray){
    int i = 8;
    while (character > 0){
        binArray[i] = character%2;
        character = character/2;
        i--;
    }
};

/*Converts a binary number to char.*/
 unsigned char binToCharacter(int* integer){
     /*use strol to convert from a string into a long int*/
     /*parameters:  string containing the binary, the beginning & the base*/
     //unsigned char c = strtol(integer, 0, 2);
     //return c;

     /*the values of the powers of 2, will be useful in conversion*/
     int values[8] = {128, 64, 32, 16, 8, 4, 2, 1};
     int sum = 0;
     unsigned char charConvert;

     /*convert from binary to char*/
     for(int i = 1; i<9; i++){
       if(integer[i] == 1){
         sum = sum + values[i-1];
       }
     }

     /*cast to unsigned char to match return type*/
     charConvert = ((unsigned char) sum);
     return charConvert;
 }

/*
(Called by decodeMsg... As the decodeMsg function grabs the onesdigit of each
pixel channel (red, green, and blue) it passes that value to queue as “n”.)

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
void queue(int digit, int* digitArr, int* digitCounter){
    // append digit to digitArr and increment digitCounter
    digitArr[*digitCounter] = digit;
    *digitCounter++;
    // if digitCounter >=9, convert digitArr to a char and print
    if(digitCounter>=9){
        binToCharacter(digitArr)
    }
};

/*Converts a decimal number to binary, storing the bits in an array. */
void dec2bin(int* bitArray, int num){

  /*array to store binary number*/
  /* it will be backwards at first */
  int binaryBackwards[32];

          // counter for binary array
          int i = 0;
          while (num > 0) {
              // storing remainder in
              // binary array
              binaryBackwards[i] = num % 2;
              num = num / 2;
              i++;
          }


          /*fixing binary order*/
          int count2 = 0;
          for (int j = i - 1; j >= 0; j--){
              bitArray[count2] = binaryBackwards[j];
              count2++;
            }

}

/*
Parameters:
Returns: void
1.	Calls readHeader()
2.	Allocates the memory for the pixels of the encoded ppm image.
3.	Uses readPixel() 
4.	Grabs the last digit of the red, green, and blue numbers,
    saves them as integers
5.	Sends each number it's grabbed to the queue function.
6.	Continues this process for all pixels in the image.
*/
void decodeMsg(FILE* in){
    // 1.	Calls readHeader()
    header_t h = readHeader(in);
    
    // printf("h.height: %d\nh.magicNum: %s\n",h.height,h.magicNum);
    pixel_t** image = readPixels(in, h);
    int digitCounter = 0;
    int digitsArray[1024];
    int nRed=0;
    int nBlue=0;
    int nGreen=0;
    for (int i=0; i<h.width; i++) {
        for (int j=0; j<h.height; j++) {
            if(image[i][j].r < 10){
                nRed = image[i][j].r;
            } else if(image[i][j].r < 100){
                nRed = image[i][j].r%10;
            } else {
                nRed = image[i][j].r%100;
            }
            if(image[i][j].b < 10){
                nBlue = image[i][j].b;
            } else if(image[i][j].b < 100){
                nBlue = image[i][j].b%10;
            } else {
                nBlue = image[i][j].b%100;
            }
            if(image[i][j].g < 10){
                nGreen = image[i][j].g;
            } else if(image[i][j].g < 100){
                nGreen = image[i][j].g%10;
            } else {
                nGreen = image[i][j].g%100;
            }
            // printf("print: %hhu %hhu %hhu\n", image[i][j].r, image[i][j].g, image[i][j].b);
            // queue(digit, arr, address);
            // printf("image[i][j].r: %d",image[i][j].r);
            queue(nRed, digitsArray, &digitCounter);
            queue(nBlue, digitsArray, &digitCounter);
            queue(nGreen, digitsArray, &digitCounter);
        }
    }
};
