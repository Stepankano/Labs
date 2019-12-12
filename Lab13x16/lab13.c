#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
/*
 1. считать мн-во согласных 1-го слова. записать в буфер
 2. считать мн-во согласных второго слова. сравнить с буфером. запомнить как буфер 
*/

#define consonants (1u << ('b'-'a') | 1u << ('c'-'a') | 1u << ('d'-'a') | 1u << ('f'-'a') | 1u << ('g'-'a') | 1u << ('h'-'a') | 1u << ('j'-'a') | 1u << ('k'-'a') | 1u << ('l'-'a') | 1u << ('m'-'a') | 1u << ('n'-'a') | 1u << ('p'-'a') | 1u << ('q'-'a') | 1u << ('r'-'a') | 1u << ('s'-'a') | 1u << ('t'-'a') | 1u << ('v'-'a') | 1u << ('w'-'a') | 1u << ('x'-'a') | 1u << ('y'-'a') | 1u << ('z'-'a'))

unsigned int char_to_set( char c){
    c = tolower(c);
    if(c < 'a' || c > 'z'){
        return 0;
    } else {
        
        return 1u << (c - 'a');
    }
}

typedef unsigned set_data_elem;
enum {
    bits_per_char = 8,
    bits_per_elem = sizeof(set_data_elem)*bits_per_char,
    datalen = (1 << bits_per_char) / bits_per_elem
};

typedef struct 
{
    set_data_elem data[datalen];
}set;

bool set_equal(const set *s1, const set *s2){
    for(int i = 0; i != datalen; ++i){
        if(s1 -> data[i] != s2 -> data[i]) return false;
    }
    return true;
}

int main(){
    char alpha;
    bool trigger = false;
    char c;
    unsigned int buffer = 0;
    unsigned int mainterance = 0;

    while ( scanf("%c", &c) != ' '){
        buffer = buffer | char_to_set(c);
        printf("%c", c);
    };
    while ( scanf("%c", &c) != EOF){
        mainterance = mainterance | char_to_set(c);
        printf("%d", 2);
        while ( scanf("%c", &c) != ' '){
            mainterance = mainterance | char_to_set(c);
        };
        printf("%d", 3);
        buffer = buffer & consonants;
        mainterance = mainterance & consonants;
        if(set_equal(&buffer, &mainterance)){
            printf("%s", "true");
            trigger = true;
        }
        buffer = mainterance;
        mainterance = 0;
        printf("%d", 4);
    };
    if(trigger){}
    else { printf("%s", "false");}
    return 0;
}