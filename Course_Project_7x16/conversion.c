/*
 *  Преобразование списка в матрицу и её вывод
 */
#include <stdio.h>
#include "data.h"

float *conversion(cell *tmp)
{
    int width = 0;
    int height = 0;
    while (tmp) //определение высоты и ширины матрицы
    {
        if (tmp->index / 10 > height)
        {
            height = tmp->index / 10;
        }
        if (tmp->index % 10 > width)
        {
            width = tmp->index % 10;
        }
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    while (tmp->last)
    {
        tmp = tmp->last;
    }
    float *matrix = (float *)realloc(NULL, height * width * sizeof(float));
    for (int i = 0; i < height * width; i++)
    {
        matrix[i] = 0;
    }
    while (tmp)
    {
        matrix[((tmp->index / 10)-1) * width + (tmp->index % 10) - 1] = tmp->value;
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    
    for (int i = 0; i < height * width; i++)
    {
        if(i%width == 0){
            printf("\n");
        }
        printf("%3.3f ",matrix[i]);
        
    }
    
    printf("\n");
return matrix;
}
