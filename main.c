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
	Stack ListStack;
	Queue ListQueue;
	node Node;
	
	
	do{
		system("cls");
		address root;
		ListQueue.First=NULL;
		ListQueue.Last=NULL;
		ListStack.Head=NULL;
		
		menu_kalkulator_scientifik(); //memanggil modul untuk menampilkan menu dari taufik.h
		printf("\n\t\t\tMasukkan expresi: ");fflush(stdin);
    	scanf("%s", input_expresi); // Menginputkan expresi yang akan diproses
		proses_kalkulator(&ListQueue,&ListStack,input_expresi);//Melakukan proes kalkulator yaitu proes infix to postfix dengan memanggil modul dari tufik.h
		root = Create_Tree(ListQueue); //Membuat tree dari listQueue yang sudah dibuat di proses_kalkulator dengan memanggil modul dari alfien.h
		hasil = proses_operasi(root); //Menghitung hasil akhir dari tree yang sudah dibuat dengan memanggil modul proes_operasi dari taufik.h
		printf("\n\t\t\tHasil : %g",hasil);
		printf("\n\t\t\tKeluar (y/t) : ");fflush(stdin);
		scanf("%c",&kembali);	
		}while(kembali == 'T' || kembali =='t');

	return 0;
}
