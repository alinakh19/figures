#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "rectangle.h"
#include "line.h"
#include "triangle.h"

int main()
{
  while (1)
  {
    Point point_1 = get_random_point();
    Point point_2 = get_random_point();
    Point point_3 = get_random_point();
    // Point point_1 = {.x = 1, .y = 14};
    // Point point_2 = {.x = 21, .y = 22};
    // Point point_3 = {.x = 30, .y = 16};
    reset_buf();
    fill_triangle(point_1, point_2, point_3);
    set_point(point_1, COLOR_BLUE);
    set_point(point_2, COLOR_GREEN);
    set_point(point_3, COLOR_RED);
    put_buf();
  // // while(1)
  // {
    // point_1 = get_random_point();
    // point_2 = get_random_point();
    // point_3 = get_random_point();
    // reset_buf();
    // fill_triangle(point_1, point_2, point_3);
    // put_buf();
  // }
    printf("%u %u\n", point_1.x, point_1.y);
    printf("%u %u\n", point_2.x, point_2.y);
    printf("%u %u\n", point_3.x, point_3.y);
  }
    return 0;
}



// void centoid_triangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, float * x_c, float * y_c)
// {
//   *x_c = ((float)x1 + (float)x2 + (float)x3) / 3;
//   *y_c = ((float)y1 + (float)y2 + (float)y3) / 3;
// }

// void func(int* a, int* b)
// {
//   *a = 54;
//   *b = 38;
// }
