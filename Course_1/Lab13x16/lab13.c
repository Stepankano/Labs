#include<stdio.h>
#include<ctype.h>

/*
 1. считать мн-во согласных 1-го слова. записать в буфер
 2. считать мн-во согласных второго слова. сравнить с буфером. запомнить как буфер 
*/



unsigned long long int check (unsigned long long int a, unsigned long long int b){
    if (a == 0){ return (b%10);}
    for(int i = 0; i < a; i++){
        b = b/10;
    }
    return (b % 10);
}

unsigned long long int stepen (int a){
if(a == 0){return 1;}
if(a == 1){return 10;}
unsigned long long int k = 10;
for(int i = 2; i <= a; i++){
    k = k*10;
}
return k;
}

unsigned long long int konq(unsigned long long int a, unsigned long long int b){
    unsigned long long int c = 0;

    for(int i =0 ; i <= 13; i++){
        if(( a % 10 == 1 ) && ( b % 10 == 1 )){
            c+=stepen(i);
        }
        a/=10;
        b/=10;
    }
    return c;
}

unsigned long long int add (unsigned long long int a, unsigned long long int mn){
    if (!check(a,mn)){
    mn = mn + stepen(a);
    } 
    
    return mn;
}


int main(){
    int key = 0;
    int enwrd = 0;
    char ltr;
    unsigned long long int mainterance1 = 0;
    unsigned long long int mainterance2 = 0;
    unsigned long long int consonants1 =  1111011101110; // 97-109
    unsigned long long int consonants2 = 1011101111101; //  110-122
    unsigned long long int buffer1 = 0;
    unsigned long long int buffer2 = 0;
        while(scanf("%c", &ltr) != EOF){
            ltr = (int)tolower(ltr)-97;
            if(ltr >= 0 && ltr <= 25){
                enwrd = 1;
                if(ltr >=0 && ltr <= 12){
                    mainterance1 = add(ltr,mainterance1);
                }
                if(ltr >=13 && ltr <= 25){
                    mainterance2 = add(ltr-13,mainterance2);
                }
                
                    
            } else {
                
                if(enwrd == 1){
                    enwrd = 0;
                    mainterance1 = konq(mainterance1, consonants1);
                    mainterance2 = konq(mainterance2, consonants2);
                    
                    if(key == 1){
                        if(konq(mainterance1, buffer1) == 0 && konq(mainterance2, buffer2) == 0){
                            printf("%s","true ");
                            return 0;
                        } else {
                            buffer1 = mainterance1;
                            buffer2 = mainterance2;
                            mainterance1 = 0;
                            mainterance2 = 0;
                        }
                    }
                    if(key == 0){
                        buffer1 = mainterance1;
                        buffer2 = mainterance2;
                        mainterance1 = 0;
                        mainterance2 = 0;
                        key = 1;
                    }
                }
            }
            
        }
        
                if(enwrd == 1){
                    enwrd = 0;
                    mainterance1 = konq(mainterance1, consonants1);
                    mainterance2 = konq(mainterance2, consonants2);
                    
                    if(key == 1){
                        if(konq(mainterance1, buffer1) == 0 && konq(mainterance2, buffer2) == 0){
                            printf("%s","true ");
                            return 0;
                        } else {
                            buffer1 = mainterance1;
                            buffer2 = mainterance2;
                            mainterance1 = 0;
                            mainterance2 = 0;
                        }
                    }
                    if(key == 0){
                        buffer1 = mainterance1;
                        buffer2 = mainterance2;
                        mainterance1 = 0;
                        mainterance2 = 0;
                        key = 1;
                    }
                }
        printf("%s\n", "false ");
    return 0;
}