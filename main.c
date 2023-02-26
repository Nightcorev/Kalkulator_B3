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
	double hasil;
	char kembali;
	
		
	for(;;){
		menu_utama();
		printf("\n\t\t\tPilih Menu : ");
		scanf("%d",&pilih_menu);
		
		switch(pilih_menu){
			case 1 :
				do{
				menu_kalkulator_scientifik();
				hasil = proses_kalkulator();
				printf("\n\t\t\tHasil : %g",hasil);
				printf("\n\t\t\tKembali (y/t) : ");fflush(stdin);
				scanf("%c",&kembali);	
				}while(kembali == 'T' || kembali =='t');
				break;
			case 2 :
				menu_kalkulator_konversi();
				printf("\n\t\t\tPilih Menu :");
				scanf("%d",&pilih_menu);
				switch(pilih_menu){
					case 1:
						do{
						system("cls");
						kalkulatorMeter();
						printf("\nKembali (y/t) : ");fflush(stdin);
						scanf("%c",&kembali);	
						}while(kembali == 'T' || kembali =='t');						
						break;
					case 2:
						do{
						system("cls");
						konversiSuhu();
						printf("\nKembali (y/t) : ");fflush(stdin);
						scanf("%c",&kembali);	
						}while(kembali == 'T' || kembali =='t');						
						break;
					case 3:
						do{
						system("cls");
						detik = inputKonversiWaktu();
						waktu = processKonversiWaktu(detik);
						resultKonversiWaktu(waktu);
						printf("\nKembali (y/t) : ");fflush(stdin);
						scanf("%c",&kembali);	
						}while(kembali == 'T' || kembali =='t');
						break;
					case 4:
						break;
					default:
						printf("\n\t\t\tSalah Input !!");
						Sleep(500);
						break;
					
					
				}
				break;
			case 3:
				return 0;
				break;
			default:
				printf("\n\t\t\tSalah Input !!");
				Sleep(500);
				break;
		}	
	}


	return 0;
}
