/*
 * Функция sort сортирует очередь (по невозрастанию)
 */
#include "data.h"

int *sort(int *queue, int size_one)
{
    int *queue_two, *queue_three;
    queue_two = queue_three = NULL;
    int size_two = 0, size_three = 0;
    for (int i = 1; i < size_one; i++)
    {
        if (queue[i] < queue[i - 1])
        {
            for (int k = 0; k <= i; k++)
            {
                queue_two = push(queue_two, &size_two, queue[0]);
                queue = pop(queue, &size_one);
            }
            for (int k = 0; k < i - 1; k++)
            {
                queue = push(queue, &size_one, queue_two[0]);
                queue_two = pop(queue_two, &size_two);
            }
            queue_three = push(queue_three, &size_three, queue_two[0]);
            queue_two = pop(queue_two, &size_two);

            if (queue_two)
            {
                queue = push(queue, &size_one, queue_two[0]);
                queue_two = pop(queue_two, &size_two);
            }

            queue = push(queue, &size_one, queue_three[0]);
            queue_three = pop(queue_three, &size_three);

            for (int z = 0; z < size_one - i - 1; z++)
            {
                queue = push(queue, &size_one, queue[0]);
                queue = pop(queue, &size_one);
            }
            i = 0;
        }
    }
    return queue;
}