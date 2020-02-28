#ifndef WALKER_H
#define WALKER_H
#define tmpL (*tmp_left)
#define tmpR (*tmp_right)
#define std_in int root, cell tmpL, cell tmpR
#define std_out root, tmp_left, tmp_right
#define std_check_in int const_left, int const_right, cell tmpL, cell tmpR
#define std_check_out const_left, const_right, tmp_left, tmp_right
#include "builder.h"

int check(std_check_in)
{
    if (tmpL.value == const_left && tmpR.value == const_right)
    {
        return 1;
    }
    return 0;
}

int walker(std_in)
{
    int const_left;
    int const_right;

    if (tmpL.left != NULL && tmpR.right != NULL)
    {
        tmp_left = tmpL.left;
        tmp_right = tmpR.right;

        const_left = tmpL.value;
        const_right = tmpR.value;
    }
    else
    {
        return (tmpL.left == NULL && tmpR.right == NULL) ? 1 : 0;
    }
    while (tmpL.value != root || tmpR.value != root)
    {
        
        while (tmpL.left != NULL && tmpR.right != NULL)
        {
            tmp_left = tmpL.left;
            tmp_right = tmpR.right;
            
        }

        if (!(tmpL.left == NULL && tmpR.right == NULL))
        {
            return 0;
        }
        while (tmpL.right == NULL && tmpR.left == NULL)
        {
            if (check(std_check_out))
            {
                return 1;
            }
            tmp_left = tmpL.parent;
            tmp_right = tmpR.parent;
            
        }
        if (check(std_check_out))
        {
            return 1;
        }

        if (tmpL.right == NULL || tmpR.left == NULL)
        {
            return 0;
        }
        if (tmpL.right != NULL && tmpR.left != NULL)
        {
            tmp_left = tmpL.right;
            tmp_right = tmpR.left;
        }
        
        while (tmpL.right != NULL && tmpR.left != NULL && tmpL.left == NULL && tmpR.right == NULL)
        {
            tmp_left = tmpL.right;
            tmp_right = tmpR.left;
            
        }

        while (tmpL.left == NULL && tmpR.right == NULL)
        {
            if (check(std_check_out))
            {
                return 1;
            }
            tmp_left = tmpL.parent;
            tmp_right = tmpR.parent;
            
        }

        if (check(std_check_out))
        {
            return 1;
        }
    }
    return 0;
}
#endif