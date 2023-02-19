#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "kalkulator.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int pilih_menu;
	int detik = 0;
	struct Time waktu;
	char kembali;

	menu_utama();
	printf("\n\t\t\tPilih Menu : ");
	scanf("%d",&pilih_menu);
	
	switch(pilih_menu){
		case 1 :
			menu_kalkulator_scientifik();
			proses_kalkulator();
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
		default:
			printf("\n\t\t\tSalah Input !!");
			menu_utama();
			break;
	}

	return 0;
}
