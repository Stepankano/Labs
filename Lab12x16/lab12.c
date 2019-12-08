#include<stdio.h>


int main(){
char number;
int key;
char yuy [10];
char set [10] = {'0','1','2','3','4','5','6','7','8','9'};
for (int y = 0; y < 10; y ++){
    yuy[y] = set[y];
}


    while( scanf("%c", &number ) != EOF){
          if( number != '\n'){
            for ( int i = 0; i < 10 ; i ++){
                if ( number == yuy [i]){
                    yuy [i] = 'f';
                    
                }
            }


          }
          else{
              key = 0;
              for( int i = 0; i < 10; i ++){
                  
                  if (yuy [i] != 'f'){
                      printf("%s\n", "true");
                      i = 10;
                      key = 1;
                  }
              }
              if ( key == 0){
                  printf("%s\n", "false");
              }
            for (int y = 0; y < 10; y ++){
            yuy[y] = set[y];
            }
          }
          
    }
    return 0;
}