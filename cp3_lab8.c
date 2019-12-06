#include<stdio.h>

int Factorial( int a ){
return ( a == 0 )? 0 : ( a == 1)? 1 : ( a + Factorial ( a - 1 ));
}

int main(){
	int number;
	while( scanf ("%d", &number) != EOF){
   		printf("%d\n", Factorial( number ));
	}


return 0;
}
