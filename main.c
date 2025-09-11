/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cclock.h"
#include "config.h"

/* Global variables ----------------------------------------------------------*/
int g_cycle_1s_count, g_clock_second, g_clock_minute, g_clock_hour, g_clock_day, g_clock_month, g_clock_year;
bool g_1s_signal;
const int *g_p_font_digit;

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

#include "ecall.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/
void MAIN_Run(void) {
    /*
    // Clear screen and move cursor to top-left
    printf("\033[2J\033[H");
    
    // Example: changing color
    uint32_t color = 0xFF0000;
    while (1) {
        for (unsigned int k = 2100000000; k > 10; k--) {}
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 8; j++) {
                int x = i * 6;
                int y = j;
                uint32_t position = (x << 16) | (y);
                ECALL_100(position, color);
            }
        }
        color = color + 0x11AA66;
    }*/

    MAIN_Init();
    MAIN_Loop();
}

void MAIN_Init(void)
{
    g_clock_second = DEFAULT_SECOND;
    g_clock_minute = DEFAULT_MINUTE;
    g_clock_hour = DEFAULT_HOUR;
    g_clock_day = DEFAULT_DAY;
    g_clock_month = DEFAULT_MONTH;
    g_clock_year = DEFAULT_YEAR;
    
    g_cycle_1s_count = 0;
    g_1s_signal = false;

    CCLOCK_DisplayClock();
}

void MAIN_Loop(void)
{
    for(;;)
    {
    while(!CCLOCK_Wait1sSignal());

    CCLOCK_UpdateTime();

    CCLOCK_DisplayClock();
    }
    
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void) {
    MAIN_Run();

    return 0;
}

