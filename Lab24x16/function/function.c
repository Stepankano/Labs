#include <stdio.h>
#include <stdlib.h>
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
                    tmp= tmp->parent;
                    tmp->left->left->parent = tmp;
                    tmp->left = tmp->left->left;
                    free(tmp->left->right);
                    free(tmp->left);
                    printf("%s\n","Cl");
                }
                else
                {
                    
                    tmp= tmp->parent;
                    free(tmp->left->right);
                    free(tmp->left);
                    tmp->left = NULL;
                     printf("%s\n","Ct");
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
    printf("%s\n", "All right");
    return;
}