

#ifndef NEWTON_H
#define NEWTON_H

#include <stdio.h>
#include <math.h>

#define eps 0.000001
/*
double func1(double x){
 return (3 * sin( sqrt(x) ) + 0.35 * x - 3.8);
}

double pro_func1(double x){
 return ((3.0 * cos( sqrt(x)) / (2 * sqrt(x))) + 0.35);
}
*/

double my_abs2(double x)
{
    return (x >= 0) ? x : -x;
}

double Newton(double func(), double deriv(double (funct)(), double), double a, double b)
{
    double x = (a + b) / 2;
    while (my_abs2(func(x) / deriv(func, x)) > eps)
    {
        x = x - (func(x) / deriv(func, x));
    }
    return x;
}

#endif