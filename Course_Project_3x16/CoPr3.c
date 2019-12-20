#include <stdio.h>
#include <math.h>

const int k = 1;

double m_eps()
{
	double e = 1.0;
	while (1.0 + e / 2.0 > 1.0){
		e /= 2.0;
        
    }
	return e;
    
}

unsigned long long int factorial(int n){
    unsigned long long int l=n;
    for (int i = 1; i < n; i++){
        l*=(n-i);
    }
    return l;
}

 double row(float x){
    double result = 1, copy;
    for(int i = 2; i <= 100; i++){
        if((((2.0 * i + 1)/(factorial(i)))*pow(x,2*i)) > m_eps()){
            result += (((2.0 * i + 1)/(factorial(i)))*pow(x,2*i));
            }
        else{
            return result;
            }
    }
    
}

double system_answer(float x){
 return (1+2*x*x)*exp(x*x);

}

void print_n_times_border(int size) {
  printf("%.*s\n", size, "------------------------------------------------------------------------------");
}

void print_v(double x, double f, double f1, double r) {
  printf("| %5.2lf | %5.2lf | %5.2lf | %5.2lf |\n", x, f, f1, r);
  print_n_times_border(7 * 4 + 5);
}

int main(){
float piece = 0.1;
float now;
    print_n_times_border(33);
  for (int i = 0; i <= (int)(1/piece) ; i++) {
      now = piece * i;
    print_v(now, system_answer(now), row(now), system_answer(now)-row(now));
  }
  
  printf("Machine epsilone = %.11e\n", m_eps());
    return 0;
}