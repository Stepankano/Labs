#include <stdio.h>
#include "data.h"

void function(struct cell *tmp)
{
    int index;
    float value;
    cell *tmp_sec = NULL;
    while (1)
    {
        printf("Enter index and value: ");
        scanf("%d", &index);
        if (index != -1)
        {
            scanf("%f", &value);
            if (!tmp_sec)
            {
                Cret(tmp_sec);
                tmp_sec->last = NULL;
                tmp_sec->next = NULL;
                tmp_sec->index = index;
                tmp_sec->value = value;
            }
            else
            {
                Cret(tmp_sec->next);
                tmp_sec->next->last = tmp;
                tmp_sec->next->next = NULL;
                tmp_sec->next->index = index;
                tmp_sec->next->value = value;
                tmp_sec = tmp_sec->next;
            }
        }
        else
        {
            break;
        }
    }
    int width = 0;
    int height = 0;
    while (tmp)
    {
        if (tmp->index / 10 > height)
        {
            height = tmp->index / 10;
        }
        if (tmp->index % 10 > width)
        {
            width = tmp->index % 10;
        }
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    float matrix[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            matrix[i][k] = 0;
        }
    }
    while (tmp)
    {
        matrix[tmp->index / 10][tmp->index % 10] = tmp->value;
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
           printf("%5.5f ",matrix[i][k]); 
        }
        printf("\n");
    }
}