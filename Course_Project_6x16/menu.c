#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "extract/extract.h"
#include "individual_function/best_students.h"
#include "output/output.h"
#include "re_builder/re_builder.h"
#include "writer/writer.h"

#define def_function(a)            \
    _Generic((a),                  \
             info_stud             \
             : func_inf_stud(a);   \
             info_pc               \
             : func_inf_pc(a);     \
             info_exam             \
             : func_inf_exam(a);   \
             info_passenger        \
             : func_inf_pass(a);   \
             info_school           \
             : func_inf_school(a); \
             inf_test              \
             : func_inf_test(a);   \
             default               \
             : printf("%s", Errur))

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        select_type *new, *tmp;
        int size = sizeof(select_type);
        FILE *stream;
        stream = fopen(__NAME__, "r");
        if (!stream)
        {
            perror("Не удалось открыть файл");
            return 1;
        }
        new = (select_type *)malloc(size);
        fread(new, size, 1, stream);
        new->last = NULL;

        while (!feof(stream) && new->next)
        { //пока ксть файл
            new->next = (select_type *)malloc(size);
            fread(new->next, size, 1, stream);
            new->next->last = new;
            new = new->next;
        }
        fclose(stream);
        new->next = NULL;
        printf("Extracting...................OK\n");

        select_type *root_tmp = NULL;
        root_tmp = new;
        //root_tmp = extract(root_tmp);
        printf("%s\n", "Welcome!");
        if (root_tmp)
        {
            if (argv[1][0] == '-' && argv[1][1] == 'f')
            {
                while (root_tmp->last)
                {
                    printf("%s\n", root_tmp->fnp_stud.last_name);
                    root_tmp = root_tmp->last;
                    printf("%s\n", root_tmp->fnp_stud.last_name);
                }
                output_stud(root_tmp);

                getchar();
                printf("%s", "Goodbye!");
                return 0;
            }
            else if (argv[1][0] == '-' && argv[1][1] == 'p')
            {
                // def_function(root_tmp);
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
            printf("%s", "Dtabase is empty menu");
        }
    }
    else
    {
        printf("%s", "Errur at command line");
    }
    return 0;
}