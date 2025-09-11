#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>
#include <stdbool.h>

bool CLOCK_IncreaseOneSecond();
bool CLOCK_IncreaseOneMinute();
bool CLOCK_IncreaseOneHour();
bool CLOCK_IncreaseOneMonth();
bool CLOCK_IncreaseOneYear();
bool CLOCK_IncreaseOneDay(int current_month, int current_year);

bool CLOCK_IncreaseByOne(unsigned int *p_clock_counter, unsigned int max_value, bool b_direction);
bool CLOCK_IsLeapYear(int year);

#endif