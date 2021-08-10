#ifndef LINE_H
#define LINE_H
 
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include "types.h"
#define A 2000
#define B 2000
static uint32_t gridchart[A+1][B+1];


// this function draw line in array
void reset_buf();

void set_point(Point point, Color val);
void set_point_rgba(Point point, uint32_t val);

void put_buf();

void put_buf_pixel();

void put_buf_pixel_rgba();

// void get_points(Point * point);

void plot_line(Point point_1, Point point_2, Color color);
void plot_line_rgba(Point point_1, Point point_2, uint32_t color);
Point get_random_point();

uint8_t get_line_intersection(Point point_1, Point point_2, Point point_3, Point point_4, Point * point_collision);

#endif