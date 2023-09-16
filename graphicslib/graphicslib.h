#ifndef HEADER_FILE
#define HEADER_FILE

#define MATRIX_WIDTH   32
#define MATRIX_HEIGHT  8

#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
}RGBcolor_t;

void setPixel();
void fillMatrixBuffer();
void printMatrixBuffer();

RGBcolor_t getPixel();

#endif