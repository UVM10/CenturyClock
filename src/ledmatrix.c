#include "ledmatrix.h"
#include "ecall.h"
#include "config.h"
#include "main.h"
#include <stdint.h>


/**
    *@brief Display a digit at specified position with specified color
    *@param digit: Digit to display (0-9)
    *@param x: X position
    *@param y: Y position
    *@param color: Color of the digit
    *@retval none
*/
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


/**
    *@brief Display a row of pixels at specified position with specified color
    *@param row: Row data 
    *@param width: Number of pixels in the row
    *@param x: X position
    *@param y: Y position
    *@param color: Color of the pixels
    *@retval none
*/
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


/**
    *@brief Display a pixel at specified position with specified color
    *@param x: X position
    *@param y: Y position
    *@param color: Color of the pixel
    *@retval none
*/
void LEDMATRIX_DisplayPixel(uint32_t x, uint32_t y, int color)
{
    ECALL_100((x << 16) | y, color);
}