#include<stdio.h>

char change (char l, int w){
int k = ((int)l)-96;
return (char) ((k+w+3)%26+96);
}

int main (){
char letter;
int word = 0;
while (scanf ("%c", &letter) != EOF){
    if (letter == ' ' || letter == '\n' || letter == ',' || letter == '.') {
        printf ("%c", letter);
        word = 0;
    }
    else {
        word+=1;
        printf ("%c", change (letter, word));
    }
}
return 0;
} 