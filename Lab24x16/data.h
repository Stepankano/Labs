#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <stdlib.h>
#define cell struct cell
#define bool enum bool


bool
{
    true = 1,
    false = 0

};

typedef cell
{
    cell *left;
    cell *right;
    cell *parent;
    bool type; //1-int, 0-char
    int value; 
    char operat;
}
this_cell;

#endif