#include <stdio.h>
#include "builder.h"
#include "walker.h"
#include "structures.h"
#include "menu.h"
int main()
{
    printf("%s\n ", "Welcome!!!");
    getchar();
    int code = 0;
    cell cell_gen = {NULL, NULL, NULL, 0};
    coup shuttle = {cell_gen, 0, 0};
    while (code != 5)
    {
        shuttle = commutator(shuttle);
        code = shuttle._int;
    }
    printf("%s\n","Goodbye!!!");
    getchar();
    return 0;
}