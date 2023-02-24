#ifndef taufik_h
#define taufik_h
#include <stdio.h>
#include "ikhsan.h"
#include "Afyar.h"
#include "alfien.h"
#include "Zia.h"
#include "Fikri.h"
#define PHI 1.6180339887

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
	printf("\n");
	printf("\n\t\t\t------------------------------------------------------");
	printf("\n\t\t\t|               Scientifik Kalkulator                |");
	printf("\n\t\t\t|                   Kelompok B3                      |");
	printf("\n\t\t\t|----------------------------------------------------|");
	printf("\n\t\t\t| Keterangan :                                       |");
	printf("\n\t\t\t| (^) = untuk operasi perpangkatan                   |");
	printf("\n\t\t\t| (s) = untuk operasi sinus                          |");
	printf("\n\t\t\t| (c) = untuk operasi cosinus                        |");
	printf("\n\t\t\t| (t) = untuk operasi tangen                         |");
	printf("\n\t\t\t| (l) = untuk operasi logaritma                      |");
	printf("\n\t\t\t| (nl) = untuk operasi natural logaritma             |");
	printf("\n\t\t\t| (%%) = untuk operasi hitung persentase              |");
	printf("\n\t\t\t|                                                    |");
	printf("\n\t\t\t| Guide :                                            |");
	printf("\n\t\t\t| 1. Tidak menggunakan spasi                         |");
	printf("\n\t\t\t| 2. untuk operasi 1 bilangan seperti menghitung cos |");
	printf("\n\t\t\t|    cara menggunakannya seperti berikut : 90c       |");
	printf("\n\t\t\t| 3. untuk operasi 2 bilangan pada menghitung cos dll|");
	printf("\n\t\t\t|    cara menggunakannya seperti berikut : 90c1+2-1  |");
	printf("\n\t\t\t|    *angka 1 digunakan sebagai bilangan pembantu    |");
	printf("\n\t\t\t| 4. untuk operasi menghitung persentase             |");
	printf("\n\t\t\t|    cara menggunakannya seperti berikut : 20%%100=20%%|");
	printf("\n\t\t\t------------------------------------------------------");
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

double proses_operasi(double bilangan1, double bilangan2, char opr) {
    switch (opr) {
        case '^':
            return perpangkatan(bilangan1, bilangan2);
        case '*':
            return perkalian(bilangan1,bilangan2);
        case '/':
            return pembagian(bilangan1,bilangan2);
        case '+':
            return perjumlahan(bilangan1,bilangan2);
        case '-':
            return pengurangan(bilangan1,bilangan2);
        case 's':
        	return sinHasil(bilangan1);
        case 't':
        	return tanHasil(bilangan1);
        case 'c':
        	return cosHasil(bilangan1);
        case 'l':
        	return logarithm(bilangan1);
        case 'n':
        	return naturalLogarithm(bilangan1); 
        case '&':
        	return akarKuadrat(bilangan1);
        case '%':
        	return hitungPersentase(bilangan1, bilangan2);        	
        case 'p':
        	return bilangan1*PHI;
        default:
            printf("Invalid operator: %c", opr);
            exit(1);
    }
}

int cek_prioritas(char opr) {
    switch (opr) {
        case '^':
        case 's':
        case 't':
        case 'c':
        case 'l':
        case 'n':
        case '&':
        case 'p':
        case '%':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
        case ')':
        	return 0;
        default:
            printf("Invalid operator: %c", opr);
            exit(1);
    }
}

void proses_kalkulator(){
	char input_expresi[100];
    double stack_number[100];
    int stack_number_top = -1;
    char stack_operator[100];
    int stack_operator_top = -1;
    int i;
			printf("\n\t\t\tMasukkan expresi: ");
    		scanf("%s", input_expresi);
    		for (i = 0; input_expresi[i]; i++) {
		        if (isdigit(input_expresi[i])) {
		            char number[100];
		            int number_top = 0;
		            while (isdigit(input_expresi[i]) || input_expresi[i] == '.') {
		                number[number_top++] = input_expresi[i++];
		            }
		            number[number_top] = '\0';
		            stack_number[++stack_number_top] = strtod(number, NULL);
		            i--;
		        } else if (input_expresi[i] == '(') {
		            stack_operator[++stack_operator_top] = input_expresi[i];
		        } else if (input_expresi[i] == ')') {
		            while (stack_operator[stack_operator_top] != '(') {
		                double number2 = stack_number[stack_number_top--];
		                double number1 = stack_number[stack_number_top--];
		                char operator = stack_operator[stack_operator_top--];
		                stack_number[++stack_number_top] = proses_operasi(number1, number2, operator);
		            }
		            stack_operator_top--;
		        }else if (input_expresi[i] == 's' || input_expresi[i] == 'c' || input_expresi[i] == 't' || input_expresi[i] == 'l' || input_expresi[i] == 'n' || input_expresi[i] == '&') {
				    i++;
				    char operator = input_expresi[i - 1];
				    double number1 = stack_number[stack_number_top--];
				    stack_number[++stack_number_top] = proses_operasi(number1, 0, operator);
				} 
				else {
		            while (stack_operator_top >= 0 && cek_prioritas(stack_operator[stack_operator_top]) >= cek_prioritas(input_expresi[i])) {
		                double number2 = stack_number[stack_number_top--];
		                double number1 = stack_number[stack_number_top--];
		                char operator = stack_operator[stack_operator_top--];
		                stack_number[++stack_number_top] = proses_operasi(number1, number2, operator);
		            }
		            stack_operator[++stack_operator_top] = input_expresi[i];
				}
			}
			while (stack_operator_top >= 0) {
			    double number2 = stack_number[stack_number_top--];
			    double number1 = stack_number[stack_number_top--];
			    char operator = stack_operator[stack_operator_top--];
			    stack_number[++stack_number_top] = proses_operasi(number1, number2, operator);
			}
		
			printf("\t\t\tHasil: %g\n", stack_number[0]);
			Sleep(500);
			
}
#endif
