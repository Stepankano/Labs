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
    FILE *stream;
    stream = fopen(__NAME__, "r");
    if (!stream)
    {
        perror("Не удалось открыть файл");
        return NULL;
    }
    new = (select_type *)malloc(size);
    fread(new, size, 1, stream);
    printf("%s\n", new->fnp_stud.last_name);

    tmp = new;

    while (!feof(stream) && new->next != NULL)
    { //пока ксть файл
        printf("%s\n", new->next->fnp_stud.last_name);
        new->next = (select_type *)malloc(size);
        fread(new->next, size, 1, stream);
        tmp = re_build(*new->next, tmp);
    }

    fclose(stream);
    return tmp;
}