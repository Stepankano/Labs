#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "extract/extract.h"
#include "individual_function/function.h"
#include "output/output.h"
#include "re_builder/re_builder.h"
#include "writer/writer.h"

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        inf_test *root_tmp = NULL;
        // root_tmp = extract(root_tmp);
        printf("%s\n", "Welcome!");
        if (argv[1][0] == '-' && argv[1][1] == 'f')
        {
            output(root_tmp);
            getchar();
            printf("%s", "Goodbye!");
            return 0;
        }
        else if (argv[1][0] == '-' && argv[1][1] == 'p')
        {
            //function(root_tmp);
            getchar();
            printf("%s", "Goodbye!");
            return 0;
        }
        else
        {
            printf("%s", "Errur at command line");
        }
    }
    else
    {
        printf("%s", "Errur at command line");
    }
    return 0;
}