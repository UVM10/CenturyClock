#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

// These global variables should be declared as "extern" to indicate that the instance of variable has already been defined somewhere
// To use these variables, source files need to include "main.h"

void MAIN_Run();
void MAIN_Init();
void MAIN_Loop();

extern int g_cycle_1s_count;
extern bool g_1s_signal;
extern const int *g_p_font_digit;
extern int g_clock_second;
extern int g_clock_minute;
extern int g_clock_hour;
extern int g_clock_day;
extern int g_clock_month;
extern int g_clock_year;

#endif