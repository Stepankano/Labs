/*
 *  Умножение строки на матрицу и подсчет ненулевых элементов
 */
#include <stdio.h>
#include "data.h"

void function(cell *list)
{
    int height = 0;
    int width = 0;
    int index;
    float value;
    cell *tmp = NULL;
    while (list) //определение высоты и ширины матрицы
    {
        if (list->index / 10 > height)
        {
            height = list->index / 10;
        }
        if (list->index % 10 > width)
        {
            width = list->index % 10;
        }
        if (list->next)
        {
            list = list->next;
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < height; i++) //заполнение строки
    {
        printf("Enter index and value: ");
        scanf("%d", &index);
        scanf("%f", &value);
        if (!tmp)
        {
            Cret(tmp);
            tmp->last = NULL;
            tmp->next = NULL;
            tmp->index = index;
            tmp->value = value;
        }
        else
        {
            Cret(tmp->next);
            tmp->next->last = tmp;
            tmp->next->next = NULL;
            tmp->next->index = index;
            tmp->next->value = value;
            tmp = tmp->next;
        }
    }
    while (tmp->last)
    {
        tmp = tmp->last;
    }
    int count_not_zero = 0;
    float sum;
    float *matrix = conversion(list);
    for (int i = 0; i < width; i++)
    {
        sum = 0;
        for (int k = 0; k < height; k++)
        {
            sum += (tmp->value) * matrix[i + k * width];
            if (tmp->next)
            {
                tmp = tmp->next;
            }
        }
        if (((sum > 0) ? sum : (-sum)) > eps)
        { 
            count_not_zero += 1;
        }
        while (tmp->last)
        {
            tmp = tmp->last;
        }
    }
    printf("Not null elements: %d\n", count_not_zero);
}
