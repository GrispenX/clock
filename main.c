#include <stdio.h>
#include <stdint.h>
#include <framebuffer.h>
#include <minimalistic_font.h>
#include <math.h>

#define SCREEN_WIDTH  32
#define SCREEN_HEIGHT 8


int main()
{
    printf("\n\n\n\n\n\n\n\n");
    frameBuffer_t newBuffer = createFrameBuffer(SCREEN_WIDTH, SCREEN_HEIGHT);
    fillFrameBuffer(&newBuffer, RED);
    // renderString(&newBuffer, "12:34", minimalisticFont, 10, 1, BLUE);
    // printFrameBuffer(&newBuffer);
    frameBuffer_t blackBuffer = createFrameBuffer(5,5);
    fillFrameBuffer(&blackBuffer, RGBA(0,0,0,0));
    blendFrameBuffers(&newBuffer, &blackBuffer, 1, 1);
    printFrameBuffer(&newBuffer);
}