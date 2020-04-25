#include <stdio.h>
#include <stdlib.h>
#include "../data.h"
#include "../builder/build.h"
#include "../cleaner/cleaner.h"

#define add_char                 \
    tmp = add_char(symbol, tmp); \
    printf("%c ", symbol);

#define add_int                 \
    tmp = add_int(number, tmp); \
    printf("%d ", number);

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
        number *= a;                              \
        add_int;                                  \
        number = 0;                               \
    }

#define Errur(pos)                                            \
    printf("%s %d %s\n", "Syntax error in", pos, "position"); \
    clean_tree(tmp);                                          \
    return NULL;

cell *parse(cell *tmp)
{
    char symbol;
    int number = 0, corruption = 0, pos = 0;
    while (scanf("%c", &symbol) != '\n')
    {
        int val = symbol;
        pos++;
        if ((val > 47) && (val < 58))
        {
            parse_num(1);
        }
        else if (((val > 39) && (val < 44)) || (val == 47) || (val == 136) || ((val > 96) && (val < 123)))
        {
            add_char;
        }
        else if (val == 45)
        {
            scanf("%c", &symbol);
            val = symbol;
            pos++;
            if (symbol == ' ')
            {
                symbol = '-';
                add_char;
            }
            else if ((val > 47) && (val < 58))
            {
                parse_num(-1);
            }
            else if ((val > 96) && (val < 123))
            {
                val = val - 32;
                symbol = val;
                add_char;
            }
            else
            {
                Errur(pos);
            }
        }
        else if (symbol == ' ')
        {
            continue;
        }
        else if (symbol == '\n')
        {
            pos--;
            return tmp;
        }
        else
        {
            Errur(pos);
        }
        if (corruption)
        {

            return NULL;
        }
    }
    return tmp;
}