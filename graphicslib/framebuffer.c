#include <framebuffer.h>
#include <stdio.h>

RGBcolor_t matrixBuffer[MATRIX_WIDTH][MATRIX_HEIGHT];

void setPixel(int width, int height, RGBcolor_t color)
{
    matrixBuffer[width][height] = color;
}
void fillMatrixBuffer(RGBcolor_t color)
{
    for(int h = 0; h < MATRIX_HEIGHT; h++)
    {
        for(int w = 0; w < MATRIX_WIDTH; w++)
        {
            setPixel(w, h, color);
        }
    }
}

RGBcolor_t getPixel(int x, int y)
{
    return matrixBuffer[x][y];
}

void printMatrixBuffer()
{
    //printf("\n");
    for (int h = 0; h < MATRIX_HEIGHT; h++)
        {
            for(int w = 0; w < MATRIX_WIDTH; w++)
            {
                printf("\033[38;2;%d;%d;%dm█", getPixel(w, h).r, getPixel(w, h).g, getPixel(w, h).b);
            }
            printf("\n");
        }
        printf("\033[8A");
}