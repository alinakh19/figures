#include "line.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

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

void fill_triangle(uint32_t x1,uint32_t y1,uint32_t x2,uint32_t y2,uint32_t x3,uint32_t y3)
{  
    uint32_t tx, ty, counter;
    float d1, d2, d3, vx, vy;
    //get length of all sides
    d1 = sqrt(((y2-y1)^2)+((x2-x1)^2));
    d2 = sqrt(((y3-y2)^2)+((x3-x2)^2));
    d3 = sqrt(((y1-y3)^2)+((x1-x3)^2));
    if(((d1<d2)||(d1=d2))&&((d1<d2)||(d1=d2))) //the first side is the shortest
    { 
        tx = x1;
        ty = y1;
        vx = ( (int32_t)((int32_t)x2-(int32_t)x1) )/d1;
        vy = ( (int32_t)((int32_t)y2-(int32_t)y1) )/d1;
        counter = 0;
        while(counter<d1)
        {  
            plot_line(x3,y3,tx,ty);
            //drawing a line from point(x3,y3) to point(tx,ty).
            tx = tx + vx;
            ty = ty + vy;
            counter = counter + 1;
        }
    }   
    else 
    { 
        if( ( d2<d3 ) || ( d2=d3 ) ) //the second side is the shortest
        { 
            tx = x2;
            ty = y2;
            vx = (x3-x2)/d2;
            vy = (y3-y2)/d2;
            counter = 0;
            while(counter<d2)
            { 
                plot_line(x1,y1,tx,ty);
                tx = tx + vx;
                ty = ty + vy;
                counter = counter + 1;
            }
        }
        else // the third side is shortest
        {  
            tx = x3;
            ty = y3;
            vx = (x1-x3)/d3;
            vy = (y1-y3)/d3;
            counter = 0;
            while(counter<d3)
            { 
                plot_line(x2,y2,tx,ty);
                tx = tx + vx;
                ty = ty + vy;
                counter = counter + 1;
            }
        }
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