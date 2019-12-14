#include<stdio.h>

int check (int a, int b){
    if (a == 0){ return (b%10);}
    for(int i = 0; i < a; i++){
        b = b/10;
    }
    return (b % 10);
}

int stepen (int a){
if(a == 0){return 1;}
if(a == 1){return 10;}
int k = 10;
for(int i = 2; i <= a; i++){
    k = k*10;
}
return k;
}

int add (int a, int mn){
    if (!check(a,mn)){
    mn = mn + stepen(a);
    } 
    
    return mn;
}

int main(){
    int key;
    char number;
    int mnoj_for_chek = 1111111111;
    int mnoj = 0;
    
        while ( scanf("%c", &number) != EOF ){
        
        
            if((int)number>=48 && (int)number<=57){
                mnoj = add((int)number-48, mnoj);
                key = 1;
            } 
            else{
                if(key == 1){
                    if((mnoj_for_chek - mnoj) != 0 ){ 
                        printf("%s\n", "true");
                        key = 0;
                        mnoj = 0;}

                    else{ 
                        printf("%s\n","false");
                        key = 0;
                        mnoj = 0;}
                }
            }
        
        }
    
    
    return 0;
}