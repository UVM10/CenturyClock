#ifndef LEDMATRIX_H
#define LEDMATRIX_H

void LEDMATRIX_DisplayPixel(uint32_t x, uint32_t y, int color);
void LEDMATRIX_DisplayRow(int row, int width, uint32_t x, uint32_t y, int color);
void LEDMATRIX_DisplayDigit(int digit, uint32_t x, uint32_t y, int color);

#endif