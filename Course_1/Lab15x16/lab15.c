#include <stdio.h>

 
int rank(int a){
    int k = 0;
   for(int i = 0; i < 8 ;i++){
       if(a - (k+1+2*i) == 0){
           return i+1;
       }
       k+=1+2*i;
   }

}

void swap (int* a, int* b){
   int t = *a;
   *a = *b;
   *b = t;

}

int main(){
    
    int matrix, rang, var, k = 0;
    int table [65];
    while ( scanf ( "%d", &matrix) != EOF){
        table[k+1]=matrix;
    k+=1;
    }
    
    rang = rank(k);
    k=1;
    for(int i = 0; i < rang; i++ ){
    swap((&table[(i*rang)+i+1]),&(table[rang*(i+1)-(i)]));
    for(int j = 1; j <= rang;j++){
        printf("%3d ", table[(i*rang) + j]);
        
    }
    printf("%c", '\n');
    }
    
   
return 0;
}