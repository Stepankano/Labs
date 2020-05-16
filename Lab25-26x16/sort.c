/*
 * Функция sort сортирует очередь (по невозрастанию)
 */
#include "data.h"

void sort(int*queue,int size_of_queue){
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