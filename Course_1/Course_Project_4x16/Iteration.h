
#ifndef ITER_H
#define ITER_H

#include <stdio.h>
#include <math.h>

#define eps 0.000001

double my_abs1(double x)
{
    return (x >= 0) ? x : -x;
}
/*
double func(double x){
 return (3 * sin( sqrt(x)) + 0.35 * x - 3.8);
}
*/
double iteration(double func(), double a, double b)
{
    double x = (a + b) / 2;
    while (my_abs1(func(x)) > eps)
    {
        x = x - func(x);
        printf("%.6f\n", x);
    }
    return x;
}

#endif