#include <stdio.h>
#include "../data.h"
#include "../add/add.h"
#include "enter.h"

cell *enter()
{
    cell *exp = NULL;
    bool inside = 0;
    int number = 0;
    char last_operate;
    char symbol = '0';
    while (symbol != '\n')
    {
        scanf("%c", &symbol);
        switch (symbol)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            last_operate = symbol;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            inside = 1;
            number = number * 10 + (int)(symbol)-48;
            break;

        default:
            if (inside)
            {
                exp = add_int(exp, number);
                inside = 0;
                number = 0;
            }
            else
            {
                exp = add_char(exp, last_operate);
            }
            break;
        }
    }
    return exp;
}