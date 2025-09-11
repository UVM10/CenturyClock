#include <stdbool.h>
#include "main.h"
#include "cclock.h"
#include "clock.h"
#include "display.h"
#include "config.h"

void CCLOCK_DisplayClock()
{
    DISPLAY_DisplayHour();
    DISPLAY_DisplayMinute();
    DISPLAY_DisplaySecond();
    DISPLAY_DisplayDay();
    DISPLAY_DisplayMonth();
    DISPLAY_DisplayYear();
}

void CCLOCK_UpdateTime()
{
    if(g_1s_signal == true) 
    {
        g_1s_signal = false;
    
        if(CLOCK_IncreaseOneSecond() == true) return;
        else
        {
            if(CLOCK_IncreaseOneMinute() == true) return;
            else
            {
                if(CLOCK_IncreaseOneHour() == true) return;
                else
                {
                    if(CLOCK_IncreaseOneDay(g_clock_month, g_clock_year) == true) return;
                    else
                    {
                        if(CLOCK_IncreaseOneMonth() == true) return;
                        else CLOCK_IncreaseOneYear();
                    }
                }
            }
        }
    }
    else return;
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