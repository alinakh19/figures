#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include "rectangle.h"
// static const uint32_t A = 100;
// static const uint32_t B = 100;
void reset_buf(void);
void get_points(uint32_t * x, uint32_t * y);
void set_point(uint32_t x, uint32_t y, uint32_t val);
void put_buf();
void plot_line();
void get_rand(uint32_t *x1, uint32_t *y1, uint32_t *x2, uint32_t *y2, uint32_t *x3, uint32_t *y3);
// void func(int* a, int* b);

int main()
{
  uint32_t get_x1, get_y1, get_x2, get_y2, get_x3, get_y3;
  // get_points(&get_x1, &get_y1);
  // get_points(&get_x2, &get_y2);
  get_rand(&get_x1, &get_y1, &get_x2, &get_y2, &get_x3, &get_y3);
  // get_x1 =1;
  // get_y1 = 50;
  // get_x2 = 45;
  // get_y2 = 3;
  reset_buf();
  // reset_buf();
  // set_point(get_x1,get_y1,1);
  // set_point(get_x2,get_y2,1);
  plot_line(get_x1, get_y1, get_x2, get_y2);
  plot_line(get_x1, get_y1, get_x3, get_y3);
  plot_line(get_x2, get_y2, get_x3, get_y3);
  put_buf();
  printf("%u %u\n", get_x1, get_y1);
  printf("%u %u\n", get_x2, get_y2);
  printf("%u %u\n", get_x3, get_y3);

  // int out_a, out_b;
  // func(&out_a, &out_b);
  // printf("%d %d\n", out_a, out_b);

  // rectangle();
    return 0;
}

void get_rand(uint32_t *x1, uint32_t *y1, uint32_t *x2, uint32_t *y2, uint32_t *x3, uint32_t *y3)
{
  const uint32_t num = 50;
  // for(int32_t i = 0; i<3; i++)
  { 
    srand(time(0));
    *x1 = rand() % num;
    *y1 = rand() % num;
    *x2 = rand() % num;
    *y2 = rand() % num;
    *x3 = rand() % num;
    *y3 = rand() % num;
  }
}

// void func(int* a, int* b)
// {
//   *a = 54;
//   *b = 38;
// }
