
#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "./enter_exp/enter.h"
#include "./add/add.h"
#include "./output/tree_output.h"

int menu(void)
{
    printf("%s\n", "1. Enter expression");
    printf("%s\n", "2. Transform expression");
    printf("%s\n", "3. Text ouput expression");
    printf("%s\n", "4. Tree output expression");
    printf("%s\n", "5. Calculate the result");
    printf("%s\n", "6. Exit");
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main()
{

    cell *root_tmp = NULL;
    printf("%s\n", "Welcome!");
    int k = 0;

    while (k != 6)
    {
        k = menu();
        switch (k)
        {
        case 1:
        {
           root_tmp = enter();
            printf("\n");
        }
        break;
        case 2:
        {
            
        }
        break;
        case 3:
        {
            
        }
        break;
        case 4:
        {
            getchar();
            text_out(root_tmp, 0);
        }
        break;
        case 5:

            break;
      

        case 6:

            break;
        default:
            printf("%s\n", "Try again)");
            break;
        }
    }

    printf("%s", "Goodbye!");
    return 0;
}