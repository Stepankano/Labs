/*
 * Вставка нового элемента в конец списка
 */
#include "data.h"

struct cell *std_insert(struct cell *tmp, enum sign new_val)
{
    if (!tmp)
    {
        Cret(tmp, struct cell);
        tmp->value = new_val;
        tmp->next = NULL;
        tmp->prev = NULL;
        return tmp;
    }
    else if (!tmp->next)
    {
        Cret(tmp->next, struct cell);
        tmp->next->next = NULL;
        tmp->next->prev = NULL;
        tmp->next->value = new_val;
        tmp->prev = tmp->next;
        return tmp;
    }
    else
    {
        tmp->prev->next = NULL;
        Cret(tmp->prev->next, struct cell);
        tmp->prev->next->prev = NULL;
        tmp->prev->next->next = NULL;
        tmp->prev->next->value = new_val;
        tmp->prev = tmp->prev->next;
        return tmp;
    }
}