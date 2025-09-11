#ifndef LEDMATRIX_H
#define LEDMATRIX_H

void LEDMATRIX_DisplayPixel(uint32_t x, uint32_t y, uint32_t color);
void LEDMATRIX_DisplayRow(int row, int width, uint32_t x, uint32_t y, uint32_t color);
void LEDMATRIX_DisplayDigit(uint32_t digit, uint32_t x, uint32_t y, uint32_t color);

#endif