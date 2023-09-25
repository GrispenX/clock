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
    fillFrameBuffer(&newBuffer, GREEN);
    frameBuffer_t pattern = createFrameBuffer(3,5);
    fillFrameBuffer(&pattern, BLUE);
    setPixel(&pattern, 1, 3, RED);
    renderCharacterWithPattern(&newBuffer, '1', minimalisticFont, 10, 1, &pattern);
    printFrameBuffer(&newBuffer);
}