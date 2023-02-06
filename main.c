#include <stdio.h>
#include <stdlib.h>

#include "kalkulator.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int pilih_menu,input_angka1,input_angka2,hasil;
	double input_log, hasil_log;
	char pilih_kembali;
	
	menu_utama();
	printf("\n\t\t\tPilih Menu : ");
	scanf("%d",&pilih_menu);
	
	switch(pilih_menu){
		case 1 :
			menu_kalkulator_scientifik();
			printf("Pilih Menu : ");
			scanf("%d",&pilih_menu);
			switch(pilih_menu){
				case 1:
					
					
					printf("\n\t\t\tKembali (y/t) ?");
					scanf("%c",pilih_kembali); fflush(stdin);
					//gets(pilih_kembali);
					if(pilih_kembali == "y" || pilih_kembali == "Y"){
						menu_kalkulator_scientifik();
						break;
					}
				case 2: 
					system("cls");
					input_log = inputLogarithm();
					hasil_log = logarithm(input_log);
					resultLogarithm(hasil_log);
					printf("\n\t\t\tKembali (y/t) ?");
					scanf("%c",pilih_kembali); fflush(stdin);
					//gets(pilih_kembali);
					if(pilih_kembali == "y" || pilih_kembali == "Y"){
						menu_kalkulator_scientifik();
						break;
					}
				case 3:
					system("cls");
					trigonometri();
					printf("\n\t\t\tKembali (y/t) ?");
					scanf("%c",pilih_kembali); fflush(stdin);
					//gets(pilih_kembali);
					if(pilih_kembali == "y" || pilih_kembali == "Y"){
						menu_kalkulator_scientifik();
						break;
					}
				case 4:
					system("cls");
					scanf("%d %d",&input_angka1,&input_angka2);
					hasil = perpangkatan (input_angka1,input_angka2);
					printf("hasil : %d",hasil);
					printf("\n\t\t\tKembali (y/t) ?");
					scanf("%c",pilih_kembali); fflush(stdin);
					//gets(pilih_kembali);
					if(pilih_kembali == "y" || pilih_kembali == "Y"){
						menu_kalkulator_scientifik();
						break;
					}
				default:
					printf("\n\t\t\tSalah Input !!");
					menu_kalkulator_scientifik();
					break;
				
				
			}
		default:
			printf("\n\t\t\tSalah Input !!");
			menu_utama();
			break;
	}

	return 0;
}
