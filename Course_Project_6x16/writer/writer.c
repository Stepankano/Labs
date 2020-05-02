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
void writer(select_type stru)//select_type - тип вводимой переменной
{				 
    FILE *base = fopen("..\\database", "w+");//Открываем файл 
    if (!base)
    {
        perror("Can't open file");//Если не удалось открыть файл выводим ошибку и ломаем программу
	return;
    }
    //while(readselect_type(&stru))//пока есть что считывать
	    fwrite(&stru, sizeof(stru), 1, base);//записываем 
    fclose(base);
    return;
}
