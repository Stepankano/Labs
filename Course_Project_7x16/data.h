#ifndef DATA_H
#define DATA_H
#include <malloc.h>
#define eps 0.00001

#define Cret(tmp)                       \
    tmp = (cell *)malloc(sizeof(cell)); \
    if (!tmp)                           \
    {                                   \
        printf("Out of memory\n");      \
    }

typedef struct cell
{
    int index;
    struct cell *last;
    struct cell *next;
    float value;
} cell;

cell *enter(cell *);
void output(cell *);
void function(cell *);
float *conversion(cell *);

#endif