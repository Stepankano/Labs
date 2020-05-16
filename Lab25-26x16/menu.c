/*
 *  Программа создаёт динамический массив и отображает на него очередь.
 *  Лоступные операции: 
 *  1. Push - добавление элемента в очередь
 *  2. Pop - удаление элемента из очереди
 *  3. Sort - сортировка очереди
 *  4. Output - вывод очереди
 */

#include <stdio.h>
#include <stdlib.h>

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
            getchar();
            int value;
            printf("%s ", "Enter a num:");
            scanf("%d", &value);
            queue = push(queue, &size_of_queue, value);
        }
        break;
        case 2: //pop
        {
            getchar();
            queue = pop(queue, &size_of_queue);
        }
        break;
        case 3:
        {
            getchar();
            output(queue, size_of_queue);
        }
        break;
        case 4:
        {
            getchar();
            queue = sort(queue, size_of_queue);
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