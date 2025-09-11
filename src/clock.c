#include <stdint.h>
#include "config.h"
#include "main.h"
#include "clock.h"

bool CLOCK_IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0);
}

bool CLOCK_IncreaseByOne(unsigned int *p_clock_counter, unsigned int max_value, bool b_direction)
{
    bool b_clock_overflow;
    int clock_counter;

    b_clock_overflow = false;
    clock_counter = *p_clock_counter;

    if (b_direction == DIRECTION_INCREASE)
    {
        if(clock_counter == max_value)
        {
            b_clock_overflow = false;
            clock_counter = 0;
        }
        else clock_counter++;
    }
    else
    {
        if(clock_counter == 0)
        {
            b_clock_overflow = true;
            clock_counter = max_value;
        }
        else clock_counter--;
    }

    return b_clock_overflow;
}

bool CLOCK_IncreaseOneSecond()
{
    return CLOCK_IncreaseByOne(&g_clock_second, MAX_VALUE_SECOND, DIRECTION_INCREASE);
}

bool CLOCK_IncreaseOneMinute()
{
    return CLOCK_IncreaseByOne(&g_clock_minute, MAX_VALUE_MINUTE, DIRECTION_INCREASE);
}

bool CLOCK_IncreaseOneHour()
{
    return CLOCK_IncreaseByOne(&g_clock_hour, MAX_VALUE_HOUR, DIRECTION_INCREASE);
}

bool CLOCK_IncreaseOneMonth()
{
    return CLOCK_IncreaseByOne(&g_clock_month, MAX_VALUE_MONTH, DIRECTION_INCREASE);
}

bool CLOCK_IncreaseOneYear()
{
    return CLOCK_IncreaseByOne(&g_clock_year, MAX_VALUE_YEAR, DIRECTION_INCREASE);
}

bool CLOCK_IncreaseOneDay(int current_month, int current_year)
{
    bool b_clock_overflow;
    int max_value_day;

    (current_month == 2) ? (max_value_day = (CLOCK_IsLeapYear(current_year) ? MAX_VALUE_DAY_29 : MAX_VALUE_DAY_28)) : ((current_month == 4 || current_month == 6 || current_month == 9 || current_month == 11) ? (max_value_day = MAX_VALUE_DAY_30) : (max_value_day = MAX_VALUE_DAY_31));

    return CLOCK_IncreaseByOne(&g_clock_day, max_value_day, DIRECTION_INCREASE);
}