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
  if ((x > 0) && (x < A) && (y > 0) && (y < B))
  {
    gridchart[x][y] = val;
    printf("Draw point with coordinates (%u;%u)\n", x, y);

  }
  else
  {
    printf("Error occuried: wrong coordinates (%u;%u)\n", x, y);

  }
}

// void put_buf(uint32_t max_x, uint32_t min_x, uint32_t max_y, uint32_t min_y)
// {
//   for (uint32_t x=min_x; x<=max_x; x++)
//   {
//     for (uint32_t y=min_y; y<=max_y; y++)
//     {
//       if (gridchart[x][y] == 1)
//       {
//         printf("o");
//       }
//       else
//       {
//         printf(" ");
//       }
//     }
//     printf("|\n");
//   }
// }

void put_buf()
{
  for (uint32_t x=1; x<=A; x++)
  {
    for (uint32_t y=1; y<=B; y++)
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
 
  for (;;)
  {  /* loop */
    set_point(x0, y0, 1);
    // printf("%u %u\n", x0, y0);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

uint32_t max_3num(uint32_t num1, uint32_t num2, uint32_t num3)
{
  if (num1 > num2)
    {
        if (num1 > num3)
        {
          return num1;
        }
        else
        {
          return num3;
        }
    }
    else if (num2 > num3)
      {
        return num2;
      }
    else
    {
      return num3;
    }
}


uint32_t min_3num(uint32_t num1, uint32_t num2, uint32_t num3)
{
  if (num1 < num2)
    {
        if (num1 < num3)
        {
          return num1;
        }
        else
        {
          return num3;
        }
    }
    else if (num2 < num3)
      {
        return num2;
      }
    else
    {
      return num3;
    }
}
// void paint_over(void)
// {
//   uint32_t beg = 0;
//    for (uint32_t x=0; x<=A; x++)
//   {
//     beg = 0;
//     for (uint32_t y=0; y<=B; y++)
//     {
//       if ((gridchart[x][y] == 1)&&(y==apex_1||y==apex_2||y==apex_3))
//       {
//         printf("o");
//       }
//       else
//         { if (gridchart[x][y] == 1)
//         {
//             printf("o");
//             beg++;
//         }
//         else  
//         {
//         if (beg==1)
//         {
//         printf("o");
//         }
//         else 
//         {
//         printf(" ");
//         }
//         }
//         }
//     }
//     printf("|\n");
//   }
// }