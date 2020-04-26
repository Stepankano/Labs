#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define info_stud struct info_student
#define FNP struct FNP
#define FIO struct FIO
#define marks struct marks
#define exam struct exam
#define offset struct offset
#define inf_test struct inf_test

typedef info_stud
{
    typedef FNP
    {
        char last_name[50]; //пока что костыль, но может ли  фамилия содержать >  50 символов? переделать в динамический массив
        char first_name;
        char patronymic;
    }
    full_name;

    enum sex
    {
        F,
        M
    };

    int group_num;

    typedef marks //будем считать, что это 2-й семестр Маёвника
    {
        typedef offset
        {
            enum la // linear algebra
            {
                yes = 1,
                no = 0
            };
            enum el // english language
            {
                yes = 1,
                no = 0
            };
            enum lab // labs
            {
                yes = 1,
                no = 0
            };
        }
        off;
        typedef exam
        {
            int ma; // mathematical analysis
            int hi; // history
            int dm; // discrete math
            int cs; // counter strike 1.6
        }
        ez;
    }
    mks;
}
inf;
typedef inf_test
{
    typedef FIO
    {
        char last_name[20];
        char first_name;
    }
    Fio;
    int age;
}
teste;

#endif