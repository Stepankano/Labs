#include <stdio.h>
#include "../data.h"
#include "add.h"
#include <malloc.h>
#define Errur printf("%s\n", "Error");

cell *add_int(cell *tmp, int new_value)
{
    if (!tmp)
    {
        tmp = (cell *)malloc(sizeof(cell));
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->parent = NULL;
        tmp->type = 1;
        tmp->value = new_value;
        tmp->operat = ' ';
        printf("%d\n", tmp->value);
        return tmp;
    }
    if (!(tmp->left))
    {
        tmp->left = (cell *)malloc(sizeof(cell));
        tmp->left->left = NULL;
        tmp->left->right = NULL;
        tmp->left->parent = tmp;
        tmp->type = 1;
        tmp->left->value = new_value;
        tmp->left->operat = ' ';
        printf("%d\n", tmp->left->value);
        return tmp;
    }
    Errur
    return tmp;
};

cell *add_char(cell *tmp, char operate)
{
    if (!tmp)
    {
        if (operate == '(')
        {
            tmp = (cell *)malloc(sizeof(cell));
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->parent = NULL;
            tmp->type = 0;
            tmp->value = 0;
            tmp->operat = operate;
            printf("%c\n", tmp->operat);
            return tmp;
        }
        else{
            Errur 
            return tmp;
        }
    }
    if (!(tmp->right))
    {
        if(tmp->operat == '(' && tmp->left){
        tmp->right = (cell *)malloc(sizeof(cell));
        tmp->right->left = tmp->left;
        tmp->left = NULL;
        tmp->right->right = NULL;
        tmp->right->parent = tmp;
        tmp->right->type = 0;
        tmp->right->value = 0;
        tmp->right->operat = operate;
        printf("%c\n", tmp->operat);
        return tmp->right;
    }
    Errur
    return tmp;
};