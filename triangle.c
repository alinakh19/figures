#include "triangle.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include "line.h"
#include "types.h"
static int det(Point a, Point b);
// static int max(int a, int b);
// static int min(int a, int b);
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
  memcpy(&triangle.point_1, &point_1, sizeof(Point));
  memcpy(&triangle.point_2, &point_2, sizeof(Point));
  memcpy(&triangle.point_3, &point_3, sizeof(Point));
  return triangle;
}

void fill_triangle(Triangle triangle)
{
    Point point;
    Point point_max, point_min;
    point_max.x=max(max(triangle.point_1.x,triangle.point_2.x),triangle.point_3.x);
    point_min.x=min(min(triangle.point_1.x,triangle.point_2.x),triangle.point_3.x);
    point_max.y=max(max(triangle.point_1.y,triangle.point_2.y),triangle.point_3.y);
    point_min.y=min(min(triangle.point_1.y,triangle.point_2.y),triangle.point_3.y);
    // printf("%f %f %f %f %f\n", triangle.point_1.x, triangle.point_2.x, triangle.point_3.x, point_max.x, point_min.x);
    for (uint32_t x=0; x<=A; x++)
    {
        for (uint32_t y=0; y<=B; y++)
        {
            point.x=x;
            point.y=y;
            // printf("%u %u\n", x, y);
            if (is_inner(triangle, point))
            {
                // if ((point.x>point_max.x) && (point.x<point_min.x) || (point.y>point_max.y) && (point.y<point_min.y))
                if ( on_segment( (Line){.point_1 = point_min,.point_2 = point_max}, point) )
                {
                    set_point(point, COLOR_RED);
                }
                else
                {
                    // printf("Error, point is outside the rectangle\n");
                    // is_inner(triangle, point);
                }
            }
            else
            {

            }
        }
    }
}
Triangle get_triangle(Point point_1, Point point_2, Point point_3)
{
    return (Triangle){.point_1 = point_1, .point_2 = point_2,  .point_3 = point_3};
}

void print_triangle(Triangle triangle, const char * name)
{
    printf("-----------\n");
    printf("Print triangle %s\n",   name);
    print_point(triangle.point_1, "point_1");
    print_point(triangle.point_2, "point_2");
    print_point(triangle.point_3, "point_3");
    printf("-----------\n");
}


void print_point(Point point, const char * name)
{
    printf("Point coordinates %s: (%f,%f)\n", name, point.x, point.y);
}

uint8_t is_point_triangle_top(Point point, Triangle triangle)
{
    if ( ((point.x == triangle.point_1.x) && (point.y == triangle.point_1.y)) ||
    ((point.x == triangle.point_2.x) && (point.y == triangle.point_2.y)) ||
    ((point.x == triangle.point_3.x) && (point.y == triangle.point_3.y)) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

uint8_t is_inner(Triangle triangle, Point point)
{
    // uint32_t cnt=0;
    // cnt= cnt + collision_counter(triangle, point);
   
    // Point nan_point = {.x = NAN, .y = NAN};
    // Triangle collision_triangle = get_triangle(nan_point, nan_point, nan_point);
    // uint8_t cnt = 0;
    
    // memset(&point_of_origin, 0, sizeof(point_of_origin));
    // if (line_intersection((Line){.point_1 = triangle.point_1, .point_2 = triangle.point_2}, (Line){.point_1 = point_of_origin, .point_2 =  point}, &collis_point) == 1)
    // {
    //     if (!is_point_triangle_top(collis_point, collision_triangle) && !is_peak(triangle, collis_point))
    //     {
    //         collision_triangle.point_1.x = collis_point.x;
    //         collision_triangle.point_1.y = collis_point.y;
    //         cnt++;
    //     }
    // };
    // if (line_intersection((Line){.point_1 = triangle.point_1, .point_2 = triangle.point_3}, (Line){.point_1 = point_of_origin, .point_2 =  point}, &collis_point) == 1)
    // {
    //     if (!is_point_triangle_top(collis_point, collision_triangle) && !is_peak(triangle, collis_point))
    //     {
    //         collision_triangle.point_2.x = collis_point.x;
    //         collision_triangle.point_2.y = collis_point.y;
    //         cnt++;
    //     }
    // };
    // if (line_intersection((Line){.point_1 = triangle.point_2, .point_2 = triangle.point_3}, (Line){.point_1 = point_of_origin, .point_2 =  point}, &collis_point) == 1)
    // {
    //     if (!is_point_triangle_top(collis_point, collision_triangle) && !is_peak(triangle, collis_point))
    //     {
    //         collision_triangle.point_3.x = collis_point.x;
    //         collision_triangle.point_3.y = collis_point.y;
    //         cnt++;
    //     }
    // };
    // // print_triangle(collision_triangle, "collision_triangle");
    // // printf("%d\n", cnt);

    return collision_counter(triangle, point) % 2;
}

uint8_t collision_counter (Triangle triangle, Point point)
{
    Point point_of_origin[4];
    point_of_origin[0] = (Point){.x = 0, .y = 0};
    point_of_origin[1] = (Point){.x = 0, .y = B};
    point_of_origin[2] = (Point){.x = A, .y = B};
    point_of_origin[3] = (Point){.x = A, .y = 0};
    Point collis_point;
    Line triangle_lines[3];
    triangle_lines[0] = (Line){.point_1 = triangle.point_1, .point_2 = triangle.point_2};
    triangle_lines[1] = (Line){.point_1 = triangle.point_1, .point_2 = triangle.point_3};
    triangle_lines[2] = (Line){.point_1 = triangle.point_2, .point_2 = triangle.point_3};

    uint32_t intersection_counter = 0;
    uint8_t valid = 1;
    for (uint32_t i = 0; i <= 3; i++)
    {
        valid = 1;
        intersection_counter = 0;
        if (i != 0)
        {
            printf("%d \n", i);

        }
        for (uint32_t j=0; j <= 2; j++)
        {         
            if (line_intersection(triangle_lines[j], (Line){.point_1 = point_of_origin[i], .point_2 =  point}, &collis_point) == 1)
            {
                if (!is_point_triangle_top(collis_point, triangle))
                {
                    intersection_counter++;
                }
                else
                {
                    j = 3;
                    intersection_counter = 0;
                    valid = 0;
                }
            }
        }
        if (valid)
        {
            // printf("Counter: %u\n", intersection_counter);
            return intersection_counter;
        }
    }
    
    return intersection_counter;
}

uint8_t is_peak(Triangle triangle, Point point)
{
    if ( ((point.x == triangle.point_1.x) && (point.y == triangle.point_1.y)) ||
    ((point.x == triangle.point_2.x) && (point.y == triangle.point_2.y)) ||
    ((point.x == triangle.point_3.x) && (point.y == triangle.point_3.y)) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static int32_t det(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

// static int32_t max(int32_t a, int32_t b)
// {
//     if (a > b)
//     {
//         return a;
//     }
//     else
//     {
//         return b;
//     }
// }


// static int32_t min(int32_t a, int32_t b)
// {
//     if (a < b)
//     {
//         return a;
//     }
//     else
//     {
//         return b;
//     }
// }

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

// uint8_t line_intersection_determinant(Line line_1, Line line_2, Point *intersection_point)
// {
//     Point xdiff = {.x=line_1.point_1.x-line_1.point_2.x, .y=line_2.point_1.x-line_2.point_2.x};
//     Point ydiff = {.x=line_1.point_1.y-line_1.point_2.y, .y=line_2.point_1.y-line_2.point_2.y};
//     int32_t div=det(xdiff, ydiff);
//     if (div == 0)
//     {
//         return 0;
//     }
//     Point d = {.x=det(line_1.point_1, line_1.point_2), .y=det(line_2.point_1, line_2.point_2)};
//     float x = (float)det(d, xdiff) / div;
//     float y = (float)det(d, ydiff) / div;
//     // printf("line_intersection d (%d,%d)\n", (int32_t)x, (int32_t)y);
//     // printf("line_intersection f (%f,%f)\n", x, y);
//     Point tmp = {.x = (int32_t)x, .y = (int32_t)y};

//     if ( on_segment(line_1, tmp) && on_segment(line_2, tmp) )
//     {
//         if (intersection_point != NULL)
//         {
//             intersection_point->x = tmp.x;
//             intersection_point->y = tmp.y;
//         }
//         return 1;    
//     }

//     else
//     {
//         return 0;
//     }
// }

uint8_t line_intersection(Line line_1, Line line_2, Point *intersection_point)
{
    float k1, k2, b1, b2;
    k1 = (line_1.point_1.y - line_1.point_2.y) / (line_1.point_1.x - line_1.point_2.x);
    b1 = (line_1.point_1.y - k1*line_1.point_1.x);
    k2 = (line_2.point_1.y - line_2.point_2.y) / (line_2.point_1.x - line_2.point_2.x);
    b2 = (line_2.point_1.y - k1*line_2.point_1.x);
    float x = (b2-b1) / (k1-k2);
    float y = k1*x + b1;
    Point tmp = {.x = x, .y = y};

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
