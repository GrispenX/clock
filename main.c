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
    fillFrameBuffer(&newBuffer, BLACK);
    frameBuffer_t patternBuffer = createFrameBuffer(SCREEN_WIDTH, SCREEN_HEIGHT);
    RGBAcolor_t color = RGBA(0, 0, 255, 255);
    for(int y = 0; y < SCREEN_HEIGHT; y++)
    {
        color.g += 30;
        for(int x = 0; x < SCREEN_WIDTH; x++)
        {
            setPixel(&patternBuffer, x, y, color);
        }
    }
    renderStringWithPattern(&newBuffer, "12:34", minimalisticFont, 8, 1, &patternBuffer, 1, 1);
    printFrameBuffer(&newBuffer);
}