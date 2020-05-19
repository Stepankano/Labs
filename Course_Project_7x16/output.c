/*
 *  Вывод списка и матрицы
 */

#include <stdio.h>
#include "data.h"

void output(struct cell *tmp)
{
    while (tmp->last)
    {
        tmp = tmp->last;
    }
    printf("\nIndex -> value\n");
    while (tmp)
    {
        printf("%5d -> %5f\n", tmp->index, tmp->value);
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    while (tmp->last)
    {
        tmp = tmp->last;
    }
    float *matrix = conversion(tmp);
    return;
}