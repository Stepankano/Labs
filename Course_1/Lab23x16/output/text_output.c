
#include <stdio.h>
#include "../data.h"
#include "text_output.h"

void text_out(cell *tmp, int space)
{
    if (!tmp)
    {
        printf("%s\n", "Tree is empty");
        return ;
    }
    int i = space;
    if (tmp->right)
    {
        text_out(tmp->right, space + 1);
    }
    printf("%d", i);
    while (i > 0)
    {
        printf("%s", "--");
        i -= 1;
    }
    printf("%c\n", tmp->value);
    i -= 1;
    if (tmp->left)
    {
        text_out(tmp->left, space + 1);
    }
}
