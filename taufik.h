#ifndef taufik_h
#define taufik_h
#include <stdio.h>

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
	printf("\n\t\t\t-------------------------------");
	printf("\n\t\t\t|    Scientifik Kalkulator    |");
	printf("\n\t\t\t|         Kelompok B3         |");
	printf("\n\t\t\t|-----------------------------|");
	printf("\n\t\t\t|        Menu Scientifik      |");
	printf("\n\t\t\t|                             |");
	printf("\n\t\t\t| 1. Tambah & Kurang          |");
	printf("\n\t\t\t| 2. Logaritma                |");
	printf("\n\t\t\t| 3. Trigonometri             |");
	printf("\n\t\t\t| 4. Perpangkatan             |");
	printf("\n\t\t\t| 5. Kembali                  |");
	printf("\n\t\t\t|                             |");
	printf("\n\t\t\t-------------------------------");
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
	printf("\n\t\t\t| 2. Kembali                  |");
	printf("\n\t\t\t|                             |");
	printf("\n\t\t\t-------------------------------");
}
#endif
