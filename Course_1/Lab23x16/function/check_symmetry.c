
#include <stdio.h>
#include "check_symmetry.h"
#include "../data.h"

int proof(cell *tmp1, cell *tmp2)
{
    if (tmp1->left && tmp2->right && !tmp1->right && !tmp2->left)
    {
        return proof(tmp1->left, tmp2->right);
    }
    if (!tmp1->left && !tmp2->right && tmp1->right && tmp2->left)
    {
        return proof(tmp1->right, tmp2->left);
    }
    if (tmp1->left && tmp2->right && tmp1->right && tmp2->left)
    {
        return (proof(tmp1->right, tmp2->left) && proof(tmp1->left, tmp2->right));
    }
    if (!tmp1->left && !tmp2->right && !tmp1->right && !tmp2->left)
    {
        return 1;
    }
    else return 0;
}