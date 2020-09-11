#include <stdio.h>
#include "Dixot.h"
#include "Iteration.h"
#include "Newton.h"

double my_func(double x)
{
    return (0.6*pow(3,x)-2.3*x-3);
}

double derivative(double (*f)(), double x)
{
    // return ((3.0 * cos(sqrt(x)) / (2 * sqrt(x))) + 0.35);]
    return (f(x + 0.00001) - f(x)) / 0.00001;
}

int main()
{
    double (*point)(double) = my_func;
    double (*deriv)(double (*f)(), double) = derivative;

    printf("Dixotomia = %.6f\n", dixotom(point, 2, 3));
    printf("Newton = %.6f", Newton(point, deriv, 2, 3));
    
    printf("Iteration = %.6f\n", iteration(point, 2, 3));
    
    return 0;
}