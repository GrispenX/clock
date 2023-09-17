#include <stdio.h>
#include <stdint.h>
#include <framebuffer.h>
#include <minimalistic_font.h>

#define SCREEN_WIDTH  32
#define SCREEN_HEIGHT 8

int main()
{
    printf("\n\n\n\n\n\n\n\n");
    frameBuffer_t newBuffer = createFrameBuffer(SCREEN_WIDTH, SCREEN_HEIGHT);
    frameBuffer_t newButter = createFrameBuffer(3, 5);
    fillFrameBuffer(&newBuffer, BLACK);
    fillFrameBuffer(&newButter, RED);
    // renderCharacter(&newBuffer, '7', minimalisticFont, 10, 1);
    // blendFrameBuffers(&newBuffer, &newButter, 10, 1);
    renderString(&newBuffer, "22:45", minimalisticFont, 1, 1);
    printFrameBuffer(&newBuffer);
}