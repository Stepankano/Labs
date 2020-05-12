#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "data.h"

int menu(void)
{
    printf("%s\n", "1. Push num");
    printf("%s\n", "2. Pop num");
    printf("%s\n", "3. Output");
    printf("%s\n", "4. Sort");
    printf("%s\n", "5. Exit");
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main()
{
    int *queue = NULL;
    int *tmp_queue = NULL;
    int size_of_queue = 0;
    printf("%s\n", "Welcome!");
    int k = 0;

    while (k != 5)
    {
        k = menu();
        switch (k)
        {
        case 1: //push
        {
            int value;
            getchar();
            printf("%s ", "Enter a num:");
            scanf("%d", &value);
            size_of_queue += 1;
            tmp_queue = (int *)realloc(queue, size_of_queue * (sizeof(int)));
            if (!tmp_queue)
            {
                printf("%s\n", "Out of memory");
                size_of_queue -= 1;
            }
            else
            {
                queue = tmp_queue;
                queue[size_of_queue - 1] = value;
            }
            printf("%s", "\n");
        }
        break;
        case 2:
        {
            getchar();
            if (size_of_queue == 0)
            {
                printf("%s\n", "Queue is empty");
            }
            else if (size_of_queue == 1)
            {
                free(tmp_queue);
                free(queue);
            }
            else
            {
                for (int i = 0; i < size_of_queue-1; i++)
                {
                    queue[i]=queue[i+1];
                }
                size_of_queue -= 1;
                tmp_queue = (int *)realloc(queue, size_of_queue * (sizeof(int)));
                queue = tmp_queue;
            }
            printf("%s", "\n");
        }
        break;
        case 3:
        {
            for (int i = 0; i < size_of_queue; i++)
            {
                printf("%d ", queue[i]);
            }
            printf("%s", "\n");
        }
        break;
        case 4:
        {
            int tmp = 0;
            for (int i = 1; i < size_of_queue; i++)
            {
                if (queue[i] < queue[i - 1])
                {
                    tmp = queue[i];
                    queue[i] = queue[i - 1];
                    queue[i - 1] = tmp;
                    i = 0;
                }
            }
        }
        break;
        default:
            printf("%s\n", "Try again)");
            break;
        case 5:
            break;
        }
    }

    printf("%s", "Goodbye!");
    return 0;
}