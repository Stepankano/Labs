#include <stdio.h>
#include "build.h"
#include <malloc.h>
#include "../data.h"
#define Cret(tmp, type)                 \
    tmp = (type *)malloc(sizeof(type)); \
    if (!tmp)                           \
    {                                   \
        printf("%s\n", "Out of meme");  \
        return tmp;                     \
    }

cell *add_int(int value, cell *tmp)
{
    if (!tmp)
    {
        Cret(tmp, cell);
        tmp->parent = NULL;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->type = 1;
        tmp->val.value = value;
        return tmp;
    }
    else
    {
        Cret(tmp->right, cell);
        tmp->right->val.value = value;
        tmp->right->right = NULL;
        tmp->right->left = NULL;
        tmp->right->type = 1;
        tmp->right->parent = tmp;
        return tmp->right;
    }
}

cell *add_char(char sign, cell *tmp)
{
    if (!tmp)
    {
        Cret(tmp, cell);
        tmp->parent = NULL;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->type = 0;
        tmp->val.oper = sign;
        return tmp;
    }
    else
    {

        if ((sign == '*') || (sign == '/') || (sign == '^'))
        {
            Cret(tmp->left, cell);
            tmp->left->val.oper = sign;
            tmp->left->right = NULL;
            tmp->left->left = NULL;
            tmp->left->type = 0;
            tmp->left->parent = tmp;
            return tmp->left;
        }
        else if ((sign == '+') || (sign == '-'))
        {
            while (((tmp->parent) != NULL) && (!(tmp->left) || (tmp->right)) && !(tmp->val.oper == '(' && tmp->type == 0))
            {
                tmp = tmp->parent;
            }
            while ((tmp->right) != NULL)
            {
                tmp = tmp->right;
            }
            Cret(tmp->right, cell);
            tmp->right->val.oper = sign;
            tmp->right->right = NULL;
            tmp->right->left = NULL;
            tmp->right->type = 0;
            tmp->right->parent = tmp;
            return tmp->right;
        }
        
        else
        {
            Cret(tmp->right, cell);
            tmp->right->val.oper = sign;
            tmp->right->right = NULL;
            tmp->right->left = NULL;
            tmp->right->type = 0;
            tmp->right->parent = tmp;
            return tmp->right;
        }
    }
}