/*
 * Запись списка (для окончания ввести вместо индекса -1)
 */

#include <stdio.h>
#include "data.h"


struct cell *enter(struct cell *tmp)
{
    int index;
    float value;
    while (1)
    {
        printf("Enter index and value: ");
        scanf("%d", &index);
        if (index != -1)
        {
            scanf("%f", &value);
            if (!tmp)
            {
                Cret(tmp);
                tmp->last = NULL;
                tmp->next = NULL;
                tmp->index = index;
                tmp->value = value;
            }
            else
            {
                Cret(tmp->next);
                tmp->next->last = tmp;
                tmp->next->next = NULL;
                tmp->next->index = index;
                tmp->next->value = value;
                tmp = tmp->next;
            }
        }
        else
        {
            break;
        }
    }
    while (tmp && tmp->last)
    {
        tmp = tmp->last;
    }
    //float* matrix = conversion(tmp);
    return tmp;
}