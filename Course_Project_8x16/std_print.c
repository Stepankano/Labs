/*
 * Печать списка, начиная с барьерного элемента
 */
#include "data.h"

void std_print(struct cell *tmp)
{
    if (tmp)
    {
        printf("Barrier sign: ");
    }
    while (tmp)
    {
        printf("%s\n", (tmp->value == AARD)?"AARD":(tmp->value == IGNI)?"IGNI":(tmp->value == QUEN)?"QUEN":(tmp->value == YRDEN)?"YRDEN":"AXII");
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            return;
        }
    }
    printf("List is empty\n");
    return;
}