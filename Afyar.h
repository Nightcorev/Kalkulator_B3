#ifndef Afyar_h
#define Afyar_h
#include <math.h>

double perpangkatan (double x, double y);
double hitungPersentase(double angka, double persen);
double akarKuadrat(double x);
double hitung_phi(double input);


double perpangkatan (double x, double y){
	double i, a;
	a=x;
	
	for (i=1; i<y; i++){
		a *= x;
	}
	return a;
}


double hitungPersentase(double angka, double persen) {
    return angka * (persen / 100);
}


double akarKuadrat(double x) {
  return sqrt(x);
}


double hitung_phi(double input){
return input*M_PI;
}

#endif
