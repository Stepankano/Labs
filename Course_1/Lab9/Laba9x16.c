#include <stdio.h>

int max(int a, int b){
return (a > b)? a : b; 
}

int min(int a, int b){
return (a < b)? a : b; 
}

int module(int a){
return (a == 0)? 0 : ( a < 0 )? ( -a ) : a; 
}

int mod(int a, int b){

	return ((a % b)<0)? ((a % b) + b) : (a % b);
}

int check(int a, int b){
return((a <= -b-10) && (a >= -b-20))? 1 : 0; 
}

int main(){

	int i, j, l, k, z=0;
	int new_i, new_j, new_l;
	while(scanf("%d %d %d", &i, &j, &l) != EOF){
//int i = -30, j = -4, l = 12, k;
z=0;
		for (k = 1; k <= 50; k ++){
			new_i = module(i - l) + min(mod(j, 10),(l * mod(k, 10))) - 20; 
			new_j = mod(max((k - i), min(j, max(i - l, j - l))), 30); 
			new_l = mod((l * l), 20) - mod(max(i, j), (k + 1)); 
			if (check(new_i, new_j)) {
				printf ("%s %d %s", "Hit, time =", k, "\n\n");
				k=55;
				z=1;
			}

			i = new_i;
			j = new_j; 
			l = new_l;
		}
		 if (k==51)
		 {printf ("%s %d %s %d %s %d %s %d %s", "Don`t hit, time =", 51 ,"\nx =", new_i ,"\ny =", new_j , "\nDinamic parameter of moving =", new_l, "\n\n" );}
		
	}
return 0;
}

