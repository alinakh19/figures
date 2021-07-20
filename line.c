#include "line.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
void reset_buf(void)
{
  memset(gridchart, 0, sizeof(gridchart));
}

void set_point(uint32_t x, uint32_t y, uint32_t val)
{
  gridchart[x][y] = val;
}

void put_buf()
{
  for (uint32_t x=0; x<=A; x++)
  {
    for (uint32_t y=0; y<=B; y++)
    {
      if (gridchart[x][y] == 1)
      {
        printf("o");
      }
      else
      {
        printf(" ");
      }
    }
    printf("|\n");
  }
}

void get_points(uint32_t * x, uint32_t * y)
{
    static uint32_t cnt = 1;
    printf("Enter X coordinate of point %u:\n", cnt);
    scanf("%u", x);
    printf("Enter Y coordinate of point %u:\n", cnt);
    scanf("%u", y);
    cnt++;
    
}

void  plot_line (int x0, int y0, int x1, int y1)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
 
  for (;;){  /* loop */
    gridchart[x0][y0]=1;
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}