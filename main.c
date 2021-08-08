#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include <math.h>
#include "rectangle.h"
#include "line.h"
#include "triangle.h"

#include "libattopng.h"


void triangle()
{
  Triangle triangle = get_random_triangle();
  reset_buf();
  Point point_of_origin;
  memset(&point_of_origin, 0, sizeof(point_of_origin));
  Point * point_collision;
  fill_triangle(triangle);
  set_point(triangle.point_1, COLOR_BLUE);
  set_point(triangle.point_2, COLOR_GREEN);
  set_point(triangle.point_3, COLOR_PURPLE);
  put_buf_pixel();
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

int main()
{
  
  // while(1)
  {
    // intersection();
    triangle();
  }
  return 0;
}


// void func(int* a, int* b)
// {
//   *a = 54;
//   *b = 38;
// }

