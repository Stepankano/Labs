/*
 * Функция output выводит всю очередь
 */

#include "data.h"

void output(int *queue, int size_of_queue)
{
    for (int i = 0; i < size_of_queue; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("%s", "\n");
}