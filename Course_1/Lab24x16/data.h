#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <stdlib.h>
#define cell struct cell
#define invent union invent
#define bool enum bool

bool{
    true = 1,
    false = 0};

typedef cell
{
    cell *parent;
    cell *left;
    cell *right;

    bool type; //bool type; //1-int, 0-char

    invent
    {
        int value;
        char oper;
    }
    val;


    //int value; //0 when type == char
    //char operat; // ' ' when type == int
}
this_cell;

#endif