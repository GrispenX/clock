#include <framebuffer.h>
#include <stdio.h>
#include <stdlib.h>

static RGBAcolor_t blendColor(RGBAcolor_t color1, RGBAcolor_t color2);

frameBuffer_t createFrameBuffer(size_t width, size_t height)
{
    frameBuffer_t buffer;
    buffer.buffer = malloc(sizeof(RGBAcolor_t) * width * height);
    buffer.width = width;
    buffer.height = height;
    return buffer;
}

void setPixel(frameBuffer_t* buffer,size_t x, size_t y, RGBAcolor_t color)
{
    if(x >= buffer->width || y >= buffer->height) {return;}
    buffer->buffer[buffer->width * y + x] = color;
}

void fillFrameBuffer(frameBuffer_t* buffer,RGBAcolor_t color)
{
    for(int h = 0; h < buffer->height; h++)
    {
        for(int w = 0; w < buffer->width; w++)
        {
            setPixel(buffer, w, h, color);
        }
    }
}

RGBAcolor_t getPixel(frameBuffer_t* buffer, size_t x, size_t y)
{
    if(x >= buffer->width || y >= buffer->height) {return BLACK;}
    return buffer->buffer[buffer->width * y + x];
}

void printFrameBuffer(frameBuffer_t* buffer)
{
    printf("\033[%dA", buffer->height);
    for (int h = 0; h < buffer->height; h++)
        {
            for(int w = 0; w < buffer->width; w++)
            {
                RGBAcolor_t getColor = getPixel(buffer, w, h);
                printf("\033[38;2;%d;%d;%dm█", getColor.r, getColor.g, getColor.b);
            }
            printf("\n");
        }
}