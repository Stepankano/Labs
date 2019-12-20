

#ifndef NEWTON_H
#define NEWTON_H

#include<stdio.h>
#include<math.h>

#define eps  0.000001

double func1(double x){
 return (3 * log(x) * log(x) + 6 * log(x) - 5);
}

double pro_func1(double x){
 return 6 * (log(x) + 1) / x;
}
double my_abs2(double x){
    return ( x >= 0 ) ? x : -x;
}

double Newton(double a, double b){
    double x = (a + b) / 2;
    while( my_abs2(func1(x) / pro_func1(x)) > eps){
        x = x - (func1(x) / pro_func1(x));
 }
return x;
}

#endif