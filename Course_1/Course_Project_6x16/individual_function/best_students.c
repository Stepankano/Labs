#include <stdio.h>
#include "../data.h"
#include <malloc.h>
#include "../re_builder/re_builder.h"

typedef struct
{
    str(last_name);
    struct best_stud *next, *last;
} best_stud;

#define sum(a) (a->mks.ez.cs + a->mks.ez.hi + a->mks.ez.ma + a->mks.ez.dm)

void best_students(select_type *tmp)
{
    info_stud *new_list = NULL, *student = NULL;
    if (!tmp)
    {
        printf("%s\n", "Database is empty");
        return;
    }
    while (tmp->last)
    {
        tmp = tmp->last;
    }
    while (tmp)
    {
        if (tmp->mks.ez.cs >= 4 && tmp->mks.ez.dm >= 4 && tmp->mks.ez.hi >= 4 && tmp->mks.ez.ma >= 4)
        {
            if (!new_list)
            {
                new_list = tmp;
                new_list->last = NULL;
            }
            else
            {
                new_list->next = tmp;
                tmp->last = new_list;
                new_list = tmp;
            }
        }
        tmp = tmp->next;
        new_list->next = NULL;
    }
    while (new_list->last)
    {
        new_list = new_list->last;
    }
    student = new_list;
    info_stud *second_tmp = student;
    int sum_marks, tmp_group;
    while (student)
    {
        sum_marks = sum(student);
        tmp_group = student->group_num;
        while (student->next && student->group_num == tmp_group)
        {
            student = student->next;
        }
        while (new_list->next)
        {
            if (sum_marks < sum(new_list) && tmp_group == new_list->group_num)
            {
                sum_marks = sum(new_list);
            }
            new_list = new_list->next;
        }
        if (sum_marks < sum(new_list) && tmp_group == new_list->group_num)
        {
            sum_marks = sum(new_list);
        }
        while (new_list->last)
        {
            if (sum_marks > sum(new_list) && tmp_group == new_list->group_num)
            {
                if (new_list->next)
                {
                    new_list->next->last = new_list->last;
                }
                if (new_list->last)
                {
                    new_list->last->next = new_list->next;
                }
                info_stud *deleter = new_list;
                if (new_list->last)
                {
                    new_list = new_list->last;
                }
                else if (new_list->next)
                {
                    new_list = new_list->next;
                }
                free(deleter);
            }
            new_list = new_list->last;
        }
        if (sum_marks > sum(new_list) && tmp_group == new_list->group_num)
        {
            if (new_list->next)
            {
                new_list->next->last = new_list->last;
            }
            if (new_list->last)
            {
                new_list->last->next = new_list->next;
            }
            info_stud *deleter = new_list;
            if (new_list->last)
            {
                new_list = new_list->last;
            }
            else if (new_list->next)
            {
                new_list = new_list->next;
            }
            free(deleter);
        }
        if (student && !student->next)
        {
            break;
        }
    }
    while (new_list->last)
    {
        new_list = new_list->last;
    }
    
    if(!new_list){
        printf("No one best student\n");
        return;
    }
    printf("%s\n", "Best students:");
    while (new_list->next)
    {
        printf("%s\n", new_list->fnp_stud.last_name);
        new_list = new_list->next;
    }
    if (new_list)
    {
        printf("%s\n", new_list->fnp_stud.last_name);
    }
    return;
}