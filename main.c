#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "rectangle.h"
// static const uint32_t A = 100;
// static const uint32_t B = 100;
#define A 50
#define B 50
uint32_t gridchart[A][B];
void reset_buf(void);
void get_points(uint32_t * x, uint32_t * y);
void set_point(uint32_t x, uint32_t y, uint32_t val);
void put_buf();
int main()
{
  uint32_t get_x1, get_y1, get_x2, get_y2;;
  get_points(&get_x1, &get_y1);
  get_points(&get_x2, &get_y2);
  reset_buf();
  set_point(get_x1,get_y1,1);
  set_point(get_x2,get_y2,1);
  put_buf();
  printf("%u %u\n", get_x1, get_y1);
  printf("%u %u\n", get_x2, get_y2);
//    void
// plot_line (int x0, int y0, int x1, int y1)
// {
//   int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
//   int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
//   int err = dx + dy, e2; /* error value e_xy */
 
//   for (;;){  /* loop */
//     setPixel (x0,y0);
//     if (x0 == x1 && y0 == y1) break;
//     e2 = 2 * err;
//     if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
//     if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
//   }
// }

  // rectangle();
    return 0;
}

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
