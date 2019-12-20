#include<stdio.h>
#include "Dixot.h"
#include "Newton.h"

double my_func(double x){
return (3 * log(x) * log(x) + 6 * log(x) -5);
}

double proizvodnaja(double x){
 return 6 * (log(x) + 1) / x;
}

int main(){
    double (*point)(double) = my_func;
    double (*proizv)(double) = proizvodnaja;

printf("Dixotomia = %.6f\n", dixotom(point, 1, 3));
printf("Newton = %.6f", Newton(point, proizv, 1, 3));
    return 0;
}