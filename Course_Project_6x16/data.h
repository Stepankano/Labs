#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define str(a) char a[20];

#define info_stud struct info_student
#define FNP struct FNP
#define marks struct marks
#define exam struct exam
#define offset struct offset

typedef info_stud
{
    FNP
    {
        str(last_name);
        char first_name;
        char patronymic;
    }
    fnp;

    enum sex
    {
        F = 'F',
        M = 'M'
    } sex;

    int group_num;

    marks //будем считать, что это 2-й семестр Маёвника
    {
        offset
        {
            enum la // linear algebra
            {
                yes = 'y',
                no = 'n'
            } this_la;
            enum el // english language
            {
                yes = 'y',
                no = 'n'
            } this_el;
            enum lab // l.a.b.s. - Liberty. Advertisement. Bureaucracy. Solving
            {
                yes = 'y',
                no = 'n'
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
#define marks struct marks
//#define FNP struct FNP

typedef info_exam
{
    FNP
    {
        str(last_name); //
        char first_name;
        char patronymic;
    }
    full_name;

    enum sex
    {
        F,
        M
    } sex;
    int school_number;
    enum medal
    {
        yes = 'y',
        no = 'n'
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
        T = 1,
        F = 0
    } this_essay;
    info_exam *next;
    info_exam *last;
}
ex;

#define info_passenger struct info_passenger
//#define FNP struct FNP

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
        yes = 'y',
        no = 'n'
    } this_transit;
    int children_count;
    info_passenger *next;
    info_passenger *last;
}
aero;

#define info_school struct info_school
#define FNP struct FNP

typedef info_school
{
    FNP
    {
        str(last_name);
        char first_name;
        char patronymic;
    }
    full_name;

    enum sex
    {
        F = 'F',
        M = 'M'
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


#define select_type info_school

#define cell struct cell
typedef cell
{
    enum type{
        st_type,
        pc_type,
        ex_type,
        ps_type,
        sc_type
    }type;
    union data{
        info_stud st;
        info_pc pc;
        info_exam ex;
        info_passenger ps;
        info_school sc;
    }data;
}
this_cell;
#endif