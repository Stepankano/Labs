#include <stdio.h>

int sign(int a)
{
	return (a < 0) ? -1 : 1;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int module(int a)
{
	return (a == 0) ? 0 : (a < 0) ? (-a) : a;
}

int mod(int a, int b)
{

	return ((a % b) < 0) ? ((a % b) + b) : (a % b);
}

int check(int a, int b)
{
	return (((a - 10) * (a - 10) + (b - 10) * (b - 10) >= 25) && ((a - 10) * (a - 10) + (b - 10) * (b - 10) <= 100)) ? 1 : 0;
}

int main()
{

	int i, j, l, k, z = 0;
	int new_i, new_j, new_l;
	printf("%s", "i j l: ");
	while (scanf("%d %d %d", &i, &j, &l) != EOF)
	{
		//int i = -1, j = -1, l = -9, k;
		z = 0;
		for (k = 1; k <= 50; k++)
		{
			new_i = mod(max(j - k, l - k), 30) + mod(max(i + l, j + k), 20);
			new_j = mod(module(i - l) * sign(j + k) + module(i - k) * (j + k), 20);
			new_l = mod((i + k) * (j - k) * (l + k), 25);
			if (check(new_i, new_j))
			{
				printf("%s %d %s", "Hit, time =", k, "\n\n");
				k = 55;
				z = 1;
			}

			i = new_i;
			j = new_j;
			l = new_l;
		}
		if (k == 51)
		{
			printf("%s %d %s %d %s %d %s %d %s", "Don`t hit, time =", 51, "\nx =", new_i, "\ny =", new_j, "\nDinamic parameter of moving =", new_l, "\n\n");
		}
	}
	return 0;
}
