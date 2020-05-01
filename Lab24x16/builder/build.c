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
        else if (sign == ')')
        {
            while (tmp->parent && tmp->parent->val.oper != '(')
            {
                tmp = tmp->parent;
            }
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            if (tmp->right)
            {
                cell *high = tmp->right;
                high->parent = NULL;
                Cret(high->parent, cell);
                high->parent->val.oper = ')';
                high->parent->type = 0;
                high->parent->right = high;
                high->parent->left = NULL;
                high->parent->parent = tmp;
                tmp->right = high->parent;
            }
            else
            {
                Cret(tmp->right, cell);
                tmp->right->type = 0;
                tmp->right->val.oper = ')';
                tmp->right->right = tmp->right->left = NULL;
                tmp->right->parent = tmp;
            }
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