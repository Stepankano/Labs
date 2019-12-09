#include <stdio.h>

/*int dvoich (int a){
    int ost = 3, result=0;
    while (a >= 2){
        ost = a % 2;
        result = result*10 + ost;
        a = a / 2;
    }
    return ((a > 0) ? (a) : (a + 10^7));
    }
*/

int main (){
    int number;
    scanf ("%d", number);
    printf ("%d", (dvoich(number)));
    return 0;
}
