#include <stdio.h>
#include <malloc.h>
#include "data.h"

void sorting(row *tmp, int size)
{
    for(int i=0; i<size;i++){
        printf("%s\n", tmp[i].string);
    }

    for (int i = 1; i < size; i++)
    {
        int k = i;
        while ( k > 0 && tmp[k].key > tmp[k - 1].key )
        {
            row f = tmp[k];
            tmp[k] = tmp[k - 1];
            tmp[k - 1] = f;
            k -= 1;
        }
    }
    
    for(int i=0; i<size;i++){
        printf("%s\n", tmp[i].string);
    }
    return;
}