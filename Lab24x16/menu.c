
#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "function/function.h"

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
    root_tmp=(cell*)malloc(sizeof(cell));
    root_tmp->left=(cell*)malloc(sizeof(cell));
    root_tmp->left->right=(cell*)malloc(sizeof(cell));
    root_tmp->type = 1;
    root_tmp->val.value = 1;
    root_tmp->right=NULL;
    root_tmp->left->type = 0;
    root_tmp->left->val.oper = '/';
    root_tmp->left->left=NULL;
    root_tmp->left->right->type = 1;
    root_tmp->left->right->val.value = 1;
    root_tmp->left->right->left=NULL;
    root_tmp->left->right->right=NULL;

    while (k != 5)
    {
        k = menu();
        switch (k)
        {
        case 1:
        {
            getchar();
            //root_tmp = enter(root_tmp);
            printf("\n");
        }
        break;
        case 2:
        {
            getchar();
            func(root_tmp);
            printf("\n");
        }
        break;
        case 3:
        {
            getchar();
            //text_out(root_tmp);
            printf("\n");
        }
        break;
        case 4:
        {
            getchar();
            //tree_out(root_tmp);
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