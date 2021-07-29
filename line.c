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
  for (uint32_t x=1; x<=A; x++)
  {
    for (uint32_t y=1; y<=B; y++)
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

void  plot_line (Point point_1, Point point_2)
{
  int32_t dx =  abs (point_2.x - point_1.x), sx = point_1.x < point_2.x ? 1 : -1;
  int32_t dy = -abs (point_2.y - point_1.y), sy = point_1.y < point_2.y ? 1 : -1; 
  int32_t err = dx + dy;
  int32_t e2; /* error value e_xy */
 
  for (;;)
  {  /* loop */
    set_point(point_1, COLOR_BLACK);
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
