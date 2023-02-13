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

/*Konversi Waktu*/
//input
int inputKonversiWaktu()
{
	int detik = 0;
	printf("Masukkan detik : ");
	scanf("%d", &detik);
	return detik;
}

//proses
void processKonversiWaktu(int detik, int menit, int jam)
{
	jam = detik / (60 * 60);
    detik = detik - ((60 * 60) * jam);
    menit = detik / 60;
    detik = detik - (60 * menit);
}

//output
void resultKonversiWaktu(int detik, int menit, int jam)
{
	printf("Maka Waktunya Adalah : ");
    printf("\nJam : %d",jam);
    printf("\nMenit : %d",menit);
    printf("\nDetik : %d",detik);

#endif
