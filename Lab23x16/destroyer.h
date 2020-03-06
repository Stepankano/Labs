#ifndef DESTROYER_H
#define DESTROYER_H
#include "structures.h"
#include <stdio.h>
#include <malloc.h>

cell delete_cell(int del_value, cell *deleter)
{
    if ((*deleter).parent == NULL)
    {
        if ((*deleter).left == NULL && (*deleter).right == NULL)
        {
            (*deleter).left = deleter;
            (*deleter).parent = deleter;
            return *deleter;
        }
        if ((*deleter).left != NULL && (*deleter).right == NULL)
        {
            (*(*deleter).left).parent = NULL;
            cell *tmpdel;
            tmpdel = (*deleter).left;
            free(deleter);
            return *tmpdel;
        }
        if ((*deleter).left == NULL && (*deleter).right != NULL)
        {
            (*(*deleter).parent).parent = NULL;
            cell *tmpdel;
            tmpdel = (*deleter).left;
            free(deleter);
            return *tmpdel;
        }
        if ((*deleter).left != NULL && (*deleter).right != NULL)
        {
            cell *tmp;
            tmp = (*deleter).left;
            while ((*tmp).right != NULL)
            {
                tmp = (*tmp).right;
            }
            (*tmp).right = (*deleter).right;
            (*(*deleter).right).parent = tmp;
            (*(*deleter).left).parent = NULL;
            cell *tmpdel;
            tmpdel = (*deleter).left;
            free(deleter);
            return *tmpdel;
        }
    }
    else
    {
        if ((*(*deleter).parent).value > (*deleter).value)
        {
            if ((*deleter).left != NULL && (*deleter).right != NULL)
            {
                     cell *tmp;
            tmp = (*deleter).left;
            while ((*tmp).right != NULL)
            {
                tmp = (*tmp).right;
            }
            (*tmp).right = (*deleter).right;
            (*(*deleter).right).parent = tmp;
            (*(*deleter).left).parent = (*deleter).parent;
            (*(*deleter).parent).left = (*deleter).left;
            cell *tmpdel;
            tmpdel = (*deleter).left;
            free(deleter);
            return *tmpdel;

            }
            if ((*deleter).left == NULL && (*deleter).right != NULL)
            {
                (*(*deleter).parent).left = (*deleter).right;
                (*(*deleter).right).parent = (*deleter).parent;
                cell *tmpdel;
            tmpdel = (*deleter).left;
                 free(deleter);
                return *tmpdel;
             }
            if ((*deleter).left != NULL && (*deleter).right == NULL)
            {
                (*(*deleter).parent).left = (*deleter).left;
                (*(*deleter).left).parent = (*deleter).parent;
                cell *tmpdel;
            tmpdel = (*deleter).left;
                 free(deleter);
                return *tmpdel;
            }
            if ((*deleter).left == NULL && (*deleter).right == NULL)
            {
                (*(*deleter).parent).left = NULL;
                cell *tmpdel;
            tmpdel = (*deleter).left;
                free(deleter);
                return *tmpdel;
            }
        }
        else
        {
             if ((*deleter).left != NULL && (*deleter).right != NULL)
            {
                     cell *tmp;
            tmp = (*deleter).right;
            while ((*tmp).left != NULL)
            {
                tmp = (*tmp).left;
            }
            (*tmp).left = (*deleter).left;
            (*(*deleter).left).parent = tmp;
            (*(*deleter).right).parent = (*deleter).parent;
            (*(*deleter).parent).right = (*deleter).right;
            cell *tmpdel;
            tmpdel = (*deleter).left;
            free(deleter);
            return *tmpdel;

            }
            if ((*deleter).left == NULL && (*deleter).right != NULL)
            {
                (*(*deleter).parent).right = (*deleter).right;
                (*(*deleter).right).parent = (*deleter).parent;
                cell *tmpdel;
            tmpdel = (*deleter).left;
                 free(deleter);
                return *tmpdel;
             }
            if ((*deleter).left != NULL && (*deleter).right == NULL)
            {
                (*(*deleter).parent).right = (*deleter).left;
                (*(*deleter).left).parent = (*deleter).parent;
                cell *tmpdel;
            tmpdel = (*deleter).left;
                 free(deleter);
                return *tmpdel;
            }
            if ((*deleter).left == NULL && (*deleter).right == NULL)
            {
                (*(*deleter).parent).left = NULL;
                cell *tmpdel;
            tmpdel = (*deleter).left;
                free(deleter);
                return *tmpdel;
            }
        }
    }
}

cell destroyer(int old_value, cell *deleter)
{

    if ((*deleter).value > old_value)
    {

        if ((*deleter).left != NULL)
        {
           return destroyer(old_value, (*deleter).left);
        }
        else
        {
            printf("%s\n", "Error!!!");
        }
    }

    else
    {
        if ((*deleter).value < old_value)
        {
            if ((*deleter).right != NULL)
            {
               return destroyer(old_value, deleter);
            }
            else
            {
                printf("%s\n", "Error!!!");
            }
        }
        else
        {
            return delete_cell(old_value, deleter);
        }
    }
}
#endif