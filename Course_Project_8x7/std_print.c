/*
 * Печать списка, начиная с барьерного элемента
 */
#include "data.h"

void std_print(struct cell *tmp)
{
    if (tmp)
    {
        printf("%s\n", (tmp->value == AARD) ? "AARD" : (tmp->value == IGNI) ? "IGNI" : (tmp->value == QUEN) ? "QUEN" : (tmp->value == YRDEN) ? "YRDEN" : "AXII");
        if (tmp->next)
        {
            struct cell *runner = tmp->next;
            while (runner != tmp)
            {
                printf("%s\n", (runner->value == AARD) ? "AARD" : (runner->value == IGNI) ? "IGNI" : (runner->value == QUEN) ? "QUEN" : (runner->value == YRDEN) ? "YRDEN" : "AXII");
                if (runner->next)
                {
                    runner = runner->next;
                }
                else
                {
                    return;
                }
            }
        }
    }
    else
    {
        printf("List is empty\n");
    }
    return;
}