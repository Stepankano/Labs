/*
 * Определение размера списка
 */
#include "data.h"

void std_size(struct cell *tmp)
{
    int size = 0;

    while (tmp)
    {
        size += 1;
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            printf("Size of plan(+ barrier sign): %d\n", size, " sign");
            return;
        }
    }
    printf("List is empty\n");
    return;
}