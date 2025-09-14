#ifndef CONSTANT_H
#define CONSTANT_H

#define CYCLE_1S_WAIT 1000000000
#define DIRECTION_INCREASE true
#define DIRECTION_DECREASE false
#define MAX_VALUE_SECOND 59
#define MAX_VALUE_MINUTE 59
#define MAX_VALUE_HOUR 23
#define MAX_VALUE_DAY_28 28
#define MAX_VALUE_DAY_29 29
#define MAX_VALUE_DAY_30 30
#define MAX_VALUE_DAY_31 31
#define MAX_VALUE_MONTH 12
#define MAX_VALUE_YEAR 9999

// Changable default time
#define DEFAULT_SECOND 0
#define DEFAULT_MINUTE 30
#define DEFAULT_HOUR 7
#define DEFAULT_DAY 11
#define DEFAULT_MONTH 5
#define DEFAULT_YEAR 2024

#define COLOR_DEFAULT 0xFFFF00
#define COLOR_BACKGROUND 0x0
#define FONT_WIDTH 5
#define FONT_HEIGHT 8
#define NUMBER_WIDTH_2 2
#define NUMBER_WIDTH_4 4 

#define POS_SS_X 1
#define POS_SS_Y 1
#define POS_MI_X 16
#define POS_MI_Y 1
#define POS_HH_X 31
#define POS_HH_Y 1
#define POS_DD_X 1
#define POS_DD_Y 13
#define POS_MO_X 16
#define POS_MO_Y 13
#define POS_YY_X 31
#define POS_YY_Y 13

#define FONT_DIGIT_VALUE { \
    {14, 17, 19, 21, 25, 17, 17, 14}, \
    {4, 12, 20, 4, 4, 4, 4, 31}, \
    {14, 17, 1, 2, 4, 8, 16, 31}, \
    {14, 17, 1, 6, 1, 1, 17, 14}, \
    {17, 17, 17, 31, 1, 1, 1, 1}, \
    {31, 16, 16, 30, 1, 1, 1, 30}, \
    {15, 16, 16, 31, 17, 17, 17, 14}, \
    {31, 1, 1, 2, 4, 4, 4, 4}, \
    {14, 17, 17, 14, 17, 17, 17, 14}, \
    {14, 17, 17, 31, 1, 1, 17, 14}  \
}

#endif