#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define str(a) char a[50];

/*
#define info_stud struct info_student
#define FNP struct FNP
#define marks struct marks
#define exam struct exam
#define offset struct offset

typedef info_stud
{
    FNP
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
    } this_sex;

    int group_num;

    marks //будем считать, что это 2-й семестр Маёвника
    {
        offset
        {
            enum la // linear algebra
            {
                la_yes = 1,
                la_no = 0
            } this_la;
            enum el // english language
            {
                el_yes = 1,
                el_no = 0
            } this_el;
            enum lab // labs
            {
                lab_yes = 1,
                lab_no = 0
            } this_lab;
        }
        off;
        exam
        {
            int ma; // mathematical analysis
            int hi; // history
            int dm; // discrete math
            int cs; // counter strike 1.6
        }
        ez;
    }
    mks;

    info_stud *next;
    info_stud *last;
}
inf;
*/

/*
#define info_pc struct info_pc
#define CPU struct CPU
#define GPU struct GPU
#define HDD struct HDD
#define control struct control

typedef info_pc
{
    str(last_name); //имя
    CPU             //процессор
    {
        int count;
        str(type);
    }
    proc;
    int memory; //память
    GPU         //видяха
    {
        enum type_gpu
        {
            built_in,
            discrete,
            AGP,
            PCI
        } typ;
        int memory;
    }
    video;
    HDD //винчестер
    {
        enum type_hdd
        {
            SCSI_IDE,
            ATA_SATA
        } typ;
        int memory;
        int count;
    }
    hdd;
    control
    { // контроллеры
        int discrete;
        int built_in;
    }
    ctrl;
    str(OC);
    info_pc *next;
    info_pc *last;
}
pc;
*/

/*
#define info_exam struct info_exam
#define marks struct marks
#define FNP struct FNP

typedef info_exam
{
    FNP
    {
        str(last_name); //
        char first_name;
        char patronymic;
    }
    full_name;

    enum exam_sex
    {
        F,
        M
    } this_sex;
    int school_number;
    enum medal
    {
        medal_T = 1,
        medal_F = 0
    } this_medal;
    marks
    {
        int math;
        int rus;
        int inf;
        int phis;
    }
    mar;
    enum essay
    {
        essay_T = 1,
        essay_F = 0
    } this_essay;
    info_exam *next;
    info_exam *last;
}
ex;
*/

/*
#define info_passenger struct info_passenger
#define FNP struct FNP

typedef info_passenger
{
    FNP
    {
        str(last_name);
        char first_name;
        char patronymic;
    }
    full_name;
    int bags;
    int mass;
    str(point);
    str(time);
    enum transit
    {
        transit_T = 1,
        transit_F = 0
    } this_transit;
    int children_count;
    info_passenger *next;
    info_passenger *last;
}
aero;
*/

/*
#define info_school struct info_school

typedef info_school
{
    FNP
    {
        str(last_name);
        char first_name;
        char patronymic;
    }
    full_name;

    enum school_sex
    {
        sex_F,
        sex_M
    } this_sex;
    int class_num;
    char lit_class;
    str(University);
    str(work);
    str(army);
    info_school *next;
    info_school *last;
}
puple;
*/
#define inf_test struct inf_test
#define FIO struct FIO

typedef inf_test
{
    FIO
    {
        str(last_name);
        char first_name;
    }
    Fio;
    int age;
    inf_test *next;
    inf_test *last;
}
teste;

#define select_type inf_test

#endif