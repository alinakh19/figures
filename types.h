#include <stdint.h>
typedef struct Point
{
    uint32_t x;
    uint32_t y;
} Point;

typedef enum PointVal
{
    POINT_UNSET = 0,
    POINT_SET = 1
} PointVal;
