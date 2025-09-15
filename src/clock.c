#include "clock.h"
#include "main.h"
#include "config.h"
#include <stdint.h>



/**
    *@brief Check if it is a leap year
    *@param year: Year to check
    *@retval Leap year signal
*/
bool CLOCK_IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


/**
    *@brief Increase or decrease a clock counter by one
    *@param p_clock_counter: Pointer to the clock counter
    *@param max_value: Maximum value of the clock counter
    *@param b_direction: Increase or Decrease 
    *@retval Overflow signal
*/
bool CLOCK_IncreaseByOne(int *p_clock_counter, int max_value, bool b_direction)
{
    bool b_clock_overflow;
    int clock_counter;

    b_clock_overflow = false;
    clock_counter = *p_clock_counter;

    if(b_direction == DIRECTION_INCREASE)
    {
        if(clock_counter == max_value)
        {
            clock_counter = 0;
            b_clock_overflow = true;
        }
        else clock_counter++;
    }
    else
    {
        if(clock_counter == 0)
        {
            clock_counter = max_value;
            b_clock_overflow = true;
        }
        else clock_counter--;
    }

    *p_clock_counter = clock_counter;

    return b_clock_overflow;
}


/**
    *@brief Increase one second
    *@param none
    *@retval Overflow signal
*/
bool CLOCK_IncreaseOneSecond()
{
    return CLOCK_IncreaseByOne(&g_clock_second, MAX_VALUE_SECOND, DIRECTION_INCREASE);
}


/**
    *@brief Increase one minute
    *@param none
    *@retval Overflow signal
*/
bool CLOCK_IncreaseOneMinute()
{
    return CLOCK_IncreaseByOne(&g_clock_minute, MAX_VALUE_MINUTE, DIRECTION_INCREASE);
}


/**
    *@brief Increase one hour
    *@param none
    *@retval Overflow signal
*/
bool CLOCK_IncreaseOneHour()
{
    return CLOCK_IncreaseByOne(&g_clock_hour, MAX_VALUE_HOUR, DIRECTION_INCREASE);
}


/**
    *@brief Increase one month
    *@param none
    *@retval Overflow signal
*/
bool CLOCK_IncreaseOneMonth()
{
    return CLOCK_IncreaseByOne(&g_clock_month, MAX_VALUE_MONTH, DIRECTION_INCREASE);
}



/**
    *@brief Increase one year
    *@param none
    *@retval Overflow signal
*/
bool CLOCK_IncreaseOneYear()
{
    return CLOCK_IncreaseByOne(&g_clock_year, MAX_VALUE_YEAR, DIRECTION_INCREASE);
}


/**
    *@brief Increase one day
    *@param current_month: Current month
    *@param current_year: Current year
    *@retval Overflow signal
*/
bool CLOCK_IncreaseOneDay(int current_month, int current_year)
{
    int max_value_day;

    if(current_month == 2)
    {
        if(CLOCK_IsLeapYear(current_year) == true) max_value_day = 29;
        else max_value_day = 28;
    }
    else if(current_month == 4 || current_month == 6 || current_month == 9 || current_month == 11) max_value_day = 30;
    else max_value_day = 31;

    return CLOCK_IncreaseByOne(&g_clock_day, max_value_day, DIRECTION_INCREASE);
}