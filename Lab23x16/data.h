#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#define cell struct cell

typedef cell
{
    cell *left;
    cell *right;
    int value;
}
this_cell;

#endif