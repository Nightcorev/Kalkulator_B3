#ifndef Afyar_h
#define Afyar_h
#include <math.h>

int perpangkatan (int x, int y);
float hitungPersentase(float angka, float persen);
double akarKuadrat(double x);
double hitung_phi(double input);


int perpangkatan (int x, int y){
	int i, a;
	a=x;
	
	for (i=1; i<y; i++){
		a *= x;
	}
	return a;
}


float hitungPersentase(float angka, float persen) {
    return angka * (persen / 100);
}


double akarKuadrat(double x) {
  return sqrt(x);
}


double hitung_phi(double input){
return input*M_PI;
}

#endif
