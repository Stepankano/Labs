#include <stdio.h>
#include "data.h"

typedef struct meme
{

  enum pol
  {
    tutu,
    pepe
  } pol;
}meme;

int main()
{
meme ruks = {.pol = tutu};
printf("%s", (ruks.pol == tutu)?"tutu":"pepe"); 

  return 0;
}