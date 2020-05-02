
#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "function/function.h"
#include "parse_exp/parse.h"
#include "output/tree_output.h"
#include "cleaner/cleaner.h"

int menu(void)
{
    printf("%s\n", "1. Enter expression");
    printf("%s\n", "2. Transform expression");
    printf("%s\n", "3. Text output expression");
    printf("%s\n", "4. Tree output expression");
    printf("%s\n", "5. Exit");
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main()
{

    cell *root_tmp = NULL;
    printf("%s\n", "Welcome!");
    int k = 0;

    while (k != 5)
    {
        k = menu();
        switch (k)
        {
        case 1:
        {
            getchar();
            clean_tree(root_tmp);
            root_tmp = parse(root_tmp);

            if (!root_tmp)
            {
                printf("%s\n", "Errur");
            }
            if (root_tmp)
            {
                while (root_tmp->parent)
                {
                    root_tmp = root_tmp->parent;
                }
            }
            printf("\n");
        }
        break;
        case 2:
        {
            getchar();
            func_num_16(root_tmp);
            printf("\n");
        }
        break;
        case 3:
        {
            getchar();
            text_out(root_tmp);
            printf("\n");
        }
        break;
        case 4:
        {
            getchar();
            tree_out(root_tmp, 1);
            printf("\n");
        }
        break;
        case 5:

            break;

        default:
            printf("%s\n", "Try again)");
            break;
        }
    }

    printf("%s", "Goodbye!");
    return 0;
}