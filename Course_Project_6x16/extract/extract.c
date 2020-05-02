#include <stdio.h>
#include <stdlib.h>
#include "extract.h"
#include "../data.h"
#include "../re_builder/re_builder.h"
#define prev previous

select_type *extract(select_type *tmp)
{
    select_type *new;
    int size = sizeof(select_type); //размер нужной структуры
    FILE *stream = fopen(__NAME__, "r");
    if (!stream)
    {
        perror("Не удалось открыть файл");
        return NULL;
    }
    while (!feof(stream))
    { //пока ксть файл или элемент не обозначен как последний
        new = (select_type *)malloc(size);
        fread(new, size, 1, stream);
        new->next = new->last = NULL;
        tmp=re_build(*new, tmp);
    }
    fclose(stream);
    return tmp;
}