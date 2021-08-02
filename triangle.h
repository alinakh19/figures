#ifndef TRIANGLE_H
#define TRIANGLE_H
 
#include <stdint.h>
#include <string.h>
#include "types.h"
// this function draw triangle
Triangle get_random_triangle();
void fill_triangle(Triangle triangle);
uint8_t is_inner(Triangle triangle, Point point);
uint8_t on_segment(Line line, Point point);
uint8_t line_intersection(Line line_1, Line line_2, Point *intersection_point);
#endif
