#include <stdio.h>
#include "Dixot.h"
#include "Iteration.h"
#include "Newton.h"

double my_func(double x){
return (3 * sin( sqrt(x) ) + 0.35 * x - 3.8);
}

double proizvodnaja(double x){
 return ((3.0 * cos( sqrt(x)) / (2 * sqrt(x))) + 0.35);
}

int main(){
    double (*point)(double) = my_func;
    double (*proizv)(double) = proizvodnaja;

printf("Iteration = %.6f\n", iteration(point, 2, 3));
printf("Dixotomia = %.6f\n", dixotom(point, 2, 3));
printf("Newton = %.6f", Newton(point, proizv, 2, 3));
    return 0;
}