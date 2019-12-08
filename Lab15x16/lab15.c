#include <stdio.h>

 struct cell{
int value, number;
struct cell *next, *last;
} ;
int rank(int a){
    int k = 0;
   for(int i = 0; i < 8 ;i++){
       if(a - (k+1+2*i) == 0){
           return i+1;
       }
       k+=1+2*i;
   }

}

int main(){
    int matrix; 
    struct cell *runner;
    int k = 0;
    int rang;
    while ( scanf ( "%d", &matrix) != EOF){
        if ( matrix != '\n' || matrix != ' '){
            printf("%d\n", matrix);
            k+=1;
            struct cell private;
            private.value = matrix;
            private.number = k;
            if ( k == 1){
                runner = &private;
            }
            else{
                (*runner).next = &private;
                private.last = &(*runner);
                runner = &private; 
            }
        }
    }
    rang = rank(k);

return 0;
}