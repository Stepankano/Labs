#include <stdio.h>
#include "../data.h"
#include "tree_output.h"

void text_out(cell *tmp)
{
    if (tmp->type == 1)
        printf("%d", tmp->val.value);
    else
        printf("%c", tmp->val.oper);
    if (tmp->left)
    {
        text_out(tmp->left);
    }
    
    if (tmp->right)
    {
        text_out(tmp->right);
    }
    return;
}

void tree_out(cell *tmp, int space)
{
    int i = space;
    if (tmp->right)
    {
        tree_out(tmp->right, space + 1);
    }
    printf("%d", i);
    while (i > 0)
    {
        printf("%s", "__");
        i -= 1;
    }
    if (tmp->type == 1)
        printf("%d\n", tmp->val.value);
    else
        printf("%c\n", tmp->val.oper);
    i -= 1;
    if (tmp->left)
    {
        tree_out(tmp->left, space + 1);
    }
}

