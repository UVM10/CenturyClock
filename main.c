/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Global variables ----------------------------------------------------------*/
int g_cycle_1s_count;
bool g_1s_signal;

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

#include "ecall.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void MAIN_Run(void);

/* Private user code ---------------------------------------------------------*/
void MAIN_Run(void) {
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

