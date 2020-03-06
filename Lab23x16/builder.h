#ifndef BUILDER_H
#define BUILDER_H

#include <stdio.h>
#include <malloc.h>
#include "structures.h"

#define cell struct tree_cell



void ret_add(cell *adder)
{
    while ((*adder).parent != NULL)
    {
        adder = (*adder).parent;
    }
};

void add_cell(int new_value, cell *adder)
{

    if ((*adder).value > new_value)
    {
        (*adder).left = (cell *)malloc(sizeof(cell));
        (*(*adder).left).value = new_value;
        (*(*adder).left).left = NULL;
        (*(*adder).left).right = NULL;
        (*(*adder).left).parent = adder;
    }
    else
    {
        (*adder).right = (cell *)malloc(sizeof(cell));
        (*(*adder).right).value = new_value;
        (*(*adder).right).left = NULL;
        (*(*adder).right).right = NULL;
        (*(*adder).right).parent = adder;
    }

    ret_add(adder);
}

void pathfinder(int new_value, cell *adder)
{

    if ((*adder).value > new_value)
    {

        if ((*adder).left == NULL)
        {
            add_cell(new_value, adder);
        }
        else
        {

            pathfinder(new_value, (*adder).left);
        }
    }

    else
    {

        if ((*adder).right == NULL)
        {
            add_cell(new_value, adder);
        }
        else
        {

            pathfinder(new_value, (*adder).right);
        }
    }
}

cell builder(int root_value)
{
    cell root = {NULL, NULL, NULL, root_value};
    return root;
}
#endif