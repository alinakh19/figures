#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "rectangle.h"
#include "line.h"
// static const uint32_t A = 100;
// static const uint32_t B = 100;
void reset_buf(void);
void get_points(uint32_t * x, uint32_t * y);
void set_point(uint32_t x, uint32_t y, uint32_t val);
void put_buf();
void plot_line();
void fill_triangle(uint32_t x1,uint32_t y1,uint32_t x2,uint32_t y2,uint32_t x3,uint32_t y3);
// void get_rand(uint32_t *x1, uint32_t *y1, uint32_t *x2, uint32_t *y2, uint32_t *x3, uint32_t *y3);
void get_rand(uint32_t *x1, uint32_t *y1);
// void func(int* a, int* b);
void paint_over(void);

int main()
{
  uint32_t get_x1, get_y1, get_x2, get_y2, get_x3, get_y3;
  // get_points(&get_x1, &get_y1);
  // get_points(&get_x2, &get_y2);
  get_rand(&get_x1, &get_y1);
  apex_1=get_y1;
  get_rand(&get_x2, &get_y2);
  apex_2=get_y2;
  get_rand(&get_x3, &get_y3);
  apex_3=get_y3;
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
  
  // paint_over();
  fill_triangle(get_x1, get_y1, get_x2, get_y2, get_x3, get_y3);
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

void get_rand(uint32_t *x1, uint32_t *y1)
{
  static uint32_t init_flag = 0;
  if (init_flag=0)
  { 
    srand(time(0));
    init_flag=1;
  }
    *x1 = rand() % A;
    *y1 = rand() % B;
    printf("%ld\n", time(0));
}



// void func(int* a, int* b)
// {
//   *a = 54;
//   *b = 38;
// }
