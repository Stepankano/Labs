#ifndef ADD_DELETE_H
#define ADD_DELETE_H

#include <stdio.h>
#include "data.h"
#include <malloc.h>

void add(cell *tmp, int new_value)
{
    if ((*tmp).value == -100)
    {
        (*tmp).value = new_value;
        (*tmp).left = NULL;
        (*tmp).right = NULL;
        return;
    }
    else
    {
        if (new_value > (*tmp).value && (*tmp).right)
        {
            add((*tmp).right, new_value);
            return;
        }
        if (new_value < (*tmp).value && (*tmp).left)
        {
            add((*tmp).left, new_value);
            return;
        }

        if (new_value > (*tmp).value && !(*tmp).right)
        {
            (*tmp).right = (cell *)malloc(sizeof(cell));
            (*(*tmp).right).left = NULL;
            (*(*tmp).right).right = NULL;
            (*(*tmp).right).value = new_value;
            return;
        }
        if (new_value < (*tmp).value && !(*tmp).left)
        {
            (*tmp).left = (cell *)malloc(sizeof(cell));
            (*(*tmp).left).left = NULL;
            (*(*tmp).left).right = NULL;
            (*(*tmp).left).value = new_value;
            return;
        }
    }
}

void delete (cell *tmp, int old_value)
{
    if ((*tmp).value == -100)
    {
        printf("%s", "One mistake and you have made a mistake (wolf) ");
        return;
    }
    else
    {
        printf("%c", (*tmp).value);
        if (old_value > (*tmp).value && (*tmp).right)
        {
            printf("%s", "FR ");
            delete ((*tmp).right, old_value);

            return;
        }
        if (old_value < (*tmp).value && (*tmp).left)
        {
            printf("%s", "FL ");
            delete ((*tmp).left, old_value);

            return;
        }
        if (old_value > (*tmp).value && !(*tmp).right)
        {
            printf("%s", "One mistake and you have made a mistake (wolf) ");
            return;
        }
        if (old_value < (*tmp).value && !(*tmp).left)
        {
            printf("%s", "One mistake and you have made a mistake (wolf) ");
            return;
        }
        if (old_value == (*tmp).value)
        {
            printf("%s", "Find ");
            if ((*tmp).left)
            {
                printf("%s", "L ");
                cell *runner;
                runner = (*tmp).left;
                (*tmp).value = (*runner).value;
                delete (runner, (*runner).value);
                return;
            }
            if ((*tmp).right)
            {
                printf("%s", "R ");
                cell *runner;
                runner = (*tmp).right;
                (*tmp).value = (*runner).value;
                delete (runner, (*runner).value);
                return;
            }
            free(tmp);
            return;
        }
    }
}
#endif