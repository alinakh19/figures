#ifndef LINE_H
#define LINE_H
 
#include <stdint.h>
#define A 50
#define B 50
uint32_t gridchart[A][B];

// this function draw line in array
void reset_buf();

void set_point();

void put_buf();

void get_points();

void plot_line();

#endif