#ifndef BUILDER_H
#define BUILDER_H

#include <stdio.h>
#include <malloc.h>

#define cell struct tree_cell

typedef struct tree_cell
{
    cell *left;
    cell *right;
    cell *parent;
    int value;
} this_cell;

void ret_add(cell *adder)
{
    while ((*adder).parent != NULL)
    {
        adder = (*adder).parent;
    }
    printf(" %s\n", "OK");
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
    printf("%d ", new_value);
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

cell builder()
{
    printf("%s\n","Tree construction started");
    int tree_value;

    scanf("%d", &tree_value);
    cell root = {NULL, NULL, NULL, tree_value};
    printf("%d  %s\n", tree_value, "OK");
    cell *tmp_left = &root;
    cell *tmp_right = &root;
    cell *tmp_adder = &root;
    const cell *pointer_root = &root;

    while (scanf("%d", &tree_value) != EOF)
    {
        pathfinder(tree_value, tmp_adder);
    }
    printf("%s\n", "Tree was built successfully");
    return root;
}
#endif