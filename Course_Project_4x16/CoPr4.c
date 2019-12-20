#include<stdio.h>
#include "Dixot.h"
#include "Iteration.h"
#include "Newton.h"

int main(){
printf("Iteration = %.6f\n", iteration(2,3));
printf("Dixotomia = %.6f\n", dixotom(2,3));
printf("Newton = %.6f", Newton(2,3));
    return 0;
}