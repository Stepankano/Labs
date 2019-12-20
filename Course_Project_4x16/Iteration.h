
#ifndef ITER_H
#define ITER_H

#include<stdio.h>
#include<math.h>

#define eps  0.000001

double my_abs1(double x){
    return ( x >= 0 ) ? x : -x;
}

double pro_func(double x){
 return (3 * sin( sqrt(x)) + 0.35 * x - 3.8);
}

double iteration(double a, double b){
 double x = (a + b) / 2;
 while(my_abs1(pro_func(x)) > eps){

     x = x - pro_func(x);

     
 }
 return x;
}


#endif