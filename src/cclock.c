#include "cclock.h"

#include "main.h"
#include "config.h"

#include <stdbool.h>

#include "clock.h"
#include "display.h"


/**
    *@brief Display the clock
    *@param none
    *@retval none
*/

void CCLOCK_DisplayClock()
{
    DISPLAY_DisplaySecond();
    DISPLAY_DisplayMinute();
    DISPLAY_DisplayHour();
    
    DISPLAY_DisplayDay();
    DISPLAY_DisplayMonth();
    DISPLAY_DisplayYear();
}


/**
    *@brief Update time
    *@param none
    *@retval none
*/
void CCLOCK_UpdateTime()
{
    if(g_1s_signal == true)
    {
        g_1s_signal = false;

        if(CLOCK_IncreaseOneSecond() == true)
        {
            if(CLOCK_IncreaseOneMinute() == true)
            {
                if(CLOCK_IncreaseOneHour() == true)
                {
                    if(CLOCK_IncreaseOneDay(g_clock_month, g_clock_year) == true)
                    {
                        if(CLOCK_IncreaseOneMonth() == true) CLOCK_IncreaseOneYear();
                    }
                }
            }
        }
    }
}


/**
    *@brief Define 1 second signal
    *@param none
    *@retval Signal for 1 second
*/
bool CCLOCK_Wait1sSignal()
{
    if(g_cycle_1s_count == CYCLE_1S_WAIT)
    {
        g_cycle_1s_count = 0;
        g_1s_signal = true;
    }
    else g_cycle_1s_count++;

    return g_1s_signal;
}