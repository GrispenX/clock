#ifndef HEADER_FILE
#define HEADER_FILE

#define MATRIX_WIDTH   32
#define MATRIX_HEIGHT  8

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGBcolor_t;

typedef struct {
    RGBcolor_t* buffer;
    size_t width;
    size_t height;
} frameBuffer_t;

frameBuffer_t createFrameBuffer(size_t width, size_t height);
void setPixel(frameBuffer_t* buffer,size_t x, size_t y, RGBcolor_t color);
void fillFrameBuffer(frameBuffer_t* buffer,RGBcolor_t color);
void printFrameBuffer(frameBuffer_t* buffer);
RGBcolor_t getPixel(frameBuffer_t* buffer, size_t x, size_t y);

#endif