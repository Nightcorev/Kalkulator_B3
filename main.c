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
#include "header.h"

//Deklarasi Variabel Global
#define PHI 1.6180339887

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double hasil;
	char input_expresi[100];
	char kembali,temp;
	Queue ListQueue;
	node Node;
	
	do{
		system("cls");
		address root;
		ListQueue.First=NULL;
		ListQueue.Last=NULL;
		kembali='t';
		
		menu_kalkulator_scientifik();
		printf("\n\t\t\tMasukkan expresi: ");fflush(stdin);
    	scanf("%s", input_expresi);
    	fflush(stdin);
    	proses_kalkulator(&ListQueue,input_expresi,&kembali);
    	if(kembali=='t'){
			root = Create_Tree(ListQueue);
			hasil = proses_operasi(root);
			printf("\n\t\t\tHasil : %g",hasil);
			printf("\n\t\t\tKeluar (y/t) : ");fflush(stdin);
			scanf("%c",&kembali);	
		}else{
			printf("\t\t\tMATH ERROR");
			printf("\n\t\t\tKeluar (y/t) : ");fflush(stdin);
			scanf("%c",&kembali);	
		}
	}while(kembali == 'T' || kembali =='t');

	return 0;
}
