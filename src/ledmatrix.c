#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "ledmatrix.h"
#include "ecall.h"
#include "config.h"
#include "main.h"

void LEDMATRIX_DisplayPixel(uint32_t x, uint32_t y, uint32_t color)
{
    ECALL_100((x << 16) | y, color);
}

void LEDMATRIX_DisplayRow(int row, int width, uint32_t x, uint32_t y, uint32_t color)
{
    for(;;)
    {
        width--;
        if(width < 0) break;
        else
        {
            (row & (1 << width)) ? LEDMATRIX_DisplayPixel(x, y, color) : LEDMATRIX_DisplayPixel(x, y, COLOR_BACKGROUND);
            x++;
        }
    }
}

void LEDMATRIX_DisplayDigit(uint32_t digit, uint32_t x, uint32_t y, uint32_t color)
{
    int height; 
    const int *p_row;

    height = FONT_HEIGHT;
    p_row = g_p_font_digit + digit;

    while(height > 0)
    {
        height--;
        p_row += FONT_WIDTH;

        LEDMATRIX_DisplayRow(*p_row, FONT_WIDTH, x, y, color);
    }
}