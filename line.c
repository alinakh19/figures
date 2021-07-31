#include "line.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


void reset_buf()
{
  memset(gridchart, COLOR_GREEN, sizeof(gridchart));
}

void set_point(Point point, Color val)
{
  if ((point.x >= 0) && (point.x <= A) && (point.y >= 0) && (point.y <= B))
  {
    gridchart[point.x][point.y] = val;
    // printf("Draw point with coordinates (%u;%u)\n", x, y);

  }
  else
  {
    printf("Error occuried: wrong coordinates (%u;%u)\n", point.x, point.y);
  }
}


void put_buf()
{
  for (uint32_t x=0; x<=A; x++)
  {
    for (uint32_t y=0; y<=B; y++)
    {
      switch (gridchart[x][y])
      {
        case COLOR_RED: 
        {
          printf("\033[0;31m");
          printf("o");
          break;
        }
        case COLOR_GREEN:
        {
          printf("\033[0;32m");
          printf("o");
          break;
        }
        case COLOR_BLUE:
        {
          printf("\033[0;34m");
          printf("o");
          break;
        }
        case COLOR_BLACK:
        {
          printf("\033[0;30m");
          printf("o");
          break;
        }
        case COLOR_PURPLE:
        {
          printf("\033[0;35m");
          printf("o");
          break;
        }
        default:
        {
          printf("\033[0;37m");
          printf(" ");
          break;
        }
      }
    }
    printf("|\n");
  }
}


void get_points(Point * point)
{
    static uint32_t cnt = 1;
    printf("Enter X coordinate of point %u:\n", cnt);
    scanf("%u", point->x);
    printf("Enter Y coordinate of point %u:\n", cnt);
    scanf("%u", point->y);
    cnt++;
}

void  plot_line (Point point_1, Point point_2, Color color)
{
  int32_t dx =  abs (point_2.x - point_1.x), sx = point_1.x < point_2.x ? 1 : -1;
  int32_t dy = -abs (point_2.y - point_1.y), sy = point_1.y < point_2.y ? 1 : -1; 
  int32_t err = dx + dy;
  int32_t e2; /* error value e_xy */
 
  for (;;)
  {  /* loop */
    set_point(point_1, color);
    // printf("%u %u\n", x0, y0);
    if (point_1.x == point_2.x && point_1.y == point_2.y) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; point_1.x += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; point_1.y += sy; } /* e_xy+e_y < 0 */
  }
}

Point get_random_point()
{
  static uint32_t init_flag = 0;
  Point point;
  if (init_flag==0)
  { 
    srand(time(0));
    init_flag=1;
  }
  point.x = rand() % A;
  point.y = rand() % B;
  // printf("%ld\n", time(0));
  return point;
}

uint8_t get_line_intersection(Point point_1, Point point_2, Point point_3, Point point_4, Point * point_collision)
{
  float s1_x, s1_y, s2_x, s2_y;
  s1_x = (float)(point_2.x) - (float)(point_1.x);
  s2_x = (float)(point_3.x) - (float)(point_2.x);
  s1_y = (float)(point_2.y) - (float)(point_1.y);
  s2_y = (float)(point_3.y) - (float)(point_2.y);
  float s, t;
  s = (-s1_y * ( (float) (point_1.x) - (float) (point_3.x) ) + s1_x * ( (float) (point_1.y) - (float) (point_3.y) )) / (-s2_x * s1_y + s1_x * s2_y);
  t = ( s2_x * ( (float) (point_1.y) - (float) (point_3.y) ) - s2_y * ( (float) (point_1.x) - (float) (point_3.x) )) / (-s2_x * s1_y + s1_x * s2_y);

  // printf("s = %f, t = %f\n", s, t);
  if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
  {
    // Collision detected
    if (point_collision->x != NULL)
    {
      point_collision->x = point_1.x + (t * s1_x);
    }
    if (point_collision->y != NULL)
    {
      point_collision->y = point_1.y + (t * s1_y);
    }
    return 1;
  }

    return 0; // No collision

}