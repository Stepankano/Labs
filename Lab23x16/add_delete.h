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
    if ((*tmp).value == 287)
    {
        printf("%s", "One mistake and you have made a mistake (wolf) ");
        return;
    }
    else
    {
        printf("%c", (*tmp).value);
        if (old_value > (*tmp).value && (*tmp).right)
        {
            delete ((*tmp).right, old_value);

            return;
        }
        if (old_value < (*tmp).value && (*tmp).left)
        {
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
            if ((*tmp).left && (*tmp).right)
            {
                cell *runner;
                if (tmp->left->right)
                {
                    runner = (*tmp).left;
                    while ((*runner).right)
                    {
                        runner = (*runner).right;
                    }
                    (*tmp).value = (*runner).value;
                    delete (runner, (*runner).value);
                    return;
                }

                if (tmp->right->left)
                {
                    runner = (*tmp).right;
                    while ((*runner).left)
                    {
                        runner = (*runner).left;
                    }
                    (*tmp).value = (*runner).value;
                    delete (runner, (*runner).value);
                    return;
                }
            }
            if ((*tmp).right || (*tmp).left)
            {
                if (tmp->left)
                {
                    tmp->value = tmp->left->value;
                    if (!tmp->left->right && !tmp->left->left)
                    {
                        free(tmp->left);
                        tmp->left = NULL;
                        return;
                    }
                    delete (tmp->left, tmp->left->value);
                    return;
                }
                if (tmp->right)
                {
                    tmp->value = tmp->right->value;
                    if (!tmp->right->right && !tmp->right->left)
                    {
                        free(tmp->right);
                        tmp->right = NULL;
                        return;
                    }
                    delete (tmp->right, tmp->right->value);
                    return;
                }
            }
        }
    }
}
#endif