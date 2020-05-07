#include <stdio.h>
#include "../data.h"
#define EMPT(a)                            \
    if (!a)                                \
    {                                      \
        printf("%s", "Database is empty"); \
        return;                            \
    }

void output_stud(info_stud *tmp)  //info_stud
{
    EMPT(tmp);
    printf("%25s %3s %5s %13s %15s\n", "Family N.P.", "sex", "group", "l.a. e.l. lab", "mat his dmt csc");

    for (;;)
    {
        printf("%20s %c.%c. %s  ", tmp->fnp_stud.last_name, tmp->fnp_stud.first_name, tmp->fnp_stud.patronymic, (tmp->sex_stud == F_stud) ? "F" : "M");
        printf("%5d%4c %4c  %3c", tmp->group_num, tmp->mks.off.this_la, tmp->mks.off.this_el, tmp->mks.off.this_lab);
        printf(" %3d %3d %3d %3d \n", tmp->mks.ez.ma, tmp->mks.ez.hi, tmp->mks.ez.dm, tmp->mks.ez.cs);
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            return;
        }
    }
}

void output_pc(info_pc *tmp) // info_pc
{
    EMPT(tmp);
    printf("%20s %9s %8s %6s %8s %10s%8s %10s %9s %9s %9s %20s\n", "Family", "CPU count", "CPU type","memory" "GPU type", "GPU memory", "HDD type", "HDD memory", "HDD count", "dcs ctrl", "blt ctrl", "OC");
    for (;;)
    {
        printf("%20s %9d %8s %6d %8s %10d", tmp->last_name, tmp->proc.count, tmp->proc.type, tmp->memory, (tmp->video.typ == built_in)?"built_in":(tmp->video.typ == discrete)?"discrete":(tmp->video.typ == AGP)?"AGP":"PCI",tmp->video.memory);
        printf("%8s %10d %9d", (tmp->hdd.typ == SCSI_IDE)?"SCSI_IDE":"ATA_SATA", tmp->hdd.memory, tmp->hdd.count);
        printf("%11d %11d %20s\n", tmp->ctrl.discrete, tmp->ctrl.built_in, tmp->OC);
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            return;
        }
    }
    return;
}

void output_exam(info_exam *tmp)  //info_exam
{
    EMPT(tmp);
    printf("%25s %3s %6s %17s %5s %5s\n", "Family N.P.", "sex", "school", "math rus inf phis", "medal", "essay");

    for (;;)
    {
        printf("%20s %c.%c. %s  ", tmp->fnp_exam.last_name, tmp->fnp_exam.first_name, tmp->fnp_exam.patronymic, (tmp->sex_exam == F_exam) ? "F" : "M");
        printf("%6d%4d %3d  %3d %4d", tmp->school_number, tmp->mar_exam.math, tmp->mar_exam.rus, tmp->mar_exam.inf, tmp->mar_exam.phis);
        printf(" %5d %5d\n", (tmp->this_medal == 1)?1:0, (tmp->this_essay == 1)?1:0);
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            return;
        }
    }
    return;
}

void output_passenger(info_passenger *tmp)  //info_passenger
{
    EMPT(tmp);
    printf("%25s %3s %4s %20s %5s %7s %14s\n", "Family N.P.", "bag", "mass", "destinayion point", "time", "transit", "children count");

    for (;;)
    {
        printf("%20s %c.%c. %3d  ", tmp->fnp_pass.last_name, tmp->fnp_pass.first_name, tmp->fnp_pass.patronymic, tmp->bags);
        printf("%4d %20d %5d  %7s %14d\n", tmp->mass, tmp->point, tmp->time, (tmp->this_transit ==1)?"yes":"no", tmp->children_count);
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            return;
        }
    }
    return;
}

void output_school(info_school *tmp)  //info_school
{
    EMPT(tmp);
    printf("%25s %3s %5s %3s %20s %20s %20s\n", "Family N.P.", "sex", "class", "lit", "univesity", "work","army");

    for (;;)
    {
        printf("%20s %c.%c. %s  ", tmp->fnp_sch.last_name, tmp->fnp_sch.first_name, tmp->fnp_sch.patronymic, (tmp->this_sex == F_sch) ? "F" : "M");
        printf("%5d%3c %20s %20s %20s", tmp->class_num, tmp->lit_class, tmp->University, tmp->work, tmp->army);
        
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            return;
        }
    }
    return;
}

