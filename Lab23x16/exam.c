#include<stdio.h>
#include"data.h"
#include<malloc.h>

int main(){cell fuf;
fuf.left = NULL;
cell huh = {NULL, NULL, 34};
fuf.right = &huh;
if(fuf.left){printf("%d", 5);}
cell *fuhi = &huh;
free(fuhi);
if(fuf.right){printf("%d", 4);}
    return 0;
}