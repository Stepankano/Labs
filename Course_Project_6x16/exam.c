#include <stdio.h>
#include "data.h"

#define opr(a)                             \
    _Generic((a),                          \
             int                           \
             : printf("%s\n", "integer"),  \
               char                        \
             : printf("%s\n", "char"),     \
               inf_test                    \
             : printf("%s\n", "inf_test"), \
               default                     \
             : printf("%s\n", "errur"))

int main()
{
    int a = 7;
    char b = 5;
    float h;
    inf_test mem;
    opr(a);
    opr(b);
    opr(mem);
    opr(h);

    return 0;
}