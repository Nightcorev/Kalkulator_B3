#ifndef taufik_h
#define taufik_h
#include <stdio.h>
#include "kalkulator.h"

//Deklarasi Modul Tampilan
void menu_utama();
void menu_kalkulator_scientifik();
void menu_kalkulator_konversi();

//Isi Program
void menu_utama(){
	system("cls");
	printf("\n\n\n");
	printf("\n\t\t\t-------------------------------");
	printf("\n\t\t\t|       Selamat Datang        |");
	printf("\n\t\t\t|             Di              |");
	printf("\n\t\t\t|    Scientifik Kalkulator    |");
	printf("\n\t\t\t|         Kelompok B3         |");
	printf("\n\t\t\t|-----------------------------|");
	printf("\n\t\t\t|         Menu Utama          |");
	printf("\n\t\t\t|                             |");
	printf("\n\t\t\t-------------------------------");
	printf("\n\t\t\t| 1. Scientifik Kalkulator    |");
	printf("\n\t\t\t| 2. Kalkulator Konversi      |");
	printf("\n\t\t\t| 3. Keluar                   |");
	printf("\n\t\t\t|                             |");
	printf("\n\t\t\t-------------------------------");
}


void menu_kalkulator_scientifik(){
	system("cls");
	printf("\n\n\n");
	printf("\n\t\t\t------------------------------------------");
	printf("\n\t\t\t|    Scientifik Kalkulator               |");
	printf("\n\t\t\t|         Kelompok B3                    |");
	printf("\n\t\t\t|----------------------------------------|");
	printf("\n\t\t\t| Keterangan :                           |");
	printf("\n\t\t\t| (^) = untuk operasi perpangkatan       |");
	printf("\n\t\t\t------------------------------------------");
}

void menu_kalkulator_konversi(){
	system("cls");
	printf("\n\n\n");
	printf("\n\t\t\t-------------------------------");
	printf("\n\t\t\t|    Scientifik Kalkulator    |");
	printf("\n\t\t\t|         Kelompok B3         |");
	printf("\n\t\t\t|-----------------------------|");
	printf("\n\t\t\t|        Menu Konverai        |");
	printf("\n\t\t\t|                             |");
	printf("\n\t\t\t| 1. Konversi Jarak           |");
	printf("\n\t\t\t| 2. Konversi Suhu            |");
	printf("\n\t\t\t| 3. Konversi Waktu           |");
	printf("\n\t\t\t| 4. Kembali                  |");
	printf("\n\t\t\t|                             |");
	printf("\n\t\t\t-------------------------------");
}

void proses_kalkulator(){
		char input[100],temp_bil,opr[100];
	double nomor[100];
	int i,k,len,hasil,bil1,bil2;
	bool end = false;
	printf("Enter the expression: ");
	scanf("%s", input);
	len = strlen(input);
	i = 0;
   	while(i <= len){
   		temp_bil = input[i];
   		switch(temp_bil){
   			case '+' :
   				bil1 = input[i-1] - '0';
   				bil2 = input[i+1] - '0';
   				hasil = pertambahan(bil1,bil2);
   				break;
   			case '-' :
   				bil1 = input[i-1] - '0';
   				bil2 = input[i+1] - '0';
   				hasil = pengurangan(bil1,bil2);
   				break;
   			case '*' :
   				bil1 = input[i-1] - '0';
   				bil2 = input[i+1] - '0';
   				hasil = perkalian(bil1,bil2);
   				break;
   			case '/':
   				bil1 = input[i-1] - '0';
   				bil2 = input[i+1] - '0';
   				hasil = pembagian(bil1,bil2);
   				break;
   			case '^':
   				bil1 = input[i-1] - '0';
   				bil2 = input[i+1] - '0';
   				hasil = perpangkatan(bil1,bil2);
   			default:
   				break;
		   }   
		i++;
		
	}
	printf("%d\n",hasil);
	printf("Selesai!\n");
}

#endif
