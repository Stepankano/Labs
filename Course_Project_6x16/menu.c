#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "extract/extract.h"
#include "individual_function/function.h"
#include "output/output.h"
#include "re_builder/re_builder.h"
#include "writer/writer.h"
#define def_output(a)             \
    _Generic((a),                 \
             info_stud            \
             : out_inf_stud(a);   \
             info_pc              \
             : out_inf_pc(a);     \
             info_exam            \
             : out_inf_exam(a);   \
             info_passenger       \
             : out_inf_pass(a);   \
             info_school          \
             : out_inf_school(a); \
             inf_test             \
             : out_inf_test(a);   \
             default              \
             : printf("%s", Errur))

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
        select_type *root_tmp = NULL;
        // root_tmp = extract(root_tmp);
        printf("%s\n", "Welcome!");
        if (argv[1][0] == '-' && argv[1][1] == 'f')
        {
            out_inf_stud();
            while(root_tmp->last){
                root_tmp = root_tmp->last;
            }
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
        printf("%s", "Errur at command line");
    }
    return 0;
}