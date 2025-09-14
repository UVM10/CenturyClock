/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cclock.h"
#include "config.h"

/* Global variables ----------------------------------------------------------*/
int g_cycle_1s_count, g_clock_second, g_clock_minute, g_clock_hour, g_clock_day, g_clock_month, g_clock_year;
bool g_1s_signal;
const int *g_p_font_digit, FONT_DIGIT[10][8];
  FONT_DIGIT = {
    FONT_DIGIT_0,
    FONT_DIGIT_1,
    FONT_DIGIT_2,
    FONT_DIGIT_3,
    FONT_DIGIT_4,
    FONT_DIGIT_5,
    FONT_DIGIT_6,
    FONT_DIGIT_7,
    FONT_DIGIT_8,
    FONT_DIGIT_9
    };

  g_p_font_digit = &FONT_DIGIT[0][0];

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
void MAIN_Run(void) 
{
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
    if(g_1s_signal)
    {
      CCLOCK_UpdateTime();

      CCLOCK_DisplayClock();
    }
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

