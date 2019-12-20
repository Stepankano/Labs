
#ifndef ITER_H
#define ITER_H

#include<stdio.h>
#include<math.h>

#define eps  0.000001

double my_abs1(double x){
    return ( x >= 0 ) ? x : -x;
}

double pro_func(double x){
 return (3 * log(x) * log(x) + 6 * log(x) - 5);
}

double iteration(double a, double b){
 double x = (a + b) / 2;
 while(pro_func(x) > eps){

     x = x - pro_func(x);

     
 }
 return x;
}


#endif