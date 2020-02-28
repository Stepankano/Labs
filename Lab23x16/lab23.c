#include <stdio.h>
#include "builder.h"
#include "walker.h"
int main()
{
    cell root;
    root = builder();
    cell *tmp_left = &root;
    cell *tmp_right = &root;

    if (walker(root.value, tmp_left, tmp_right))
    {
        printf("%s\n", "Tree is symmetrically");
    }
    else
    {
        printf("%s\n", "Tree isn't symmetrically");
    }

    return 0;
}