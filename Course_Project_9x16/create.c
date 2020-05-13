#include <stdio.h>
#include <malloc.h>
#include "data.h"

int create(row *tmp, int size)
{
    size += 1;
    tmp = (row *)realloc(tmp, size * sizeof(row));
    if (!tmp)
    {
        size -= 1;
        printf("Out of memory\n");
        
    }
    printf("Enter a string: ");
    getchar();
    scanf("%[^\n]s", &(tmp[size - 1].string));
    printf("Enter a key: ");
    getchar();
    scanf("%f", &(tmp[size - 1].key));
    return size;
}