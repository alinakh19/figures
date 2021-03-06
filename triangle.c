#include "triangle.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include "line.h"
#include "types.h"

Triangle get_random_triangle()
{
  Triangle triangle;
  Point point_1 = get_random_point();
  Point point_2 = get_random_point();
  Point point_3 = get_random_point();
  triangle.point_1 = point_1;
  triangle.point_2 = point_2;
  triangle.point_3 = point_3;
  return triangle;
}

// Algorithm is working with rectangle area that lies between max and min x and y
void fill_triangle(Triangle triangle)
{
    Point point;
    Point point_max, point_min;
    point_max.x=max(max(triangle.point_1.x,triangle.point_2.x),triangle.point_3.x);
    point_min.x=min(min(triangle.point_1.x,triangle.point_2.x),triangle.point_3.x);
    point_max.y=max(max(triangle.point_1.y,triangle.point_2.y),triangle.point_3.y);
    point_min.y=min(min(triangle.point_1.y,triangle.point_2.y),triangle.point_3.y);
    for (uint32_t x=0; x<=A; x++)
    {
        for (uint32_t y=0; y<=B; y++)
        {
            point.x=x;
            point.y=y;
            if (is_inner(triangle, point))
            {
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

// This function returns 1 if point is within the triangle and 0 otherwise
uint8_t is_inner(Triangle triangle, Point point)
{
    Point point_of_origin[4];
    point_of_origin[0] = (Point){.x = 0, .y = 0};
    point_of_origin[1] = (Point){.x = 0, .y = B};
    point_of_origin[2] = (Point){.x = A, .y = B};
    point_of_origin[3] = (Point){.x = A, .y = 0};

    for (uint32_t i = 0; i <= 3; i++)
    {
        int8_t col_cnt = collision_counter(triangle, (Line){.point_1 = point_of_origin[i], .point_2 =  point});
        if (col_cnt < 0)
        {
            continue;
        }
        else
        {
            return col_cnt % 2;
        }
    }
    return 0;
}

// The function counts intersections between line, conecting origin point and analyzing point, and triangle edge
int8_t collision_counter (Triangle triangle, Line line)
{
    Point collis_point;
    Line triangle_lines[3];
    triangle_lines[0] = (Line){.point_1 = triangle.point_1, .point_2 = triangle.point_2};
    triangle_lines[1] = (Line){.point_1 = triangle.point_1, .point_2 = triangle.point_3};
    triangle_lines[2] = (Line){.point_1 = triangle.point_2, .point_2 = triangle.point_3};

    uint32_t intersection_counter = 0;    
    for (uint32_t edge = 0; edge <= 2; edge++)
    {          
        if (line_intersection(triangle_lines[edge], line, &collis_point) == 1)
        {
            if (!is_point_triangle_top(collis_point, triangle))
            {
                intersection_counter++;
            }
            else
            {
                return -1;
            }
        }
    }
    return intersection_counter;
}

// This function tells if point is one of the triangle peaks
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

// TODO: function only determines if point near the line (in rectangle area)
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

// This function finds intersection point of two segments, returns 0 if there is none
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


// Standart algorithm for filling triangle deviding it to 2 flat triangles; origin triangle has tops v1, v2, v3
void fillBottomFlatTriangle(Point v1, Point v2, Point v3, uint32_t color)
{
  float invslope1 = (v2.x - v1.x) / (v2.y - v1.y);
  float invslope2 = (v3.x - v1.x) / (v3.y - v1.y);

  float curx1 = v1.x;
  float curx2 = v1.x;

  for (int scanlineY = v1.y; scanlineY <= v2.y; scanlineY++)
  {
    plot_line_rgba((Point){.x = (int)curx1, .y = scanlineY}, (Point){.x = (int)curx2, .y = scanlineY}, color);
    curx1 += invslope1;
    curx2 += invslope2;
  }
}

void fillTopFlatTriangle(Point v1, Point v2, Point v3, uint32_t color)
{
  float invslope1 = (v3.x - v1.x) / (v3.y - v1.y);
  float invslope2 = (v3.x - v2.x) / (v3.y - v2.y);

  float curx1 = v3.x;
  float curx2 = v3.x;

  for (int scanlineY = v3.y; scanlineY > v1.y; scanlineY--)
  {
    plot_line_rgba((Point){.x = (int)curx1, .y = scanlineY}, (Point){.x = (int)curx2, .y = scanlineY}, color);
    curx1 -= invslope1;
    curx2 -= invslope2;
  }
}

// sort the three vertices by y-coordinate ascending so a is the topmost vertice
void sort(Point a, Point b, Point c, Point *min, Point *mid, Point *max) 
{
    min->x = a.x;
    min->y = a.y;
    mid->x = b.x;
    mid->y = b.y;
    max->x = c.x;
    max->y = c.y;
    if (min->y > mid->y)
    { 
        mid->x = a.x;
        mid->y = a.y;
        min->x = b.x;
        min->y = b.y;
    }
    if (mid->y > max->y)
    {
        max->x = mid->x;
        max->y = mid->y;
        mid->x = c.x;
        mid->y = c.y;
        if (min->y > mid->y)
        {
            mid->x = min->x;
            mid->y = min->y;
            min->x = c.x;
            min->y = c.y;
        }
    }
}

void drawTriangle(Triangle triangle, uint32_t color)
{
   /* at first sort the three vertices by y-coordinate ascending so v1 is the topmost vertice */
    Point v1, v2, v3;
    v1 = triangle.point_1;
    v2 = triangle.point_2;
    v3 = triangle.point_3;
    Point vt1, vt2, vt3, v4;
    vt1 = v1;
    vt2 = v2;
    vt3 = v3;
    sort(v1, v2, v3, &v1, &v2, &v3);
    sort(vt1, vt2, vt3, &vt1, &vt2, &vt3);

  /* here we know that v1.y <= v2.y <= v3.y */
  /* check for trivial case of bottom-flat triangle */
    if (v2.y == v3.y)
    {
        fillBottomFlatTriangle(v1, v2, v3, color);
    }
  /* check for trivial case of top-flat triangle */
    else if (vt1.y == vt2.y)
    {
        fillTopFlatTriangle(vt1, vt2, vt3, color);
    }
    else
    {
    /* general case - split the triangle in a topflat and bottom-flat one */
        v4 = (Point){.x = (int)(vt1.x + ((float)(vt2.y - vt1.y) / (float)(vt3.y - vt1.y)) * (vt3.x - vt1.x)), .y = vt2.y};
        fillBottomFlatTriangle(vt1, vt2, v4, color);
        fillTopFlatTriangle(vt2, v4, vt3, color);
    }
    // printf("triangle tops: (%f;%f), (%f;%f), (%f;%f)\n", v1.x, v1.y, v2.x, v2.y, v3.x, v3.y);
    // printf("v4: (%f;%f)\n", v4.x, v4.y);

}