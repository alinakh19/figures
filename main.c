#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include <math.h>
#include "line.h"
#include "triangle.h"

#include "libattopng.h"

uint32_t random_color(uint8_t alpha)
{
  return RGBA(rand() % 0xff, rand() % 0xff, rand() % 0xff, alpha);
}

void triangle()
{
  Triangle triangle = get_random_triangle();
  reset_buf();
  Point point_of_origin;
  memset(&point_of_origin, 0, sizeof(point_of_origin));
  Point * point_collision;
  // fill_triangle(triangle);
  // drawTriangle(triangle);
  set_point(triangle.point_1, COLOR_BLUE);
  set_point(triangle.point_2, COLOR_GREEN);
  set_point(triangle.point_3, COLOR_PURPLE);
  plot_line (triangle.point_1, triangle.point_2, COLOR_PURPLE);
  plot_line (triangle.point_1, triangle.point_3, COLOR_PURPLE);
  plot_line (triangle.point_3, triangle.point_2, COLOR_PURPLE);
  put_buf_pixel();
  // printf("%u %u\n", triangle.point_1.x, triangle.point_1.y);
  // printf("%u %u\n", triangle.point_2.x, triangle.point_2.y);
  // printf("%u %u\n", triangle.point_3.x, triangle.point_3.y);
}

void triangle_check()
{
  reset_buf();
  Point point_of_origin;
  memset(&point_of_origin, 0, sizeof(point_of_origin));
  Point * point_collision;
  for(int i = 0; i < 1000; i++)
  {
    // fill_triangle(get_random_triangle());
    drawTriangle(get_random_triangle(), random_color(0xff));
  }

  // set_point(triangle.point_1, COLOR_BLUE);
  // set_point(triangle.point_2, COLOR_GREEN);
  // set_point(triangle.point_3, COLOR_PURPLE);
  // plot_line (triangle.point_1, triangle.point_2, COLOR_GREEN);
  // plot_line (triangle.point_1, triangle.point_3, COLOR_GREEN);
  // plot_line (triangle.point_3, triangle.point_2, COLOR_GREEN);
  put_buf_pixel_rgba();
  // printf("%u %u\n", triangle.point_1.x, triangle.point_1.y);
  // printf("%u %u\n", triangle.point_2.x, triangle.point_2.y);
  // printf("%u %u\n", triangle.point_3.x, triangle.point_3.y);
}

void intersection()
{
  Line line1 = {.point_1 = get_random_point(), .point_2 = get_random_point()};
  Line line2 = {.point_1 = get_random_point(), .point_2 = get_random_point()};
  Point int_point;
  if (line_intersection(line1, line2, &int_point))
  {
    reset_buf();
    plot_line (line1.point_1, line1.point_2, COLOR_BLUE);
    plot_line (line2.point_1, line2.point_2, COLOR_RED);
    plot_line ((Point){.x = 0, .y = int_point.y}, (Point){.x = A, .y = int_point.y}, COLOR_GREEN);
    plot_line ((Point){.x = int_point.x, .y = 0}, (Point){.x = int_point.x, .y = B}, COLOR_GREEN);
    put_buf();
  }
}

void test_PNG()
{
  Point point_1, point_2;
  point_1.x = 14;
  point_1.y = 60;
  point_2.x = 0;
  point_2.y = 3;
  reset_buf();
  plot_line (point_1, point_2, COLOR_RED);
  put_buf_pixel();
}

int main()
{
  
  while(1)
  {
    // intersection();
    // triangle();
    triangle_check();
  }
  return 0;
}


// void func(int* a, int* b)
// {
//   *a = 54;
//   *b = 38;
// }

