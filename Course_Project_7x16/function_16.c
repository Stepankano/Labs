/*
 *  Умножение строки на матрицу и подсчет ненулевых элементов
 */
#include <stdio.h>
#include "data.h"

void function_Koti(cell *list)
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

void function_Zayki(cell *list)
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
    float *matrix = conversion(list);
    float sum_str;
    int count_not_zero;
  //  printf("BR1\n");
    for (int i = 0; i < height; i++)
    {
        sum_str = 0;
        count_not_zero = 0;
       // printf("BR1.1\n");
        for (int k = 0; k < width; k++)
        {
          //  printf("BR1.2\n");
            sum_str += matrix[i * width + k];
         //   printf("BR1.3\n");
            if ((matrix[i * width + k]) > 0 ? (matrix[i * width + k]) : (-1) * (matrix[i * width + k]) > eps)
            {
                count_not_zero += 1;
            }
            printf("---%f\n",matrix[i * width + k]);
        }
        printf("%f %d\n",sum_str,count_not_zero);
       // printf("BR1.4\n");
        if (!tmp)
        {
           // printf("BR1.4.1\n");
            Cret(tmp);
          //  printf("BR1\n");
            tmp->last = NULL;
           // printf("BR2\n");
            tmp->next = NULL;
           // printf("BR3\n");
            tmp->index = count_not_zero;
          //  printf("BR4\n");
            tmp->value = sum_str;
           // printf("BR1.4.1.1\n");
        }
        else
        {
           // printf("BR1.4.2\n");
            Cret(tmp->next);
            tmp->next->last = tmp;
            tmp->next->next = NULL;
            tmp->next->index = count_not_zero;
            tmp->next->value = sum_str;
            tmp = tmp->next;
            //printf("BR1.4.2.1\n");
        }
        //printf("BR1.5\n");
    }
   // printf("BR2\n");
    int max_not_zero = 0;
    while (tmp)
    {
        max_not_zero = (tmp->index > max_not_zero) ? tmp->index : max_not_zero;
        if (tmp->last)
        {
            tmp = tmp->last;
        }
        else
        {
            break;
        }
    }
    //printf("BR3\n");
    while (tmp)
    {
        if (tmp->index == max_not_zero)
        {
            printf("Max not zero: %d, sum: %5.5f\n", tmp->index, tmp->value);
        }
        if(tmp->next){
            tmp=tmp->next;
        }else{
            break;
        }
    }
    return;
}