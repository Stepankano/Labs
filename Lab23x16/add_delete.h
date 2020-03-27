#ifndef ADD_DELETE_H
#define ADD_DELETE_H

#include <stdio.h>
#include "data.h"
#include <malloc.h>
#define less value < (*root).value
#define more value > (*root).value
#define l_ptr (*root).left
#define r_ptr (*root).right

void add_cell(char value, cell *root)
{
    if ((*l_ptr).value == (*root).value)
    {
        l_ptr = NULL;
        r_ptr = NULL;
        (*root).value = value;
        return;
    }
    if (less && l_ptr != NULL)
    {
        add_cell(value, l_ptr);
        return;
    }
    if (more && r_ptr != NULL)
    {
        add_cell(value, r_ptr);
        return;
    }
    if (less && l_ptr == NULL)
    {
        l_ptr = (cell *)malloc(sizeof(cell));
        root = l_ptr;
        l_ptr = root;
        add_cell(value, root);
        return;
    }
    if (more && r_ptr == NULL)
    {
        r_ptr = (cell *)malloc(sizeof(cell));
        root - r_ptr;
        l_ptr = root;
        add_cell(value, root);
        return;
    }
}

void delete_cell(cell *root)
{
}

void adapter(cell *root)
{
    char value;

    printf("%s", "Print a char: ");
    scanf("%c", &value);
    printf("%c", value % 255);
    add_cell(value, root);
    printf("%d", 2);
    printf("%c", (*root).value % 255);
    printf("%d", 3);
    return;
}
#endif