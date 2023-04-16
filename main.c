#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "taufik.h"
#include "ikhsan.h"
#include "Afyar.h"
#include "alfien.h"
#include "Zia.h"
#include "Fikri.h"

//Deklarasi Variabel Global
#define PHI 1.6180339887

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double hasil;
	char kembali;
	
	do{
		
		menu_kalkulator_scientifik();
		hasil = proses_kalkulator();
		printf("\n\t\t\tHasil : %g",hasil);
		printf("\n\t\t\tKeluar (y/t) : ");fflush(stdin);
		scanf("%c",&kembali);	
		}while(kembali == 'T' || kembali =='t');

	return 0;
}
