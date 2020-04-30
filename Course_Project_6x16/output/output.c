#include <stdio.h>
#include "../data.h"
#define EMPT(a)                            \
    if (!a)                                \
    {                                      \
        printf("%s", "Database is empty"); \
        return;                            \
    }
/*
void out_inf_stud(info_stud *tmp)
{
    EMPT(tmp);
    printf("%25s %3s %5s %13s %15s\n", "Family N.P.", "sex", "group", "l.a. e.l. lab", "mat his dmt csc");

    for (;;)
    {
        printf("%20s %c.%c. %s  ", tmp->fnp.last_name, tmp->fnp.first_name, tmp->fnp.patronymic, (tmp->sex == F) ? "F" : "M");
        printf("%5d%4d %4d  %3d", tmp->group_num, tmp->mks.off.this_la, tmp->mks.off.this_el, tmp->mks.off.this_lab);
        printf(" %3d %3d %3d %3d\n", tmp->mks.ez.ma, tmp->mks.ez.hi, tmp->mks.ez.dm, tmp->mks.ez.cs);
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
*/

void out_inf_pc(info_pc *tmp)
{
    EMPT(tmp);
    printf("%20s %9s %8s %6s %8s %10s", "Family", "CPU count", "CPU type","memory" "GPU type", "GPU memory");
    printf("%8s %10s %9s %11s %11s %20s\n", "HDD type", "HDD memory", "HDD count", "dcs control", "blt control", "OC");
    for (;;)
    {
        printf("%20s %9d %8s %6d %8s %10d", tmp->last_name, tmp->proc.count, tmp->proc.type, tmp->memory, (tmp->video.typ == built_in)?"built_in":(tmp->video.typ == discrete)?"discrete":(tmp->video.typ == AGP)?"AGP":"PCI"),tmp->video.memory);
        printf("%5d%4d %4d  %3d", tmp->group_num, tmp->mks.off.this_la, tmp->mks.off.this_el, tmp->mks.off.this_lab);
        printf(" %3d %3d %3d %3d\n", tmp->mks.ez.ma, tmp->mks.ez.hi, tmp->mks.ez.dm, tmp->mks.ez.cs);
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