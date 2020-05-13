#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "data.h"

int menu(void)
{
    printf("%s\n", "1. Add table");
    printf("%s\n", "2. Sort table");
    printf("%s\n", "3. Search at table");
    printf("%s\n", "4. Exit");
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main()
{
    row *table = NULL;
    int size_table = 0;

    printf("%s\n", "Welcome!");
    int k = 0;

    while (k != 4)
    {
        k = menu();
        switch (k)
        {
        case 1:
        {
            getchar();
            size_table = create(table, size_table);
        }
        break;
        case 2:
        {
            getchar();
            sorting(table, size_table);
        }
        break;
        case 3:
        {
            getchar();
            search(table, 0, size_table - 1);
        }
        break;
        case 4:
            break;
        default:
            printf("%s\n", "Try again)");
            break;
        }
    }

    printf("%s", "Goodbye!");
    return 0;
}