#include <stdio.h>
#include "../data.h"
#include "re_builder.h"
#include <malloc.h>
#define Cret(tmp, type)                 \
    tmp = (type *)malloc(sizeof(type)); \
    if (!tmp)                           \
    {                                   \
        printf("%s\n", "Out of meme");  \
        return;                         \
    }

select_type *re_build(select_type slct, select_type *tmp)
{
    if (!tmp)
    {
        Cret(tmp, select_type);
        tmp->last = tmp->next = NULL;
        *tmp = slct;
        return tmp;
    }
    if (!tmp->last)
    {
        Cret(tmp->next, select_type);
        tmp->next->next = NULL;
        tmp->next->last = tmp;
        *tmp->next = slct;
        return tmp->next;
    }
}