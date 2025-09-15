#ifndef CCLOCK_H
#define CCLOCK_H

#include <stdbool.h>

void CCLOCK_UpdateTime();
bool CCLOCK_Wait1sSignal();
void CCLOCK_DisplayClock();

#endif