/*
 * Создание линейного двунапрвленного списка, 
 * проведение над ним 4 стандартных действий и 1 нестандартного.
 * Стандартные:
 * 1. Печать списка
 * 2. Вставка нового элемента в список
 * 3. Удаление элемента из списка
 * 4. Подсчёт длины списка
 * Тип элементов: перечислимый
 * Нестандартное действие: дополнение списка копиями некоторого значения до указанной длины
 */
#include "data.h"

int menu(void)
{
    printf("%s\n", "1. Print");
    printf("%s\n", "2. Insert");
    printf("%s\n", "3. Delete");
    printf("%s\n", "4. Size");
    printf("%s\n", "5. Unstd_act");
    printf("%s\n", "6. Exit");
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main()
{

    printf("%s\n", "Welcome to my humble programm!");
    int k = 0;
    struct cell *barrier = NULL;
    while (k != 6)
    {
        k = menu();
        switch (k)
        {
        case 1: //Print
        {
            getchar();
            std_print(barrier);
        }
        break;
        case 2: //Insert
        {
            getchar();
            printf("Choose need`s sign(\nAARD(1)\nQUEN(2)\nIGNI(3)\nYRDEN(4)\nAXII(5)): ");
            int value;
            scanf("%d", &value);
            if (value > 5 || value < 1)
            {
                printf("Get a hold of yourself and try again!\n");
            }
            else
            {
                barrier = std_insert(barrier, (value==1)?AARD:(value==2)?QUEN:(value==3)?IGNI:(value==4)?YRDEN:AXII);
            }
        }
        break;
        case 3: //Delete
        {
            getchar();
            printf("Choose don`t need`s sign(\nAARD(1)\nQUEN(2)\nIGNI(3)\nYRDEN(4)\nAXII(5)): ");
            int value;
            scanf("%d", &value);
            if (value > 5 || value < 1)
            {
                printf("Get a hold of yourself and try again!\n");
            }
            else
            {
                barrier = std_delete(barrier, (value==1)?AARD:(value==2)?QUEN:(value==3)?IGNI:(value==4)?YRDEN:AXII);
            }
        }
        break;
        case 4: //Size
        {
            getchar();
            int size;
            size = std_size(barrier);
            if(size==0){
                printf("List is empty\n");
            }else{
                 printf("List size: %d\n", size);
            }
        }
        break;
        case 5: //Unstd_act
        {
            getchar();
            printf("Choose trained sign(\nAARD(1)\nQUEN(2)\nIGNI(3)\nYRDEN(4)\nAXII(5)) and need`s range of list ");
            int value,range;
            scanf("%d %d", &value, &range);
            if (value > 5 || value < 1)
            {
                printf("Get a hold of yourself and try again!\n");
            }
            else
            {
                barrier = unstd_act(barrier, (value==1)?AARD:(value==2)?QUEN:(value==3)?IGNI:(value==4)?YRDEN:AXII,range);
            }
        }
        break;
        default:
            printf("%s\n", "Try again)");
            break;
        case 6:
            break;
        }
    }

    printf("%s", "Toss a coin to your witcher!");
    return 0;
}