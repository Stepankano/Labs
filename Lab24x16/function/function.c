
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../data.h"
#include "function.h"

void func_num_16(cell *tmp)
{

    if (tmp->type == 0 && tmp->val.oper == '/' && tmp->right)
    {
        if (tmp->right->type == 1 && tmp->right->val.value == 1)
        {
            if (!tmp->right->right && !tmp->right->left)
            {
                if (tmp->left)
                {
                    cell *del, *del1;
                    del = tmp;
                    del1 = del->right;
                    tmp = tmp->parent;
                    tmp->left->left->parent = tmp;
                    tmp->left = tmp->left->left;
                    free(del);
                    free(del1);
                }
                else
                {

                    tmp = tmp->parent;
                    free(tmp->left->right);
                    free(tmp->left);
                    tmp->left = NULL;
                }
            }
            else if (tmp->right->right && !tmp->right->left && tmp->right->right->type == 0 && tmp->right->right->val.oper == ')')
            {
                if (tmp->left)
                {
                    cell *del, *del1;
                    del = tmp;
                    del1 = del->right->right;
                    tmp = tmp->parent;
                    tmp->left->left->parent = tmp;
                    tmp->left = tmp->left->left;
                    tmp->left->right = del1;
                    free(del);
                    free(del1->parent);
                    del1->parent = tmp->left;
                }
                else
                {
                    /*
                    tmp = tmp->parent;
                    free(tmp->left->right);
                    free(tmp->left);
                    tmp->left = NULL;
                    */

                    tmp = tmp->parent;
                    tmp->left->right->right->parent = tmp;
                    free(tmp->left->right);
                    free(tmp->left);
                    if (tmp->right)
                    {
                        tmp->right->parent = tmp->left;
                        tmp->left->right = tmp->right;
                    }
                    tmp->right = tmp->left;
                    tmp->left = NULL;
                }
            }
        }
    }
    if (tmp->left)
    {
        func_num_16(tmp->left);
    }
    if (tmp->right)
    {
        func_num_16(tmp->right);
    }
    return;
}
