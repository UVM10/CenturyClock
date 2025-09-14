#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "ledmatrix.h"
#include "ecall.h"
#include "config.h"
#include "main.h"

void LEDMATRIX_DisplayDigit(int digit, uint32_t x, uint32_t y, int color)
{
    int height;
    const int *p_row;

    height = FONT_HEIGHT;
    p_row = g_p_font_digit - 1 + digit*(FONT_HEIGHT);

    while(height > 0)
    {
        height--;
        p_row++;

        LEDMATRIX_DisplayRow(*p_row, FONT_WIDTH, x, y, color);
        y++;
    }    
}

void LEDMATRIX_DisplayRow(int row, int width, uint32_t x, uint32_t y, int color)
{
    while(width > 0)
    {
        width--;
        if(row & (0x1 << width))
        {
            LEDMATRIX_DisplayPixel(x, y, color);
        }
        else
        {
            LEDMATRIX_DisplayPixel(x, y, COLOR_BACKGROUND);
        }
        x++;
    }
}

void LEDMATRIX_DisplayPixel(uint32_t x, uint32_t y, int color)
{
    ECALL_100((x << 16) | y, color);
}