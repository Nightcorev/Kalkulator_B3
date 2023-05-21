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
	/* Deklarasi variabel dan struct yang akan digunakan */
	double hasil;
	char input_expresi[255];
	char kembali,temp;
	Queue ListQueue;
	node Node;
	
	do{ //Melakukan looping selama kembali bernilai t atau T
		system("cls");
		address root;
		ListQueue.First=NULL;
		ListQueue.Last=NULL;
		kembali='t';
		
		menu_kalkulator_scientifik(); // Menampilkan menu kalkulator yang diambil dari taufik.h
		printf("\n\t\t\tMasukkan expresi: ");fflush(stdin);
    	scanf("%s", input_expresi); // Menginputkan expresi yang di simpan di input_expresi
    	fflush(stdin);
    	proses_kalkulator(&ListQueue,input_expresi,&kembali); // Melakukan proes infix to postfix yang akan disimpan di list Queue dari taufik.h
    	if(kembali=='t'){ // Mengecek apakah kembali bernilai t
			root = Create_Tree(ListQueue); // membuat tree berdasarkan list Queue dari alfien.h
			hasil = proses_operasi(root); // menghitung atau melakukan operasi sesuai dengan yang ada di tree yang disimpan di hasil dari taufik.h
			printf("\n\t\t\tHasil : %g",hasil); // menampilkan hasil yang telah dioperasikan
			printf("\n\t\t\tKeluar (y/t) : ");fflush(stdin);
			scanf("%c",&kembali);	// memilih akan keluar atau mengulang kalkulator
		}else{ 
			// jika bukan maka akan menampilkan Math error dan dapat memilih akan keluar atau tidak
			printf("\t\t\tMATH ERROR");
			printf("\n\t\t\tKeluar (y/t) : ");fflush(stdin);
			scanf("%c",&kembali);	
		}
	}while(kembali == 'T' || kembali =='t');

	return 0;
}
