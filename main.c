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
	int pilih_menu;
	int detik = 0;
	struct Time waktu;
	char kembali;
	
	for(;;){
		menu_utama();
		printf("\n\t\t\tPilih Menu : ");
		scanf("%d",&pilih_menu);
		
		switch(pilih_menu){
			case 1 :
				menu_kalkulator_scientifik();
				proses_kalkulator();
				printf("\n\t\t\tKembali (y/t) : ");fflush(stdin);
				scanf("%c",&kembali);
				switch(kembali){
					case 'T':
					case 't':
						menu_kalkulator_scientifik();
						proses_kalkulator();
						break;
					default:
						break;					
				}
				break;
			case 2 :
				menu_kalkulator_konversi();
				printf("\n\t\t\tPilih Menu :");
				scanf("%d",&pilih_menu);
				switch(pilih_menu){
					case 1:
						system("cls");
						kalkulatorMeter();
						break;
					case 2:
						system("cls");
						konversiSuhu();
						break;
					case 3:
						detik = inputKonversiWaktu();
						waktu = processKonversiWaktu(detik);
						resultKonversiWaktu(waktu);
						break;
					case 4:
						menu_kalkulator_konversi();
						break;
					default:
						printf("\n\t\t\tSalah Input !!");
						menu_kalkulator_konversi();
						break;
					
					
				}
				break;
			case 3:
				return 0;
				break;
			default:
				printf("\n\t\t\tSalah Input !!");
				menu_utama();
				break;
		}	
	}


	return 0;
}
