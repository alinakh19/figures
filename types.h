#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
typedef struct
{
    float x;
    float y;
}Point;

typedef struct
{
    Point point_1;
    Point point_2;
} Line;


typedef struct
{
    Point point_1;
    Point point_2;
    Point point_3;
}Triangle;

typedef enum
{
    COLOR_RED = 0,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_BLACK,
    COLOR_WHITE,
    COLOR_PURPLE
}Color;

#endif