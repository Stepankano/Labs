#include <stdio.h>

int counter(char a){
  int number = 1;
  while( scanf ("%c", &a ) != EOF ){
    
    if( a == ' ' || a == '\n'){
      return number;
    } else {      
      number += 1;
    }
}
return number;
}

int main(){
  char key;
  int min = 0, number=999999999, junk;
  
  while( scanf ("%c", &key ) != EOF ){
    if( key == ' ' || key == '\n'){
    } else { 
           junk = counter(key);
      if (junk == number){
        min += 1;
      }
      if (junk < number){
        min = 1;
        number = junk;
      }
    }
  }
  printf("%d %d",min, number);
  return 0;
}