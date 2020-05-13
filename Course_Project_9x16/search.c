#include <stdio.h>
#include <malloc.h>
#include "data.h"
#define average tmp[(low + high) / 2].key

void search(row *tmp, int low, int high, float key)
{
    if (average > key && ((average)-key) * ((average)-key) > eps)
    {
        if ((low + high) / 2 != low)
        {
            search(tmp, low, (low + high) / 2, key);
        }
        else
        {
            printf("Error\n");
        }
        return;
    }
    else if (average < key && ((average)-key) * ((average)-key) > eps)
    {
        if ((low + high) / 2 != high)
        {
            search(tmp, (low + high) / 2, high, key);
        }
        else
        {
            printf("Error\n");
        }
        return;
    }
    else if (((average)-key) * ((average)-key) < eps)
    {
        printf("%s %f %s %s\n", "Key: ", average, "\nString: ", tmp[(low + high) / 2].string);
    }
    else
    {
        printf("Error\n");
    }

    return;
}