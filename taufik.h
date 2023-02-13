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
	printf("\n\t\t\t| 2. Kembali                  |");
	printf("\n\t\t\t|                             |");
	printf("\n\t\t\t-------------------------------");
}

double perform_operation(double bilangan1, double bilangan2, char operator) {
    switch (operator) {
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
        default:
            printf("Invalid operator: %c", operator);
            exit(1);
    }
}

int get_priority(char operator) {
    switch (operator) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            printf("Invalid operator: %c", operator);
            exit(1);
    }
}

void proses_kalkulator(){
	char expression[100];
    double stack_num[100];
    int stack_num_top = -1;
    char stack_op[100];
    int stack_op_top = -1;
    int i;
			printf("\n\t\t\tMasukkan expresi: ");
    		scanf("%s", expression);
    		 for (i = 0; expression[i]; i++) {
	        if (isdigit(expression[i])) {
	            char number[100];
	            int number_top = 0;
	            while (isdigit(expression[i]) || expression[i] == '.') {
	                number[number_top++] = expression[i++];
	            }
	            number[number_top] = '\0';
	            stack_num[++stack_num_top] = strtod(number, NULL);
	            i--;
	        } else if (expression[i] == '(') {
	            stack_op[++stack_op_top] = expression[i];
	        } else if (expression[i] == ')') {
	            while (stack_op[stack_op_top] != '(') {
	                double num2 = stack_num[stack_num_top--];
	                double num1 = stack_num[stack_num_top--];
	                char operator = stack_op[stack_op_top--];
	                stack_num[++stack_num_top] = perform_operation(num1, num2, operator);
	            }
	            stack_op_top--;
	        } else {
	            while (stack_op_top >= 0 && get_priority(stack_op[stack_op_top]) >= get_priority(expression[i])) {
	                double num2 = stack_num[stack_num_top--];
	                double num1 = stack_num[stack_num_top--];
	                char operator = stack_op[stack_op_top--];
	                stack_num[++stack_num_top] = perform_operation(num1, num2, operator);
	            }
	            stack_op[++stack_op_top] = expression[i];
			}
			}
			while (stack_op_top >= 0) {
			    double num2 = stack_num[stack_num_top--];
			    double num1 = stack_num[stack_num_top--];
			    char operator = stack_op[stack_op_top--];
			    stack_num[++stack_num_top] = perform_operation(num1, num2, operator);
			}
		
			printf("\t\t\tResult: %g\n", stack_num[0]);
}
#endif
