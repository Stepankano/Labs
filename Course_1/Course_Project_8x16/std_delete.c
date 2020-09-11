/*
 * Поиск и удаление всех копий заданного элемента из списка
 */
#include "data.h"

struct cell *std_delete(struct cell *tmp, enum sign old_val)
{
    if (!tmp)
    {
        printf("Error. List is empty\n");
        return NULL;
    }
    else if (!tmp->next && tmp->value == old_val)
    {
        free(tmp);
        return NULL;
    }
    else
    {
        if (tmp->value == old_val)
        {
            if (tmp->next != tmp->prev)
            {
                tmp->next->prev = tmp->prev;
            }
            struct cell *copy = tmp->next;
            free(tmp);
            return copy;
        }
        struct cell *runner = tmp;
        while (runner->next)
        {
            if (runner->next->value != old_val)
            {
                runner = runner->next;
            }
            else
            {
                if (tmp->prev == runner->next)
                {
                    tmp->prev = runner;
                }
                struct cell *copy = runner->next;
                runner->next = runner->next->next;
                free(copy);
            }
        }
        return tmp;
    }
}