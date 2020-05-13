#include <stdio.h>
#include <malloc.h>
#include "data.h"

void search(row *tmp, int low, int high)
{
    printf("Enter a key: ");
    char key;
    scanf("%c", &key);
    if (tmp[(low + high) / 2].key > key)
    {
        search(tmp, low, (low + high) / 2);
        return;
    }
    else if (tmp[(low + high) / 2].key < key)
    {
        search(tmp, (low + high) / 2, high);
        return;
    }
    else
    {
        printf("%s %f %s %s", "Key: ", tmp[(low + high) / 2].key, "\nString: ", tmp[(low + high) / 2].string);
    }
    return;
}