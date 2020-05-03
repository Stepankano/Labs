#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../data.h"
/*
void writer(info_stud inf)//info_stud - тип вводимой переменной
{
    FILE *base = fopen(argv[1], "w");
    if (!base)
    {
        perror("Can't open file");
        return;
    }
    while(readinfo_stud_FNP(&inf))
            fwrite(&inf, sizeof(inf), 1, base);
    fclose(base);
}
*/
void writer(select_type *stru) //select_type - тип вводимой переменной
{
    if(!stru){
        perror("Database is empty"); 
        return;
    }
    FILE *base = fopen(__NAME__, "w"); //Открываем файл
    if (!base)
    {
        perror("Can't open file"); //Если не удалось открыть файл выводим ошибку и ломаем программу
        return;
    }

    while (stru->next)
    { //пока есть что считывать
        fwrite(stru, sizeof(stru), 1, base);
        printf("%s\n",stru->fnp_stud.last_name);
        stru = stru->next;
        
    }
    fwrite(stru, sizeof(stru), 1, base);
    printf("%s\n",stru->fnp_stud.last_name);
    fclose(base);
    return;
}
