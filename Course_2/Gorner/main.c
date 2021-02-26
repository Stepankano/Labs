/*
Стародубцев С.А.
М80-202Б-19
Вычисление полинома по схеме горнера (для 4 степени)
*/

#include <stdio.h>
#include <malloc.h>

int main()
{

    int coef = 0;
    int tmp_max = 100;

    char ch = '0';
    double arr[tmp_max];
    printf("Enter coefficient: ");

    while (ch != '\n')
    {

        scanf("%lf", &arr[coef]);
        coef += 1;
        ch = getchar();
    }

    double *new_arr = (double *)malloc(coef);

    double a;

    printf("Enter a:\n");
    scanf("%lf", &a);

    int pow = coef - 1;

    printf("Old: \n");

    for (int i = 0; i < coef - 1; i++)
    {
        if (arr[i] > 0.01 || arr[i] < -0.01)
        {
            //printf(" (x^%d) * %.2lf +", coef - 1 - i, arr[i]);

            if (arr[i] > 1.01 || arr[i] < -1.01)
            {
                printf(" (x^%d) * %.2lf +", coef - 1 - i, arr[i]);
            }
            else
            {
                printf(" (x^%d) +", coef - 1 - i);
            }
        }
    }

    printf(" %.2f\n", arr[coef - 1]);

    new_arr[0] = arr[0];

    for (int i = 1; i < coef; i++)
    {
        new_arr[i] = arr[i] + new_arr[i - 1] * a;
    }

    printf("New: \n");

    for (int i = 0; i < coef - 2; i++)
    {
        if (new_arr[i] > 0.01 || new_arr[i] < -0.01)
        {
            // printf(" (x^%d) * %.2lf +", coef - 1 - i, new_arr[i]);

            if (new_arr[i] > 1.01 || new_arr[i] < 0.99)
            {
                printf(" (x^%d) * %.2lf +", coef - 1 - i, new_arr[i]);
            }
            else
            {
                printf(" (x^%d) +", coef - 1 - i);
            }
        }
    }

    if (new_arr[coef - 2] > 0.01 || new_arr[coef - 2] < -0.01)
    {
        printf(" (%.2lf) * x", new_arr[coef - 2]);
    }

    printf("\nPower: %d", pow);
    return 0;
}
