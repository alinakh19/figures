#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
typedef struct
{
    int32_t x;
    int32_t y;
}Point;

typedef enum
{
    COLOR_RED = 0,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_BLACK,
    COLOR_WHITE
}Color;

#endif