#include <stdio.h>
#include <stdint.h>
#include "config.h"
#include "main.h"
#include "ledmatrix.h"
#include "display.h"


/**
    *@brief Display a number at specified position with specified width and color
    *@param number: Number to display
    *@param position_x: X position
    *@param position_y: Y position
    *@param display_width: Width of a number
    *@param color: Color of a number
    *@retval none
*/
void DISPLAY_DisplayNumber(int number, uint32_t position_x, uint32_t position_y, int display_width, int color)
{
    uint32_t x, y;
    int digit;

    x = position_x + (FONT_WIDTH + 1) * (display_width - 1);
    y = position_y;

    while(display_width > 0)
    {
        digit = number % 10;
        number /= 10;

        LEDMATRIX_DisplayDigit(digit, x, y, color);

        x -= (FONT_WIDTH + 1);
        display_width--;
    }
}


/**
    *@brief Display second
    *@param none
    *@retval none
*/
void DISPLAY_DisplaySecond()
{
    DISPLAY_DisplayNumber(g_clock_second, POS_SS_X, POS_SS_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}


/**
    *@brief Display minute
    *@param none
    *@retval none
*/
void DISPLAY_DisplayMinute()
{
    DISPLAY_DisplayNumber(g_clock_minute, POS_MI_X, POS_MI_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}


/**
    *@brief Display hour
    *@param none
    *@retval none
*/
void DISPLAY_DisplayHour()
{
    DISPLAY_DisplayNumber(g_clock_hour, POS_HH_X, POS_HH_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}


/**
    *@brief Display day
    *@param none
    *@retval none
*/
void DISPLAY_DisplayDay()
{
    DISPLAY_DisplayNumber(g_clock_day, POS_DD_X, POS_DD_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}


/**
    *@brief Display month
    *@param none
    *@retval none
*/
void DISPLAY_DisplayMonth()
{
    DISPLAY_DisplayNumber(g_clock_month, POS_MO_X, POS_MO_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}


/**
    *@brief Display year
    *@param none
    *@retval none
*/
void DISPLAY_DisplayYear()
{
    DISPLAY_DisplayNumber(g_clock_year, POS_YY_X, POS_YY_Y, NUMBER_WIDTH_4, COLOR_DEFAULT);
}