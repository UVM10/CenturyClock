/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "config.h"

/* Global variables ----------------------------------------------------------*/
int g_cycle_1s_count, g_clock_second, g_clock_minute, g_clock_hour, g_clock_day, g_clock_month, g_clock_year;
bool g_1s_signal;
const int font_digit[10][8] = FONT_DIGIT_VALUE;

const int *g_p_font_digit = &font_digit[0][0];

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>

#include "cclock.h"
#include "ecall.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  *@brief Main program
  *@param none
  *@retval none
*/
void MAIN_Run(void) 
{
  MAIN_Init();
  MAIN_Loop();
}


/**
  *@brief Start clock with default time
  *@param none
  *@retval none
*/
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


/**
  *@brief Run the clock loop
  *@param none
  *@retval none
*/
void MAIN_Loop(void)
{
  for(;;)
  {
    if(CCLOCK_Wait1sSignal() == true)
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

