#include <stdio.h>
#include <stdlib.h>
#include "../data.h"
#include "../builder/build.h"
#include "../cleaner/cleaner.h"

#define parse_num(a)                              \
    number = val - 48;                            \
    while (scanf("%c", &symbol) != EOF)           \
    {                                             \
        val = symbol;                             \
        pos++;                                    \
        if ((val > 47) && (val < 58))             \
        {                                         \
            number = number * 10 + (val - 48);    \
        }                                         \
        else if (symbol == ' ' || symbol == '\n') \
        {                                         \
            break;                                \
        }                                         \
        else                                      \
        {                                         \
            Errur(pos);                           \
        }                                         \
    }                                             \
    if (!corruption)                              \
    {                                             \
        tmp = add_int(number * a, tmp);           \
        printf("%d ", (number * a));              \
        number = 0;                               \
    }

#define Errur(pos)                                            \
    printf("%s %d %s\n", "Syntax error in", pos, "position"); \
    clean_tree(tmp);                                               \
    return NULL;

//надо подключить остальные хэдэры и пофиксить расположение для доступа data.h если убирать это в отдельную папку
/*int parse(cell* tmp)*/
cell *parse(cell *tmp) //Строка для тестов
{
    char symbol;        //сам символ
    int number = 0;     //число
    int corruption = 0; //повреждение(да или нет)
    int pos = 0;
    while (scanf("%c", &symbol) != '\n')
    {
        int val = symbol;
        pos++;
        if ((val > 47) && (val < 58)) //если встретилась цифра то строим число
        {
            parse_num(1);
        }
        else if (((val > 39) && (val < 44)) || (val == 47) || (val == 136) || ((val > 96) && (val < 123))) //если встретился символ(не минус)
        {
            tmp = add_char(symbol, tmp);
            printf("%c ", symbol); //Строка для тестов
        }
        else if (val == 45) //если встретился минус
        {
            scanf("%c", &symbol); //считываем следующий символ
            val = symbol;         //
            pos++;                //
            if (symbol == ' ')    //если следующий символ - пробел, то запоминаем минус просто как символ
            {
                tmp = add_char('-', tmp);
                printf("%c ", '-'); //Строка для тестов
            }
            else if ((val > 47) && (val < 58)) //если встретилась цифра то строим число
            {
                parse_num(-1);
            }
            else if ((val > 96) && (val < 123)) //если встретилась буква, то делаем замену символа по типу -а = А
            {
                val = val - 32;
                symbol = val;
                tmp = add_char(symbol, tmp);
                printf("%c ", symbol); //Строка для тестов
            }
            else //Если в функцию попали запрещённые символы то отмечаем что данные повреждены(опть повторяющийся кусок кода)
            {
                
                Errur(pos);
            }
        }
        else if (symbol == ' ')
        {
            continue;
        } //Если пробел то продолжаем цикл, всё в порядке
        else if (symbol == '\n')
        {
            pos--;
            return tmp;
        }
        else //Если в функцию попали запрещённые символы то отмечаем что данные повреждены
        {
            Errur(pos);
        }
        if (corruption)
        {
            /* clearer_tree(tmp);*/
            return NULL;
        } //Возвращает единицу если данные повреждены
    }
    return tmp;
}