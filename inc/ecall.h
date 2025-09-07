#ifndef ECALL_H
#define ECALL_H

#include <stdio.h>
#include <stdint.h>

/*
 * ECALL_100 - Color a terminal character to simulate a pixel
 *
 * Colors a single space at the given terminal coordinates with an RGB color using ANSI escape codes.
 * Saves and restores cursor position. For Linux terminals with true-color support.
 *
 * Parameters:
 *   position (uint32_t): 32-bit coords (upper 16 bits: x-column, 0-based; lower 16 bits: y-row, 0-based).
 *   color (uint32_t): 32-bit RGB (0x00RRGGBB; R: bits 23-16, G: 15-8, B: 7-0).
 *
 * Usage:
 *   ECALL_100((10 << 16) | 5, 0x00FF0000); // Red "pixel" at column 10, row 5
 *
 * Notes:
 *   - Checks for 120x40 terminal bounds. Adjust if needed.
 *   - Use '█' instead of space for visibility: change printf to "\033[%u;%uH\033[48;2;%u;%u;%um█\033[0m".
 *   - Resets to default colors after drawing.
 *   - Requires true-color terminal (e.g., xterm, gnome-terminal).
 */
void ECALL_100(uint32_t position, uint32_t color);

#endif