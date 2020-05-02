#include <stdio.h>
#include <stdlib.h>
#include "../data.h"
#include "../writer/writer.h"

void fill_student(void)
{
  char sex;
  char offsets;
  info_stud form;
  printf("%s\n", "Please enter:");
  printf("%s", "Last name - ");
  scanf("%s", &form.fnp_stud.last_name);
  printf("%s", "First name (first letter) - ");
  scanf("%s", &form.fnp_stud.first_name);
  printf("%s", "Patronymic (first letter) - ");
  scanf("%s", &form.fnp_stud.patronymic);
  printf("%s", "Sex(F/M) - ");
  scanf("%s", &sex);
  form.sex_stud = (sex == 'F') ? F_stud : M_stud;
  printf("%s", "Group number - ");
  scanf("%d", &form.group_num);
  printf("%s", "Offset linear algebra(y/n) - ");
  scanf("%c", &offsets);
  form.mks.off.this_la = (offsets == 'y') ? la_yes : la_no;
  printf("%s", "English language(y/n) - ");
  scanf("%c", &offsets);
  form.mks.off.this_el = (offsets == 'y') ? el_yes : el_no;
  printf("%s", "L.A.B.S(y/n) - ");
  scanf("%c", &offsets);
  form.mks.off.this_lab = (offsets == 'y') ? lab_yes : lab_no;
  printf("%s", "Mark for mathematical analysis - ");
  scanf("%1d", &form.mks.ez.ma);
  printf("%s", "Mark for history - ");
  scanf("%1d", &form.mks.ez.hi);
  printf("%s", "Mark for discrete math - ");
  scanf("%1d", &form.mks.ez.dm);
  printf("%s", "Mark for computer science - ");
  scanf("%1d", &form.mks.ez.dm);
  form.next = NULL;
  form.last = NULL;
  //writer(form);
}

void fill_pc(void)
{
  str(tmp_type);
  info_pc form;
  printf("%s\n", "Please enter:");
  printf("%s", "Last name - ");
  scanf("%s", &form.last_name);
  printf("%s", "Number of processors - ");
  scanf("%d", &form.proc.count);
  printf("%s", "Type of processors - ");
  scanf("%20s", &form.proc.type);
  printf("%s", "Memory - ");
  scanf("%d", &form.memory);
  printf("%s", "GPU type(built_in/discrete/AGP/PCI) - ");
  scanf("%s", &tmp_type);
  form.video.typ = (tmp_type == "built_in") ? built_in : (tmp_type == "discrete") ? discrete : (tmp_type == "AGP") ? AGP : PCI;
  printf("%s", "Video card memory(GB) - ");
  scanf("%3d", &form.video.memory);
  printf("%s", "HDD type(SCSI/ATA) - ");
  scanf("%s", &tmp_type);
  form.hdd.typ = (tmp_type == "SCSI") ? SCSI_IDE : ATA_SATA;
  printf("%s", "Winchester memory(GB) - ");
  scanf("%d", &form.hdd.memory);
  printf("%s", "Number of winchester - ");
  scanf("%d", &form.hdd.count);
  printf("%s", "Number of controller - ");
  scanf("%d", &form.ctrl.built_in);
  printf("%s", "Number of external devices - ");
  scanf("%d", &form.ctrl.discrete);
  printf("%s", "Operating system - ");
  scanf("%20s", &form.OC);
  form.next = NULL;
  form.last = NULL;
  
  //writer(form);
}

void fill_exam(void)
{
  char sex, medal, essay;
  info_exam form;
  printf("%s\n", "Please enter:");
  printf("%s", "Last name - ");
  scanf("%s", &form.fnp_exam.last_name);
  printf("%s", "First name - ");
  scanf("%s", &form.fnp_exam.first_name);
  printf("%s", "Patronymic - ");
  scanf("%s", &form.fnp_exam.patronymic);
  printf("%s", "Sex(F/M) - ");
  scanf("%s", &sex);
  form.sex_exam = (sex == 'F') ? F_exam : M_exam;
  printf("%s", "School number - ");
  scanf("%d", &form.school_number);
  printf("%s", "Medal(y/n) - ");
  scanf("%s", &medal);
  form.this_medal = (medal == 'y') ? yes_medal : no_medal;
  printf("%s", "Mark for math - ");
  scanf("%d", &form.mar_exam.math);
  printf("%s", "Mark for russian - ");
  scanf("%d", &form.mar_exam.rus);
  printf("%s", "Mark for informatics - ");
  scanf("%d", &form.mar_exam.inf);
  printf("%s", "Mark for physics - ");
  scanf("%d", &form.mar_exam.phis);
  printf("%s", "Essay(y/n) - ");
  scanf("%s", &essay);
  form.this_essay = (essay == 'y') ? yes_essay : no_essay;
  form.next = NULL;
  form.last = NULL;
  //writer(form);
}

void fill_passenger(void)
{
  char transit;
  info_passenger form;
  printf("%s\n", "Please enter:");
  printf("%s", "Last name - ");
  scanf("%s", &form.fnp_pass.last_name);
  printf("%s", "First name(first letter) - ");
  scanf("%s", &form.fnp_pass.first_name);
  printf("%s", "Patronymic(first letter) - ");
  scanf("%s", &form.fnp_pass.patronymic);
  printf("%s", "Number of bags - ");
  scanf("%d", &form.bags);
  printf("%s", "Bags weight - ");
  scanf("%d", &form.mass);
  printf("%s", "Transit(y/n) - ");
  scanf("%s", &transit);
  form.this_transit = (transit == 'y') ? yes_pass : no_pass;
  printf("%s", "Number of children - ");
  scanf("%d", &form.children_count);
  form.next = NULL;
  form.last = NULL;
  //writer(form);
}

void fill_school(void)
{
  char sex;
  info_school form;
  printf("%s\n", "Please enter:");
  printf("%s", "Last name - ");
  scanf("%s", &form.fnp_sch.last_name);
  printf("%s", "First name (first letter) - ");
  scanf("%s", &form.fnp_sch.first_name);
  printf("%s", "Patronymic (first letter) - ");
  scanf("%s", &form.fnp_sch.patronymic);
  printf("%s", "Sex(F/M) - ");
  scanf("%s", &sex);
  form.this_sex = (sex == 'F') ? F_sch : M_sch;
  printf("%s", "Class number - ");
  scanf("%d", &form.class_num);
  printf("%s", "Class letter - ");
  scanf("%s", &form.lit_class);
  printf("%s", "University - ");
  scanf("%20s", &form.University);
  printf("%s", "Work - ");
  scanf("%20s", &form.work);
  printf("%s", "Army - ");
  scanf("%20s", &form.army);
  form.next = NULL;
  form.last = NULL;
  //writer(form);
}

int main()
{
  printf("%s\n", "Welcome!");
  select_type form;
  int choice = 0;
  while (choice != 2)
  {
    printf("%s\n", "Choose your option");
    printf("%s\n", "1) Add");
    printf("%s\n", "2) Exit");
    scanf("%d", &choice);
    if (choice == 1)
    {
      _Generic((form), // oaoammm polymorfizm)))
               info_stud
               : fill_student(),
                 info_pc
               : fill_pc(),
                 info_exam
               : fill_exam(),
                 info_passenger
               : fill_passenger(),
                 info_school
               : fill_school());
    }
    else if (choice != 2)
    {
      printf("%s", "Try again");
    }
    else
    {
      printf("%s\n", "Goodbye");
    }
  }

  return 0;
}