#ifndef CONSTANT_H
#define CONSTANT_H

#define CYCLE_1S_WAIT 3
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

#define FONT_DIGIT_0 {{0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,1,1}, {1,0,1,0,1}, {1,1,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}}
#define FONT_DIGIT_1 {{0,0,1,0,0}, {0,1,1,0,0}, {1,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}, {1,1,1,1,1}}
#define FONT_DIGIT_2 {{0,1,1,1,0}, {1,0,0,0,1}, {0,0,0,0,1}, {0,0,0,1,0}, {0,0,1,0,0}, {0,1,0,0,0}, {1,0,0,0,0}, {1,1,1,1,1}}
#define FONT_DIGIT_3 {{0,1,1,1,0}, {1,0,0,0,1}, {0,0,0,0,1}, {0,0,1,1,0}, {0,0,0,0,1}, {0,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}}
#define FONT_DIGIT_4 {{1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,1}, {0,0,0,0,1}, {0,0,0,0,1}, {0,0,0,0,1}, {0,0,0,0,1}}
#define FONT_DIGIT_5 {{1,1,1,1,1}, {1,0,0,0,0}, {1,0,0,0,0}, {1,1,1,1,0}, {0,0,0,0,1}, {0,0,0,0,1}, {0,0,0,0,1}, {1,1,1,1,0}}
#define FONT_DIGIT_6 {{0,1,1,1,1}, {1,0,0,0,0}, {1,0,0,0,0}, {1,1,1,1,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}}
#define FONT_DIGIT_7 {{1,1,1,1,1}, {0,0,0,0,1}, {0,0,0,0,1}, {0,0,0,1,0}, {0,1,0,0,0}, {0,1,0,0,0}, {0,1,0,0,0}, {0,1,0,0,0}}
#define FONT_DIGIT_8 {{0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}}
#define FONT_DIGIT_9 {{0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,1}, {0,0,0,0,1}, {0,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}}

#endif