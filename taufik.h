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
void menu_kalkulator_scientifik();
double proses_1operasi(double bilangan1, char* opr);
double proses_operasi(double bilangan1, double bilangan2, char opr);
double proses_kalkulator(); 

//Isi Program


void menu_kalkulator_scientifik(){
	system("cls");
	printf("\n\t\t\t------------------------------------------------------");
	printf("\n\t\t\t|               Scientifik Kalkulator                |");
	printf("\n\t\t\t|                   Kelompok B3                      |");
	printf("\n\t\t\t|----------------------------------------------------|");
	printf("\n\t\t\t| Keterangan :                                       |");
	printf("\n\t\t\t| (^) = untuk operasi perpangkatan                   |");
	printf("\n\t\t\t| (p) = untuk operasi Phi                            |");
	printf("\n\t\t\t| (m) = untuk operasi modulus                        |");
	printf("\n\t\t\t| (&) = untuk operasi akar pangkat n                 |");
	printf("\n\t\t\t| (%%) = untuk operasi hitung persentase              |");
	printf("\n\t\t\t|                                                    |");
	printf("\n\t\t\t| Guide :                                            |");
	printf("\n\t\t\t| 1. Tidak menggunakan spasi                         |");
	printf("\n\t\t\t| 2. untuk operasi trigonometri                      |");
	printf("\n\t\t\t|    contohnya seperti berikut : cos(90)             |");
	printf("\n\t\t\t| 3. untuk operasi logaritma                         |");
	printf("\n\t\t\t|    contohnya seperti berikut : 2log(3)             |");
	printf("\n\t\t\t| 4. untuk operasi menghitung persentase             |");
	printf("\n\t\t\t|    cara menggunakannya seperti berikut : 20%%100=20%%|");
	printf("\n\t\t\t------------------------------------------------------");
}


double proses_1operasi(double bilangan1, char* opr){
	double result = 0;
	 if (strcmp(opr, "phi(") == 0) {
        result = hitung_phi(bilangan1);
    }else{
    	printf("Invalid operator: %c", opr);
            exit(1);
	}
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
        case '%':
        	return hitungPersentase(bilangan1, bilangan2);   
		case '&':
        	return hitung_akar(bilangan1,bilangan2);      
		case 'm':
			return modulus(bilangan1, bilangan2);	
        default:
            printf("Invalid operator: %c", opr);
            exit(1);
    }
}

int cek_prioritas(char opr) {
    switch (opr) {
        case '^':
        case '&':
        case 'p':
        case '%':
        case 'm':
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

double operasi_trigono(double bilangan1, char* trigono) {
    double result = 0;
    if (strcmp(trigono, "sin(") == 0) {
        result = sinHasil(bilangan1);
    }
    else if (strcmp(trigono, "cos(") == 0) {
        result =  cosHasil(bilangan1);
    }
    else if (strcmp(trigono, "tan(") == 0) {
        result =  tanHasil(bilangan1);
    }else if (strcmp(trigono, "cosec(") == 0) {
        result = cosecHasil(bilangan1);
    }
    else if (strcmp(trigono, "sec(") == 0) {
        result =  secHasil(bilangan1);
    }
    else if (strcmp(trigono, "cotan(") == 0) {
        result =  cotanHasil(bilangan1);
    }else{
    	return result;
	}
}
double operasi_logaritma(double bilangan1,double bilangan2, char* logaritma) {
    double result = 0;
    if (strcmp(logaritma, "nl(") == 0) {
        result = naturalLogarithm(bilangan2);
    }
    else if (strcmp(logaritma, "log(") == 0) {
        result =  logarithm(bilangan1,bilangan2);
    }else{
    	return result;
	}
}

double proses_kalkulator(){
	char input_expresi[100];
    double stack_number[100];
    int stack_number_top = -1;
    char stack_operator[100];
    int stack_operator_top = -1;
    int i;
			printf("\n\t\t\tMasukkan expresi: ");fflush(stdin);
    		scanf("%s", input_expresi);
    		for (i = 0; input_expresi[i]; i++) {
		        if (isdigit(input_expresi[i]) ) {
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
		        }else if (input_expresi[i] == 'p') {
				    int  j = 0, number_top = 0;
					char  operator_log[100], nomor[100];
				    double bilangan;
					while(input_expresi[i]!=')'){
		            	if(isdigit(input_expresi[i])||input_expresi[i]=='.'){
		            		nomor[number_top++] = input_expresi[i++];
						}else {
						    operator_log[j++] = input_expresi[i++];
						    operator_log[99] = '\0';    
						}
						
					}
					stack_number[++stack_number_top] = strtod(nomor,NULL);
					bilangan = stack_number[stack_number_top];
					stack_number[stack_number_top] = proses_1operasi(bilangan,operator_log);
				} else if(input_expresi[i] == 's' || input_expresi[i] == 'c' || input_expresi[i] == 't' ){
					char trigono[100];
					int j=0;
					char number[100];
					double number1;
					int number_top = 0;
					while(input_expresi[i] != ')'){
						 if (isdigit(input_expresi[i]) || input_expresi[i] == '.') {
		                	number[number_top++] = input_expresi[i++];
		            	}else{
		            		trigono[j++] = input_expresi[i++];
		            		trigono[99] = '\0';
						}
					}
					stack_number[++stack_number_top] = strtod(number,NULL);
					number1 = stack_number[stack_number_top];
					stack_number[stack_number_top] = operasi_trigono(number1,trigono);
				}else if (input_expresi[i] == 'l'){
					int  j = 0, number_top = 0, toInt = 0;
					char  operator_log[100], nomor[100];
				    double bilangan, bilangan2,temp;
					while(input_expresi[i]!=')'){
		            	if(isdigit(input_expresi[i])||input_expresi[i]=='.'){
		            		nomor[number_top++] = input_expresi[i++];
						}else {
						    operator_log[j++] = input_expresi[i++];
						    operator_log[99] = '\0';    
						}
						
					}
					stack_number[++stack_number_top] = strtod(nomor,NULL);
					bilangan = stack_number[stack_number_top];
					bilangan2 = stack_number[--stack_number_top];
					toInt = bilangan2;
					if(strcmp(operator_log,"log(")==0){
						if( toInt != 0){
							stack_number[stack_number_top] = processLogarithm(bilangan,bilangan2,operator_log);
						}else{
							stack_number[++stack_number_top] = processLogarithm(bilangan,10,operator_log);
						}
					}else{
						stack_number[++stack_number_top] = processLogarithm(bilangan,0,operator_log);
					}	
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
			return  stack_number[0];
			
}
#endif
