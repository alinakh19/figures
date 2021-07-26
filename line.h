#ifndef LINE_H
#define LINE_H
 
#include <stdint.h>
#include <math.h>
#define A 50
#define B 50
static uint32_t gridchart[A+1][B+1];
static uint32_t max_x, min_x, max_y, min_y;
// static uint32_t apex_1, apex_2, apex_3;

// this function draw line in array
void reset_buf();

void set_point();

void put_buf();

void get_points();

void plot_line();

uint32_t max_3num();

uint32_t min_3num();

#endif