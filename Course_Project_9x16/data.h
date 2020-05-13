#ifndef DATA_H
#define DATA_H

typedef struct
{
    float key;
    char string[100];
} row;

int create(row *, int);
void search(row *, int, int);
void sorting(row *, int);

#endif