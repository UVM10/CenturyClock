#include <stdbool.h>
#include "main.h"
#include "cclock.h"
#include "clock.h"
#include "display.h"
#include "config.h"

void CCLOCK_DisplayClock()
{
    DISPLAY_Hour();
    DISPLAY_Minute();
    DISPLAY_Second();
    DISPLAY_Day();
    DISPLAY_Month();
    DISPLAY_Year();
}

void CCLOCK_UpdateTime()
{
    if(g_1s_signal == true)
    {
        g_1s_signal = false;

        if(CLOCK_IncreaseOneSecond() == false)
        {
            if(CLOCK_IncreaseOneMinute() == false)
            {
                if(CLOCK_IncreaseOneHour() == false)
                {
                    if(CLOCK_IncreaseOneDay(g_clock_month, g_clock_year) == false)
                    {
                        if(CLOCK_IncreaseOneMonth() == false) CLOCK_IncreaseOneYear();
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