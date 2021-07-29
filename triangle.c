#include "triangle.h"
#include <math.h>
#include <stdint.h>
#include "line.h"
static void inner();

static void inner()
{

}

void fill_triangle(Point point_1, Point point_2, Point point_3)
{  
    int32_t tx, ty, counter;
    float d1, d2, d3, vx, vy;
    //get length of all sides
    d1 = sqrt(  pow(point_2.y-point_1.y, 2) +   pow(point_2.x-point_1.x, 2) );
    d2 = sqrt(  pow(point_3.y-point_2.y, 2) +   pow(point_3.x-point_2.x, 2) );
    d3 = sqrt(  pow(point_1.y-point_3.y, 2) +   pow(point_1.x-point_3.x, 2) );
    if(((d1<d2)||(d1 == d2))&&((d1<d2)||(d1 == d2))) //the first side is the shortest
    { 
        tx = point_1.x;
        ty = point_1.y;
        vx = ( (int32_t)((int32_t)point_2.x-(int32_t)point_1.x) )/d1;
        vy = ( (int32_t)((int32_t)point_2.y-(int32_t)point_1.y) )/d1;
        counter = 0;
        while(counter<d1)
        {  
            Point point_tmp;
            point_tmp.x = tx;
            point_tmp.y = ty;
            plot_line(point_3, point_tmp);
            //drawing a line from point(point_3.x,point_3.y) to point(tx,ty).
            tx = tx + vx;
            ty = ty + vy;
            counter = counter + 1;
        }
    }   
    else 
    { 
        if( ( d2 < d3 ) || ( d2 == d3 ) ) //the second side is the shortest
        { 
            tx = point_2.x;
            ty = point_2.y;
            vx = (point_3.x-point_2.x)/d2;
            vy = (point_3.y-point_2.y)/d2;
            counter = 0;
            while(counter<d2)
            { 
                Point point_tmp;
                point_tmp.x = tx;
                point_tmp.y = ty;
                plot_line(point_1 , point_tmp);
                tx = tx + vx;
                ty = ty + vy;
                counter = counter + 1;
            }
        }
        else // the third side is shortest
        {  
            tx = point_3.x;
            ty = point_3.y;
            vx = (point_1.x-point_3.x)/d3;
            vy = (point_1.y-point_3.y)/d3;
            counter = 0;
            while(counter<d3)
            { 
                Point point_tmp;
                point_tmp.x = tx;
                point_tmp.y = ty;
                plot_line(point_2, point_tmp);
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