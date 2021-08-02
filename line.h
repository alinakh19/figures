#ifndef LINE_H
#define LINE_H
 
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include "types.h"
#define A 255
#define B 255
#define RGBA(r, g, b, a) ((r) | ((g) << 8) | ((b) << 16) | ((a) << 24))
static uint32_t gridchart[A+1][B+1];
// static uint32_t apex_1, apex_2, apex_3;

// this function draw line in array
void reset_buf();

void set_point(Point point, Color val);

void put_buf();

void put_buf_pixel();

// void get_points(Point * point);

void plot_line(Point point_1, Point point_2, Color color);

Point get_random_point();

uint8_t get_line_intersection(Point point_1, Point point_2, Point point_3, Point point_4, Point * point_collision);

#endif