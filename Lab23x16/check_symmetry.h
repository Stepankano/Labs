#ifndef CHECK_H
#define CHECK_H
#include <stdio.h>
#include "data.h"

int proof(cell* tmp1, cell* tmp2)
{
    if (tmp1->right && !tmp1->left && tmp2->left && !tmp2->right)
        proof(tmp1->right, tmp2->left);
    else if (tmp1->left && !tmp1->right && tmp2->right && !tmp2->left)
        proof(tmp1->left, tmp2->right);
    else if (tmp1->left && tmp1->right && tmp2->right && tmp2->left)
    {
        proof(tmp1->left, tmp2->right);
        proof(tmp1->right, tmp2->left);
    }
    else if (!tmp1->left && !tmp1->right && !tmp2->right && !tmp2->left)
    {
        //printf("%s\n", "The tree is symetric.");
        return 1;
    }
    else
    {
        //printf("%s\n", "The tree isn't symetric.");
        return 0;
    }
}
#endif