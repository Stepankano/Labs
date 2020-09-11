#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../data.h"
#include "../writer/writer.h"
#include "../re_builder/re_builder.h"

void fill_student()
{
  int choice = 0;
  info_stud *tmp = NULL;
  while (choice != 2)
  {
    printf("%s\n", "Choose your option");
    printf("%s\n", "1) Add");
    printf("%s\n", "2) Exit");
    scanf("%d", &choice);
    if (choice == 1)
    {
      char sex;
      char offsets;
      if (!tmp)
      {
        Cret(tmp, info_stud);
        tmp->next = NULL;
        tmp->last = NULL;
      }
      else
      {
        Cret(tmp->next, info_stud);
        tmp->next->last = tmp;
        tmp = tmp->next;
        tmp->next = NULL;
      }
      printf("%s\n", "Please enter:");
      printf("%s", "Last name - ");
      scanf("%s", &tmp->fnp_stud.last_name);
      printf("%s", "First name (first letter) - ");
      scanf("%s", &tmp->fnp_stud.first_name);
      printf("%s", "Patronymic (first letter) - ");
      scanf("%s", &tmp->fnp_stud.patronymic);
      printf("%s", "Sex(F/M) - ");
      scanf("%s", &sex);
      tmp->sex_stud = (sex == 'F') ? F_stud : M_stud;
      printf("%s", "Group number - ");
      scanf("%d", &tmp->group_num);
      printf("%s", "Offset linear algebra(y/n) - ");
      scanf("%s", &offsets);
      tmp->mks.off.this_la = (offsets == 'y') ? la_yes : la_no;
      printf("%s", "English language(y/n) - ");
      scanf("%s", &offsets);
      tmp->mks.off.this_el = (offsets == 'y') ? el_yes : el_no;
      printf("%s", "L.A.B.S(y/n) - ");
      scanf("%s", &offsets);
      tmp->mks.off.this_lab = (offsets == 'y') ? lab_yes : lab_no;
      printf("%s", "Mark for mathematical analysis - ");
      scanf("%1d", &tmp->mks.ez.ma);
      printf("%s", "Mark for history - ");
      scanf("%1d", &tmp->mks.ez.hi);
      printf("%s", "Mark for discrete math - ");
      scanf("%1d", &tmp->mks.ez.dm);
      printf("%s", "Mark for computer science - ");
      scanf("%1d", &tmp->mks.ez.cs);
    }
    else if (choice != 2)
    {
      printf("%s", "Try again");
    }
    else
    {
      to_high(tmp);
      printf("%s\n", "Goodbye");
    }
  }
}

/*
void fill_pc()
{
  str(tmp_type);
  int choice = 0;
  info_pc *tmp = NULL;
  while (choice != 2)
  {
    printf("%s\n", "Choose your option");
    printf("%s\n", "1) Add");
    printf("%s\n", "2) Exit");
    scanf("%d", &choice);
    if (choice == 1)
    {
      char sex;
      char offsets;
      if (!tmp)
      {
        Cret(tmp, info_pc);
        tmp->next = NULL;
        tmp->last = NULL;
      }
      else
      {
        Cret(tmp->next, info_pc);
        tmp->next->last = tmp;
        tmp = tmp->next;
        tmp->next = NULL;
      }
      printf("%s\n", "Please enter:");
      printf("%s", "Last name - ");
      scanf("%s", &tmp->last_name);
      printf("%s", "Number of processors - ");
      scanf("%d", &tmp->proc.count);
      printf("%s", "Type of processors - ");
      scanf("%20s", &tmp->proc.type);
      printf("%s", "Memory - ");
      scanf("%d", &tmp->memory);
      printf("%s", "GPU type(built_in(b)/discrete(d)/AGP(a)/PCI(p)) - ");
      scanf("%s", &tmp_type);
      tmp->video.typ = (*tmp_type == 'b') ? built_in : (*tmp_type == 'd') ? discrete : (*tmp_type == 'a') ? AGP : PCI;
      printf("%s", "Video card memory(GB) - ");
      scanf("%3d", &tmp->video.memory);
      printf("%s", "HDD type(SCSI(s)/ATA(a)) - ");
      scanf("%s", &tmp_type);
      tmp->hdd.typ = (*tmp_type == 's') ? SCSI_IDE : ATA_SATA;
      printf("%s", "Winchester memory(GB) - ");
      scanf("%d", &tmp->hdd.memory);
      printf("%s", "Number of winchester - ");
      scanf("%d", &tmp->hdd.count);
      printf("%s", "Number of controller - ");
      scanf("%d", &tmp->ctrl.built_in);
      printf("%s", "Number of external devices - ");
      scanf("%d", &tmp->ctrl.discrete);
      printf("%s", "Operating system - ");
      scanf("%20s", &tmp->OC);
    }
    else if (choice != 2)
    {
      printf("%s", "Try again");
    }
    else
    {
      to_high(tmp);
      printf("%s\n", "Goodbye");
    }
  }
}
*/

/*
void fill_exam()
{
  char sex, medal, essay;
  int choice = 0;
  info_exam *tmp = NULL;
  while (choice != 2)
  {
    printf("%s\n", "Choose your option");
    printf("%s\n", "1) Add");
    printf("%s\n", "2) Exit");
    scanf("%d", &choice);
    if (choice == 1)
    {
      char sex;
      char offsets;
      if (!tmp)
      {
        Cret(tmp, info_exam);
        tmp->next = NULL;
        tmp->last = NULL;
      }
      else
      {
        Cret(tmp->next, info_exam);
        tmp->next->last = tmp;
        tmp = tmp->next;
        tmp->next = NULL;
      }
      printf("%s\n", "Please enter:");
      printf("%s", "Last name - ");
      scanf("%s", &tmp->fnp_exam.last_name);
      printf("%s", "First name - ");
      scanf("%s", &tmp->fnp_exam.first_name);
      printf("%s", "Patronymic - ");
      scanf("%s", &tmp->fnp_exam.patronymic);
      printf("%s", "Sex(F/M) - ");
      scanf("%s", &sex);
      tmp->sex_exam = (sex == 'F') ? F_exam : M_exam;
      printf("%s", "School number - ");
      scanf("%d", &tmp->school_number);
      printf("%s", "Medal(y/n) - ");
      scanf("%s", &medal);
      tmp->this_medal = (medal == 'y') ? yes_medal : no_medal;
      printf("%s", "Mark for math - ");
      scanf("%d", &tmp->mar_exam.math);
      printf("%s", "Mark for russian - ");
      scanf("%d", &tmp->mar_exam.rus);
      printf("%s", "Mark for informatics - ");
      scanf("%d", &tmp->mar_exam.inf);
      printf("%s", "Mark for physics - ");
      scanf("%d", &tmp->mar_exam.phis);
      printf("%s", "Essay(y/n) - ");
      scanf("%s", &essay);
      tmp->this_essay = (essay == 'y') ? yes_essay : no_essay;
    }
    else if (choice != 2)
    {
      printf("%s", "Try again");
    }
    else
    {
      to_high(tmp);
      printf("%s\n", "Goodbye");
    }
  }
}
*/

/*
void fill_passenger()
{
  char transit;
  int choice = 0;
  info_passenger *tmp = NULL;
  while (choice != 2)
  {
    printf("%s\n", "Choose your option");
    printf("%s\n", "1) Add");
    printf("%s\n", "2) Exit");
    scanf("%d", &choice);
    if (choice == 1)
    {
      char sex;
      char offsets;
      if (!tmp)
      {
        Cret(tmp, info_passenger);
        tmp->next = NULL;
        tmp->last = NULL;
      }
      else
      {
        Cret(tmp->next, info_passenger);
        tmp->next->last = tmp;
        tmp = tmp->next;
        tmp->next = NULL;
      }
      printf("%s\n", "Please enter:");
      printf("%s", "Last name - ");
      scanf("%s", &tmp->fnp_pass.last_name);
      printf("%s", "First name(first letter) - ");
      scanf("%s", &tmp->fnp_pass.first_name);
      printf("%s", "Patronymic(first letter) - ");
      scanf("%s", &tmp->fnp_pass.patronymic);
      printf("%s", "Number of bags - ");
      scanf("%d", &tmp->bags);
      printf("%s", "Bags weight - ");
      scanf("%d", &tmp->mass);
      printf("%s", "Transit(y/n) - ");
      scanf("%s", &transit);
      tmp->this_transit = (transit == 'y') ? yes_pass : no_pass;
      printf("%s", "Number of children - ");
      scanf("%d", &tmp->children_count);
    }
    else if (choice != 2)
    {
      printf("%s", "Try again");
    }
    else
    {
      to_high(tmp);
      printf("%s\n", "Goodbye");
    }
  }
}
*/
/*
void fill_school()
{
  char sex;
  int choice = 0;
  info_school *tmp = NULL;
  while (choice != 2)
  {
    printf("%s\n", "Choose your option");
    printf("%s\n", "1) Add");
    printf("%s\n", "2) Exit");
    scanf("%d", &choice);
    if (choice == 1)
    {
      char sex;
      char offsets;
      if (!tmp)
      {
        Cret(tmp, info_school);
        tmp->next = NULL;
        tmp->last = NULL;
      }
      else
      {
        Cret(tmp->next, info_school);
        tmp->next->last = tmp;
        tmp = tmp->next;
        tmp->next = NULL;
      }
      printf("%s\n", "Please enter:");
      printf("%s", "Last name - ");
      scanf("%s", &tmp->fnp_sch.last_name);
      printf("%s", "First name (first letter) - ");
      scanf("%s", &tmp->fnp_sch.first_name);
      printf("%s", "Patronymic (first letter) - ");
      scanf("%s", &tmp->fnp_sch.patronymic);
      printf("%s", "Sex(F/M) - ");
      scanf("%s", &sex);
      tmp->this_sex = (sex == 'F') ? F_sch : M_sch;
      printf("%s", "Class number - ");
      scanf("%d", &tmp->class_num);
      printf("%s", "Class letter - ");
      scanf("%s", &tmp->lit_class);
      printf("%s", "University - ");
      scanf("%20s", &tmp->University);
      printf("%s", "Work - ");
      scanf("%20s", &tmp->work);
      printf("%s", "Army - ");
      scanf("%20s", &tmp->army);
    }
    else if (choice != 2)
    {
      printf("%s", "Try again");
    }
    else
    {
      to_high(tmp);
      printf("%s\n", "Goodbye");
    }
  }
}
*/
int main()
{
  printf("%s\n", "Welcome!");
  select_type form;
  _Generic((form),
           info_stud
           : fill_student()/* ,
             info_exam
           : fill_exam(),
             info_passenger
           : fill_passenger(),
             info_pc
           : fill_pc(),
             info_school
           : fill_school()*/
  );

  return 0;
}