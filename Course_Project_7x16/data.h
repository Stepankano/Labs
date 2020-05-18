#ifndef DATA_H
#define DATA_H
#include <malloc.h>

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


struct cell *enter(struct cell *);
void output(struct cell *);
void function(struct cell *);

#endif