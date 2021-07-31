#include "triangle.h"
#include <math.h>
#include <stdint.h>
#include "line.h"
static int det(Point a, Point b);
static int max(int a, int b);
static int min(int a, int b);
static void inner();

static void inner()
{

}

// void fill_triangle(Point point_1, Point point_2, Point point_3)
// {  
//     int32_t tx, ty, counter;
//     float d1, d2, d3, vx, vy;
//     //get length of all sides
//     d1 = sqrt(  pow(point_2.y-point_1.y, 2) +   pow(point_2.x-point_1.x, 2) );
//     d2 = sqrt(  pow(point_3.y-point_2.y, 2) +   pow(point_3.x-point_2.x, 2) );
//     d3 = sqrt(  pow(point_1.y-point_3.y, 2) +   pow(point_1.x-point_3.x, 2) );
//     if(((d1<d2)||(d1 == d2))&&((d1<d2)||(d1 == d2))) //the first side is the shortest
//     { 
//         tx = point_1.x;
//         ty = point_1.y;
//         vx = ( (int32_t)((int32_t)point_2.x-(int32_t)point_1.x) )/d1;
//         vy = ( (int32_t)((int32_t)point_2.y-(int32_t)point_1.y) )/d1;
//         counter = 0;
//         while(counter<d1)
//         {  
//             Point point_tmp;
//             point_tmp.x = tx;
//             point_tmp.y = ty;
//             plot_line(point_3, point_tmp);
//             //drawing a line from point(point_3.x,point_3.y) to point(tx,ty).
//             tx = tx + vx;
//             ty = ty + vy;
//             counter = counter + 1;
//         }
//     }   
//     else 
//     { 
//         if( ( d2 < d3 ) || ( d2 == d3 ) ) //the second side is the shortest
//         { 
//             tx = point_2.x;
//             ty = point_2.y;
//             vx = (point_3.x-point_2.x)/d2;
//             vy = (point_3.y-point_2.y)/d2;
//             counter = 0;
//             while(counter<d2)
//             { 
//                 Point point_tmp;
//                 point_tmp.x = tx;
//                 point_tmp.y = ty;
//                 plot_line(point_1 , point_tmp);
//                 tx = tx + vx;
//                 ty = ty + vy;
//                 counter = counter + 1;
//             }
//         }
//         else // the third side is shortest
//         {  
//             tx = point_3.x;
//             ty = point_3.y;
//             vx = (point_1.x-point_3.x)/d3;
//             vy = (point_1.y-point_3.y)/d3;
//             counter = 0;
//             while(counter<d3)
//             { 
//                 Point point_tmp;
//                 point_tmp.x = tx;
//                 point_tmp.y = ty;
//                 plot_line(point_2, point_tmp);
//                 tx = tx + vx;
//                 ty = ty + vy;
//                 counter = counter + 1;
//             }
//         }
//     }
// }

Triangle get_random_triangle()
{
  Triangle triangle;
  Point point_1 = get_random_point();
  Point point_2 = get_random_point();
  Point point_3 = get_random_point();
  memcpy(&triangle.point_1.x, &point_1.x, sizeof(point_1.x));
  memcpy(&triangle.point_1.y, &point_1.y, sizeof(point_1.y));
  memcpy(&triangle.point_2.x, &point_2.x, sizeof(point_2.x));
  memcpy(&triangle.point_2.y, &point_2.y, sizeof(point_2.y));
  memcpy(&triangle.point_3.x, &point_3.x, sizeof(point_3.x));
  memcpy(&triangle.point_3.y, &point_3.y, sizeof(point_3.y));
  return triangle;
}

void fill_triangle(Triangle triangle)
{
    Point point;
    for (uint32_t x=0; x<=A; x++)
  {
    for (uint32_t y=0; y<=B; y++)
    {
        point.x=x;
        point.y=y;
        if (is_inner(triangle, point))
        {
            set_point(point, COLOR_RED);
        }
        else
        {

        }
    }
  }
}

uint8_t is_inner(Triangle triangle, Point point)
{
    // __PRETTY_FUNCTION__;
    Point point_of_origin;
    uint8_t cnt = 0;
    memset(&point_of_origin, 0, sizeof(point_of_origin));
    // point_of_origin.x = point.x;
    if (line_intersection((Line){.point_1 = triangle.point_1, .point_2 = triangle.point_2}, (Line){.point_1 = point_of_origin, .point_2 =  point}, NULL) == 1)
    {
        // printf("is_inner (%d, %d) true\n", point.x, point.y);
        cnt++;
    };
    if (line_intersection((Line){.point_1 = triangle.point_1, .point_2 = triangle.point_3}, (Line){.point_1 = point_of_origin, .point_2 =  point}, NULL) == 1)
    {
        // printf("is_inner (%d, %d) true\n", point.x, point.y);
        cnt++;
    };
    if (line_intersection((Line){.point_1 = triangle.point_2, .point_2 = triangle.point_3}, (Line){.point_1 = point_of_origin, .point_2 =  point}, NULL) == 1)
    {
        // printf("is_inner (%d, %d) true\n", point.x, point.y);
        cnt++;
    };
    // printf("%d, %d, %d\n", point.x, point.y, cnt);
    return cnt % 2;
}

static int32_t det(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

static int32_t max(int32_t a, int32_t b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

static int32_t min(int32_t a, int32_t b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// TODO: function only determines if point near the line
uint8_t on_segment(Line line, Point point)
{
    if ( (point.x<=max(line.point_1.x, line.point_2.x)) &&
    (point.x>=min(line.point_1.x, line.point_2.x)) &&
    (point.y<=max(line.point_1.y, line.point_2.y)) &&
    (point.y>=min(line.point_1.y, line.point_2.y)) )
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

uint8_t line_intersection(Line line_1, Line line_2, Point *intersection_point)
{
    Point xdiff = {.x=line_1.point_1.x-line_1.point_2.x, .y=line_2.point_1.x-line_2.point_2.x};
    Point ydiff = {.x=line_1.point_1.y-line_1.point_2.y, .y=line_2.point_1.y-line_2.point_2.y};
    int32_t div=det(xdiff, ydiff);
    if (div == 0)
    {
        return 0;
    }
    Point d = {.x=det(line_1.point_1, line_1.point_2), .y=det(line_2.point_1, line_2.point_2)};
    float x = (float)det(d, xdiff) / div;
    float y = (float)det(d, ydiff) / div;
    // printf("line_intersection d (%d,%d)\n", (int32_t)x, (int32_t)y);
    // printf("line_intersection f (%f,%f)\n", x, y);
    Point tmp = {.x = (int32_t)x, .y = (int32_t)y};

    if ( on_segment(line_1, tmp) && on_segment(line_2, tmp) )
    {
        if (intersection_point != NULL)
        {
            intersection_point->x = tmp.x;
            intersection_point->y = tmp.y;
        }
        return 1;    
    }

    else
    {
        return 0;
    }
}

// struct point
// {
//   double x,y;
// };
// int get_points_of_intersection(double x10,double y10,double r1 ,//координаты центра и радиус
//                         double x20,double y20,double r2 ,
//                         point &first , point &second  ) //возвращаем результаты
// {
//     double x0,y0;//координаты точки пересечения всех линий

//     double d;//расстояние между центрами окружностей
//     double a;//расстояние от r1 до точки пересечения всех линий
//     double h;//расстояние от точки пересеч окружностей до точки пересеч всех линий

//     d=sqrt( pow(abs(x10-x20),2) + pow(abs(y10-y20),2));
//     if(d > r1+r2) return 0; //окружности не пересекаются

//     a= (r1*r1 - r2*r2 + d*d ) / (2*d);
//     h= sqrt( pow(r1,2) - pow(a,2));


//     x0 = x10 + a*( x20 - x10 ) / d;
//     y0 = y10 + a*( y20 - y10 ) / d;

//     first.x= x0 + h*( y20 - y10 ) / d;
//     first.y= y0 - h*( x20 - x10 ) / d;

//     if(a == r1 ) return 1; //окружности соприкасаются

//     second.x= x0 - h*( y20 - y10 ) / d;
//     second.y= y0 + h*( x20 - x10 ) / d;

//     return 2;//окружности пересекаются
// }