#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "rectangle.h"
// static const uint32_t A = 100;
// static const uint32_t B = 100;
void reset_buf(void);
void get_points(uint32_t * x, uint32_t * y);
void set_point(uint32_t x, uint32_t y, uint32_t val);
void put_buf();
void plot_line();
int main()
{
  uint32_t get_x1, get_y1, get_x2, get_y2;;
  get_points(&get_x1, &get_y1);
  get_points(&get_x2, &get_y2);
  reset_buf();
  set_point(get_x1,get_y1,1);
  set_point(get_x2,get_y2,1);
  plot_line(get_x1, get_y1, get_x2, get_y2);
  put_buf();
  printf("%u %u\n", get_x1, get_y1);
  printf("%u %u\n", get_x2, get_y2);


  // rectangle();
    return 0;
}

