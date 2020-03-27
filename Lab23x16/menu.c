#include <stdio.h>
#include "data.h"
#include "add_delete.h"

int interface(void)
{

    printf("%s\n", "What do you want?");
    printf("%s\n", "1. Add a cell");
    printf("%s\n", "2. Delete a cell");
    printf("%s\n", "3. My function (check symmetry)");
    printf("%s\n", "4. Text output tree");
    printf("%s\n", "5. Quit");

    char answer;
    answer = getchar();
    return answer;
}

int main()
{
    printf("%s\n", "---Welcome!!!---");
    int key_quit = 0;
    cell tmp_root;
    cell *root = &tmp_root;
    tmp_root.left = root;
    tmp_root.right = NULL;

    while (key_quit == 0)
    {    
        switch (interface())
        {
        case '1':
        {
           adapter(root);
        }
        break;
        case '2':
        {
            delete_cell(root);
        }
        break;
        case '3':
        {
            // my_function(root);
        }
        break;
        case '4':
        {
            // text_output(root);
        }
        break;
        case '5':
        {
            key_quit = 1;
        }
        break;

        case 'f':
        case 'F':
        {
            printf("%s\n", "Respect expressed");
        }
        break;
        default:
        {
            printf("%s\n", "Try again");
        }
        break;
        }
    }
    printf("%s", "---Give us 5 star at google play!!!---");
    return 0;
}