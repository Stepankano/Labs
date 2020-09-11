#include <stdio.h>
#include "../data.h"
#include "add_delete.h"
#include <malloc.h>

cell *create(int new_value)
{
    cell *new_root = (cell *)malloc(sizeof(cell));
    if (!new_root)
    {
        printf("%s\n", "Out of memory");
    }
    new_root->left = NULL;
    new_root->right = NULL;
    new_root->value = new_value;
    return new_root;
}

cell *destroy(cell *tmp)
{
    free(tmp);
    printf("%s\n", "Tree has been deleted");
    tmp = NULL;
    return tmp;
}

void add(cell *tmp, int new_value)
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
        if ((tmp->right) == NULL)
        {
            printf("%s\n", "Out of memory");
            return;
        }
        (*(*tmp).right).left = NULL;
        (*(*tmp).right).right = NULL;
        (*(*tmp).right).value = new_value;
        return;
    }
    if (new_value < (*tmp).value && !(*tmp).left)
    {
        (*tmp).left = (cell *)malloc(sizeof(cell));
        if ((tmp->left) == NULL)
        {
            printf("%s\n", "Out of memory");
            return;
        }
        (*(*tmp).left).left = NULL;
        (*(*tmp).left).right = NULL;
        (*(*tmp).left).value = new_value;
        return;
    }
}

void delete (cell *tmp, cell *tmp2, int old_value)
{
    if (!tmp)
    {
        printf("%s\n", "Tree empty ");
        return;
    }
    else
    {
        if (old_value > (*tmp).value && (*tmp).right)
        {
            delete ((*tmp).right, tmp, old_value);

            return;
        }
        if (old_value < (*tmp).value && (*tmp).left)
        {
            delete ((*tmp).left, tmp, old_value);

            return;
        }
        if (old_value > (*tmp).value && !(*tmp).right)
        {
            printf("\n%s\n", "One mistake and you have made a mistake (wolf) ");
            return;
        }
        if (old_value < (*tmp).value && !(*tmp).left)
        {
            printf("\n%s\n", "One mistake and you have made a mistake (wolf) ");
            return;
        }
        if (old_value == (*tmp).value)
        {
            if ((*tmp).left && (*tmp).right)
            {
                cell *runner, *runner2;
                if (tmp->left->right)
                {
                    runner = (*tmp).left;
                    while ((*runner).right)
                    {
                        runner2 = runner;
                        runner = (*runner).right;
                    }
                    (*tmp).value = (*runner).value;
                    delete (runner, runner2, (*runner).value);
                    return;
                }

                if (tmp->right->left)
                {
                    runner = (*tmp).right;
                    while ((*runner).left)
                    {
                        runner2 = runner;
                        runner = (*runner).left;
                    }
                    (*tmp).value = (*runner).value;
                    delete (runner, runner2, (*runner).value);
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
                    delete (tmp->left, tmp, tmp->left->value);
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
                    delete (tmp->right, tmp, tmp->right->value);
                    return;
                }
            }
            if (tmp->value > tmp2->value)
            {
                tmp2->right = NULL;
            }
            else
            {
                tmp2->left = NULL;
            }
            free(tmp);
            return;
        }
    }
}