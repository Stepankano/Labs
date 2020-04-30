#include <stdio.h>
#include "data.h"

#define afk(b) b *b;

int main()
{ int b =5 ;
  if (b > 0)
  {
#define afk(b) b *b
  } else{
    #define afk(b) b*7
  }
printf("%d", afk(b));
  return 0;
}