/*
 * Определение размера списка
 */
#include "data.h"

int std_size(struct cell *tmp)
{
    int size = 0;
    if (tmp)
    {
        size += 1;

        if (tmp && tmp->next)
        {
            struct cell *runner = tmp->next;

            while (runner != tmp)
            {
                size += 1;
                if (runner->next)
                {
                    runner = runner->next;
                }
                else
                {
                    break;
                }
            }
        }
        return size;
    }
    return 0;
}