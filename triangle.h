#ifndef TRIANGLE_H
#define TRIANGLE_H
 
#include <stdint.h>
#include <string.h>
#include "types.h"
// this function draw triangle
Triangle get_random_triangle();
void fill_triangle(Triangle triangle);
Triangle get_triangle(Point point_1, Point point_2, Point point_3);
uint8_t is_point_triangle_top(Point point, Triangle triangle);
uint8_t is_inner(Triangle triangle, Point point);
int8_t collision_counter (Triangle triangle, Line line);
uint8_t is_peak(Triangle triangle, Point point);
uint8_t on_segment(Line line, Point point);
uint8_t line_intersection(Line line_1, Line line_2, Point *intersection_point);
void fillBottomFlatTriangle(Point v1, Point v2, Point v3, uint32_t color);
void fillTopFlatTriangle(Point v1, Point v2, Point v3, uint32_t color);
void drawTriangle(Triangle triangle, uint32_t color);
#endif
