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
struct Time {
	int jam; int menit; int detik;
};

//input
int inputKonversiWaktu()
{
	int detik = 0;
	printf("Masukkan detik : ");
	scanf("%d", &detik);
	return detik;
}

//proses
struct Time processKonversiWaktu(int totalDetik)
{
	struct Time T;
  	T.jam = totalDetik / 3600;
  	T.menit = (totalDetik % 3600) / 60;
  	T.detik = (totalDetik % 3600) % 60;
  	return T;
}

//output
void resultKonversiWaktu(struct Time W)
{
	printf("Maka Waktunya Adalah : ");
    printf("\n%d jam, %d menit, %d detik",W.jam, W.menit, W.detik);
}

/*main*/
int main(int argc, char *argv[]) {
	double angka = 0, hasilLogaritma = 0, hasilLogaritmaNatural = 0;
	int detik = 0;
	struct Time waktu;
	
	//logartima
	angka = inputLogarithm();
	hasilLogaritma = logarithm(angka);
	resultLogarithm(hasilLogaritma);
	printf("\n");
	hasilLogaritmaNatural = naturalLogarithm(angka);
	resultLogarithm(hasilLogaritmaNatural);
	printf("\n");
	
	//konversi waktu
	detik = inputKonversiWaktu();
	waktu = processKonversiWaktu(detik);
	resultKonversiWaktu(waktu);
	return 0;
}

#endif
