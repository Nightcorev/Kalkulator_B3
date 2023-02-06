#ifndef alfien_H
#define alfien_H
#include <math.h>

//input
double inputLogarithm()
{	
	double angka = 0;
	printf("Masukkan angka : ");
	scanf("%lf", &angka);
	return angka;
}

//rumus logaritma
double logarithm(double number)
{
	return log10(number);
}

//rumus Logaritma Natural
double naturalLogarithm(double number)
{	
	return log(number);
}

//output logaritma
void resultLogarithm(double result)
{
	printf("Hasil : %lf", result);
}

#endif
