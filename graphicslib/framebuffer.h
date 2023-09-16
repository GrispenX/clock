#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdint.h>
#include <stddef.h>

#define RGBA(rv, gv, bv, av) \
    (RGBAcolor_t)            \
    {                        \
        .r = rv,             \
        .g = gv,             \
        .b = bv,             \
        .a = av              \
    }

#define BLACK RGBA(0, 0, 0, 255)
#define WHITE RGBA(255, 255, 255, 255)
#define RED RGBA(255, 0, 0, 255)
#define GREEN RGBA(0, 255, 0, 255)
#define BLUE RGBA(0, 0, 255, 255)

typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} RGBAcolor_t;

typedef struct
{
    RGBAcolor_t *buffer;
    size_t width;
    size_t height;
} frameBuffer_t;

frameBuffer_t createFrameBuffer(size_t width, size_t height);
void setPixel(frameBuffer_t *buffer, size_t x, size_t y, RGBAcolor_t color);
void fillFrameBuffer(frameBuffer_t *buffer, RGBAcolor_t color);
void printFrameBuffer(frameBuffer_t *buffer);
RGBAcolor_t getPixel(frameBuffer_t *buffer, size_t x, size_t y);

#endif