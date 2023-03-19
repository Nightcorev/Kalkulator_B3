#ifndef alfien_H
#define alfien_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*Logaritma*/
//rumus logaritma
double logarithm(double number, double base)
{
	return log(number)/log(base);
}

//process
double processLogarithm(double number, double base, char op[]){
	if(strcmp(op,"log(")==0){
		return logarithm(number,base);
	}else{
		printf("Operator is invalid: %c", op);
        exit(1);
	}
}

int process(){
	int a = 0, i = 0, num_top = 0, index_angka= -1, top_no = 0;
	char inputan[100], num[100], operator_log[100], nomor[100];
    double bilangan, bilangan2, angka[100];;
	
	printf("Masukkan ekspresi : "); scanf("%s", inputan);
	for (a=0; a<strlen(inputan); a++){
		if(isdigit(inputan[a])) {
	        while (isdigit(inputan[a]) || inputan[a] == '.') {
	            num[num_top++] = inputan[a++];
	        }
	  		num[num_top++]='\0';
	        angka[++index_angka] = strtod(num,NULL);
	    	a--;
		}
		else if (inputan[a] == 'l'){
			while(inputan[a]!=')'){
            	if(isdigit(inputan[a])||inputan[a]=='.'){
            		nomor[top_no++] = inputan[a++];
				}else {
				    operator_log[i++] = inputan[a++];
				    operator_log[100] = '\0';    
				}
				
			}
			nomor[top_no] = '\0';
			angka[++index_angka] = strtod(nomor, NULL);
			bilangan = angka[index_angka--];
			bilangan2 = angka[index_angka];
			angka[index_angka]=processLogarithm(bilangan,bilangan2,operator_log);
			
			printf("hasil: %lf\n", angka[0]);
	
			return 0;
		}
	}
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
//int main(int argc, char *argv[]) {
//	double angka = 0, base = 0, hasilLogaritma = 0, hasilLogaritmaNatural = 0;
//	int detik = 0;
//	char input[100];
//	struct Time waktu;
	
	//logartima	
	//process();
	
//	hasilLogaritmaNatural = naturalLogarithm(angka);
//	resultLogarithm(hasilLogaritmaNatural);
//	printf("\n");
	
	//konversi waktu
//	detik = inputKonversiWaktu();
//	waktu = processKonversiWaktu(detik);
//	resultKonversiWaktu(waktu);
//	return 0;
//}
#endif
