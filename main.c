#include <stdio.h>
#include <stdint.h>
#include <framebuffer.h>

#define SCREEN_WIDTH  32
#define SCREEN_HEIGHT 8
int main()
{
    frameBuffer_t newBuffer = createFrameBuffer(SCREEN_WIDTH, SCREEN_HEIGHT);
    RGBcolor_t newcolor={.r=0,.g=255,.b=0};
    for(int i = 0; i < 255; i++)
    {
        fillFrameBuffer(&newBuffer, newcolor);
        printFrameBuffer(&newBuffer);
        newcolor.r += 1;
    }
}