/* 
 *   Функция push заносит в очередь новый элемент
 *   Функция pop забирает из очереди элемент
 */

#include "data.h"
#include <malloc.h>

int* push(int *queue, int * size_of_queue,int value)
{
    *size_of_queue += 1;
    int* tmp_queue = NULL;
    
    tmp_queue = (int *)realloc(queue, *size_of_queue * (sizeof(int)));
    if (!tmp_queue)
    {
        printf("%s\n", "Out of memory");
        *size_of_queue -= 1;
    }
    else
    {
        queue = tmp_queue;
        queue[*size_of_queue - 1] = value;
    }
    printf("%s", "\n");
    return queue;
}

int* pop(int *queue, int *size_of_queue)
{
    if (*size_of_queue == 0)
    {
        printf("%s\n", "Queue is empty");
    }
    else if (*size_of_queue == 1)
    {
        free(queue);
       * size_of_queue = 0;
        return NULL;
    }
    else
    {
        for (int i = 0; i < *size_of_queue - 1; i++)
        {
            queue[i] = queue[i + 1];
        }
        *size_of_queue -= 1;
        queue = (int *)realloc(queue, *size_of_queue * (sizeof(int)));
    }
    printf("%s", "\n");
    return queue;
}