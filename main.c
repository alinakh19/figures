#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "rectangle.h"
#include "line.h"

int main()
{
  Point point_1, point_2, point_3;
  float x_centr, y_centr;
  // get_points(&get_x1, &get_y1);
  // get_points(&get_x2, &get_y2);
  Point point_1 = get_random_point();
  Point point_2 = get_random_point();
  Point point_3 = get_random_point();
  // get_x1 =1;
  // get_y1 = 50;
  // get_x2 = 45;
  // get_y2 = 3;
  reset_buf();
  // reset_buf();
  // set_point(get_x1,get_y1,1);
  // set_point(get_x2,get_y2,1);
  // plot_line(get_x1, get_y1, get_x2, get_y2);
  // plot_line(get_x1, get_y1, get_x3, get_y3);
  // plot_line(get_x2, get_y2, get_x3, get_y3);
  centoid_triangle(get_x1, get_y1, get_x2, get_y2, get_x3, get_y3, &x_centr, &y_centr);
  fill_triangle(get_x1, get_y1, get_x2, get_y2, x_centr, y_centr);
  // fill_triangle(get_x1, get_y1, get_x3, get_y3, x_centr, y_centr);
  // fill_triangle(get_x2, get_y2, get_x3, get_y3, x_centr, y_centr);
  // max_x = max_3num(get_x1, get_x2, get_x3);
  // min_x = min_3num(get_x1, get_x2, get_x3);
  // max_y = max_3num(get_y1, get_y2, get_y3);
  // min_y = min_3num(get_y1, get_y2, get_y3);
  // put_buf(max_x, min_x, max_y, min_y);
  put_buf();
  printf("%u %u\n", get_x1, get_y1);
  printf("%u %u\n", get_x2, get_y2);
  printf("%u %u\n", get_x3, get_y3);
  printf("%f %f\n", x_centr, y_centr);
  // int out_a, out_b;
  // func(&out_a, &out_b);
  // printf("%d %d\n", out_a, out_b);

  // rectangle();
    return 0;
}



void centoid_triangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, float * x_c, float * y_c)
{
  *x_c = ((float)x1 + (float)x2 + (float)x3) / 3;
  *y_c = ((float)y1 + (float)y2 + (float)y3) / 3;
}

// void func(int* a, int* b)
// {
//   *a = 54;
//   *b = 38;
// }
