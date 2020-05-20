/*
 * Поиск и удаление всех копий заданного элемента из списка
 */
#include "data.h"

struct cell *std_delete(struct cell *tmp, type_name old_val)
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
            if (tmp->next && (tmp->next != tmp->prev))
            {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
            }
            if (tmp->next && (tmp->next == tmp->prev))
            {
                tmp->next->next = NULL;
                tmp->next->prev = NULL;
            }
            struct cell *copy = tmp->next;
            free(tmp);
            if (copy)
            {
                return std_delete(copy, old_val);
            }
            else
            {
                return NULL;
            }
        }
        struct cell *runner = tmp;
        while (runner->next && runner->next != tmp)
        {
            if (runner->next->value != old_val)
            {
                runner = runner->next;
            }
            else
            {

                struct cell *copy = runner->next;
                runner->next = copy->next;
                copy->next->prev = runner;
                free(copy);
            }
        }
        return tmp;
    }
}