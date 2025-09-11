#include <stdio.h>
#include <stdint.h>
#include "config.h"
#include "main.h"
#include "ledmatrix.h"
#include "display.h"

void DISPLAY_DisplayNumber(int number, uint32_t position_x, uint32_t position_y, uint32_t display_width, uint32_t color)
{
    uint32_t x, y;
    int digit;

    x = position_x + (FONT_WIDTH + 1) * (display_width - 1);
    y = position_y;

    while(display_width != 0)
    {
        digit = number % 10;
        number /= 10;

        LEDMATRIX_DisplayDigit(digit, x, y, color);

        x -= FONT_WIDTH + 1;
        display_width--;
    }
}

void DISPLAY_DisplaySecond()
{
    DISPLAY_DisplayNumber(g_clock_second, POS_SS_X, POS_SS_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

void DISPLAY_DisplayMinute()
{
    DISPLAY_DisplayNumber(g_clock_minute, POS_MI_X, POS_MI_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

void DISPLAY_DisplayHour()
{
    DISPLAY_DisplayNumber(g_clock_hour, POS_HH_X, POS_HH_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

void DISPLAY_DisplayDay()
{
    DISPLAY_DisplayNumber(g_clock_day, POS_DD_X, POS_DD_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

void DISPLAY_DisplayMonth()
{
    DISPLAY_DisplayNumber(g_clock_month, POS_MO_X, POS_MO_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

void DISPLAY_DisplayYear()
{
    DISPLAY_DisplayNumber(g_clock_year, POS_YY_X, POS_YY_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}