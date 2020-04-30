
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../data.h"
#include "function.h"

void func(cell *tmp)
{

    if (tmp->type == 0 && tmp->val.oper == '/' && tmp->right)
    {
        if (tmp->right->type == 1 && tmp->right->val.value == 1)
        {
            if (!tmp->right->right && !tmp->right->left)
            {
                if (tmp->left)
                {
                     cell *del,*del1;
                     del = tmp;
                     del1= del->right;
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
        }
    }
    if (tmp->left)
    {
        func(tmp->left);
    }
    if (tmp->right)
    {
        func(tmp->right);
    }
    return;
}

