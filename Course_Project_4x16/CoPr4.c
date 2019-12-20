#include<stdio.h>
#include "Dixot.h"

#include "Newton.h"

int main(){
printf("Dixotomia = %.6f\n", dixotom(1,3));
printf("Newton = %.6f", Newton(1,3));
    return 0;
}