#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include "builder.h"
#include "destroyer.h"
#include "structures.h"
#include "walker.h"

int menu()
{
    int number;

    printf("\n%s\n", "What do you want?");
    printf("%s\n", "1. Add a cell");
    printf("%s\n", "2. Delete a cell");
    printf("%s\n", "3. Text output");
    printf("%s\n", "4. Check symmetry");
    printf("%s\n", "5. Quit");

    scanf("%d", &number);

    return number;
}

coup commutator(coup root_in)
{

    switch (menu())
    {
    case 1:
    {
        int root_value;
        if (!root_in.root_bool)
        {

            printf("%s", "Enter value: ");
            scanf("%d", &root_value);
            root_in._cell = builder(root_value);

            coup answer = {root_in._cell, 0, 1};
            return answer;
        }
        else
        {
            printf("%s", "Enter value: ");
            scanf("%d", &root_value);
            cell *adder = &root_in._cell;
            pathfinder(root_value, adder);
            coup answer = {root_in._cell, 1, 1};
            return answer;
        }
    }
    break;

    case 2:
    {
        if (!root_in.root_bool)
        {
            printf("%s\n", "Error!!! ");
            coup answer = {root_in._cell, 0, 1};
            return answer;
        }
        else
        {
            int root_value;
            coup answer;
            printf("%s", "Enter value: ");
            scanf("%d", &root_value);
            cell *deleter = &root_in._cell;
            cell temper;
            temper = destroyer(root_value, deleter);
            if (temper.left == temper.parent)
            {
                coup answer = {temper, 1, 0};
            }
            else
            {
                coup answer = {root_in._cell, 1, 1};
            }
            return answer;
        }
        break;

    case 3:
        /* code */
        break;

    case 4:
    {
        cell *tmp_left = &root_in._cell;
        cell *tmp_right = &root_in._cell;

        if (walker(root_in._cell.value, tmp_left, tmp_right))
        {
            printf("%s\n", "Tree is symmetrically");
        }
        else
        {
            printf("%s\n", "Tree isn't symmetrically");
        }
        coup answer = {root_in._cell, 4, root_in.root_bool};
        return answer;
    }
    break;
    case 5:
    {
        coup answer = {root_in._cell, 5, root_in.root_bool};
        return answer;
    }
    break;
    default:
    {
        printf("%s\n", "Try again :)");
    }
    break;
    }
    }
}
#endif