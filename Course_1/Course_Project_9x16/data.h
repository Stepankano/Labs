#ifndef DATA_H
#define DATA_H
#define eps 0.00001

typedef struct
{
    float key;
    char string[100];
} row;


void search(row *, int, int,float);


#endif