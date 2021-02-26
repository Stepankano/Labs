#include <stdio.h>

int check(int a)
{
  while (a > 0)
  {
    if (a % 10 == 8 || a % 10 == 9)
    {
      return 0;
    }
    a = a / 10;
  }
  return 1;
}

int main()
{
  int min = 10;
  int max = 1000;
  int count = 0;
  for (int i = min; i <= max; i++)
  {
    if (check(i) == 1)
    {
      count += 1;
    }
  }
  printf("%d\n",count);
  return 0;
}