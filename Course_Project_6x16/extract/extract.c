#include <stdio.h>
#include <stdlib.h>
#include "extract.h"
#include "../data.h"
#include "../re_builder/re_builder.h"
#define prev previous

select_type *extract(select_type *tmp)
{
    select_type *new;
    int size = sizeof(select_type);
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
    new->last = NULL;
    tmp = re_build(*new, NULL);

    while (!feof(stream) && new->next)
    { //пока ксть файл
        new->next = (select_type *)malloc(size);
        fread(new->next, size, 1, stream);
        tmp = re_build(*new->next, tmp);
        printf("%s\n", new->next->fnp_stud.last_name);
        new = new->next;
    }
    /*
    new = (select_type *)malloc(size);
    fread(new, size, 1, stream);
    tmp = re_build(*new, tmp);
    printf("%s\n", new->fnp_stud.last_name);
    */
    fclose(stream);
    printf("%s\n", tmp->fnp_stud.last_name);
    return tmp;
}