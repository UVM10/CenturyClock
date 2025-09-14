#include <stdbool.h>
#include "main.h"
#include "cclock.h"
#include "clock.h"
#include "display.h"
#include "config.h"

void CCLOCK_DisplayClock()
{
    DISPLAY_DisplaySecond();
    DISPLAY_DisplayMinute();
    DISPLAY_DisplayHour();
    
    DISPLAY_DisplayDay();
    DISPLAY_DisplayMonth();
    DISPLAY_DisplayYear();
}

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