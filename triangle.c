#include "triangle.h"
#include <math.h>
#include <stdint.h>
#include "line.h"
static void inner();

static void inner()
{

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