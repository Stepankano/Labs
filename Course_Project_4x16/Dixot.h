

#ifndef DIXOT_H
#define DIXOT_H

#include<stdio.h>
#include<math.h>

#define eps  0.000001
/*
double func(double x){
 return (3 * sin( sqrt(x) ) + 0.35 * x - 3.8);
}
*/
typedef enum monoton{  // возрастает или убывает
    up,
    down
} monoton;

double my_abs(double x){
    return ( x >= 0 ) ? x : -x;
}

enum monoton check(double(*func)(), double a, double b){
return (func(a) > func(b))? down : up; 
}

void prible(double(*func)(), double* l, double* r){
    if ((func(*l) + func(*r)) / 2 > 0){
        if(check(func, *l,*r) == up){
            *r = (*l + *r) / 2;
        }else {
            *l = (*l + *r) / 2;
        }
     } else{
         if(check(func, *l,*r) == up){
            *l = (*l + *r) / 2;
        }else {
            *r = (*l + *r) / 2;
        }
     }
}

double dixotom(double fanc(), double a, double b){
    double (*func)(double) = fanc;
while( my_abs(a - b) > eps){
    prible(func, &a, &b);
 }
return ((a+b)/2);
}

#endif