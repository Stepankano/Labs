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




void diagonal_up(int a, int k, int tab[]){
    int c;
    for ( int i = 1; i <= k-((k*k)-a); i++ ){
        printf("%d ", tab[k*k-(i-1)*(k+1)-(k*k-a)]);
    }
}

void diagonal_down(int a, int k, int tab[]){
    int c;
    for ( int i = 1; i <= k+1-a; i++ ){
        printf("%d ", tab[(i-1)*(k+1)+a]);
    }
}

int main(){
    
    int value, rang, var, k = 0;
    int table [65];
    while ( scanf ( "%d", &value) != EOF){
        table[k+1]=value;
    k+=1;
    
    }
    rang = rank(k);
    diagonal_up(k, rang, table);
    for( int i = 1; i < rang; i++){
        diagonal_down(1+i, rang, table);
        diagonal_up(k-i, rang, table);
    }
    
    return 0;
}