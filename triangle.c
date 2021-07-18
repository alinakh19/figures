#include "triangle.h"

static void inner();

static void inner()
{

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