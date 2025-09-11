#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <stdbool.h>

void DISPLAY_DisplaySecond();
void DISPLAY_DisplayMinute();
void DISPLAY_DisplayHour();
void DISPLAY_DisplayDay();
void DISPLAY_DisplayMonth();
void DISPLAY_DisplayYear();

void DISPLAY_DisplayNumber(int number, uint32_t position_x, uint32_t position_y, uint32_t color, uint32_t display_width);

#endif