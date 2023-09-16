#include <stdio.h>
#include <stdint.h>
#include <graphicslib.h>

#define MATRIX_WIDTH   32
#define MATRIX_HEIGHT  8

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b
}pixel_t;

pixel_t ledMatrix[MATRIX_WIDTH][MATRIX_HEIGHT];

void ledMatrix_print()
{
    for (int h = 0; h < MATRIX_HEIGHT; h++)
    {
        for(int w = 0; w < MATRIX_WIDTH; w++)
        {
            printf("\033[38;2;%d;%d;%dm█", ledMatrix[w][h].r, ledMatrix[w][h].g, ledMatrix[w][h].b);
        }
        printf("\n");
    }
    printf("\033[8A");
}

int main()
{
    RGBcolor_t newcolor={.r=100,.g=200,.b=255};
    fillMatrixBuffer(newcolor);
    for(int i = 0; i < 20; i++)
    {
        printMatrixBuffer();
    }
}