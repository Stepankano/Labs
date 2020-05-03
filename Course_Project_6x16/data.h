#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <malloc.h>
#define str(a) char a[20];
#define __NAME__ "database"

#define Cret(tmp, type)                 \
    tmp = (type *)malloc(sizeof(type)); \
    if (!tmp)                           \
    {                                   \
        printf("%s\n", "Out of meme");  \
        return;                         \
    }

#define to_high(tmp)         \
    if (tmp)                 \
    {                        \
        while (tmp->last)    \
        {                    \
            tmp = tmp->last; \
        }                    \
        writer(tmp);         \
    }

#define info_stud struct info_student
#define FNP_stud struct FNP_stud
#define marks struct marks
#define exam struct exam
#define offset struct offset

typedef info_stud
{
    FNP_stud
    {
        str(last_name);
        char first_name;
        char patronymic;
    }
    fnp_stud;

    enum sex_stud
    {
        F_stud = 'F',
        M_stud = 'M'
    } sex_stud;

    int group_num;

    marks //будем считать, что это 2-й семестр Маёвника
    {
        offset
        {
            enum la // linear algebra
            {
                la_yes = 'y',
                la_no = 'n'
            } this_la;
            enum el // english language
            {
                el_yes = 'y',
                el_no = 'n'
            } this_el;
            enum lab // l.a.b.s. - Liberty. Advertisement. Bureaucracy. Solving
            {
                lab_yes = 'y',
                lab_no = 'n'
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

#define info_exam struct info_exam
#define marks_exam struct marks_exam
#define FNP_exam struct FNP_exam

typedef info_exam
{
    FNP_exam
    {
        str(last_name); //
        char first_name;
        char patronymic;
    }
    fnp_exam;

    enum sex_exam
    {
        F_exam = 'F',
        M_exam = 'M'
    } sex_exam;
    int school_number;
    enum medal
    {
        yes_medal = 'y',
        no_medal = 'n'
    } this_medal;
    marks_exam
    {
        int math;
        int rus;
        int inf;
        int phis;
    }
    mar_exam;
    enum essay
    {
        yes_essay = 'y',
        no_essay = 'n'
    } this_essay;
    info_exam *next;
    info_exam *last;
}
ex;

#define info_passenger struct info_passenger
#define FNP_pass struct FNP_pass

typedef info_passenger
{
    FNP_pass
    {
        str(last_name);
        char first_name;
        char patronymic;
    }
    fnp_pass;
    int bags;
    int mass;
    str(point);
    str(time);
    enum transit
    {
        yes_pass = 'y',
        no_pass = 'n'
    } this_transit;
    int children_count;
    info_passenger *next;
    info_passenger *last;
}
aero;

#define info_school struct info_school
#define FNP_sch struct FNP_sch

typedef info_school
{
    FNP_sch
    {
        str(last_name);
        char first_name;
        char patronymic;
    }
    fnp_sch;

    enum sex
    {
        F_sch = 'F',
        M_sch = 'M'
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

#define select_type info_stud

#endif