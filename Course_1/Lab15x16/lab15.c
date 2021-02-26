#include <stdio.h>

int main()
{

    int matrix, rang, min,max,row =0;
    int table[64];
    printf("rang: ");
    scanf("%d", &rang);
    for (int i = 0; i < rang * rang; i++)
    {
        scanf("%d", &table[i]);
        if (i == 0)
        {
            min = table[i];
            max = table[i];
        }
        else
        {
            if (min > table[i])
            {
                min = table[i];
            }
            if (max < table[i])
            {
                max = table[i];
            }
        }
    }
    for(int i =0;i<rang;i++){
        for(int j = 0;j<rang;j++){
            if(table[i+j*rang]==min){
                row+=1;
               j=rang;
            }
        }
    }

    for(int i = 0;i<rang*rang;i++){
        if(table[i]==max){
            table[i]=row;
        }
    }

    printf("\n");
    
    for(int i =0;i<rang;i++){
        for(int j = 0;j<rang;j++){
            printf("%d ",table[i*rang+j]);
        }
        printf("\n");
    }

    printf("%c", '\n');

    return 0;
}