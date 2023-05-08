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
double proses_operasi(address Troot);
void proses_kalkulator(Queue *listQ, Stack *listS, char* input ); 

//Isi Program


void menu_kalkulator_scientifik(){
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

double proses_operasi(address Troot) {
	if(Troot->isOperator == 1){
		switch (Troot->data) {
	        case '^':
	            return perpangkatan(proses_operasi(Troot->left), proses_operasi(Troot->right));
	        case '*':
	            return perkalian(proses_operasi(Troot->left), proses_operasi(Troot->right));
	        case '/':
	            return pembagian(proses_operasi(Troot->left), proses_operasi(Troot->right));
	        case '+':
	            return perjumlahan(proses_operasi(Troot->left), proses_operasi(Troot->right));
	            return pengurangan(proses_operasi(Troot->left), proses_operasi(Troot->right));
	        case '%':
	        	return hitungPersentase(proses_operasi(Troot->left), proses_operasi(Troot->right));   
			case '&':
	        	return hitung_akar(proses_operasi(Troot->left), proses_operasi(Troot->right));      
			case 'm':
				return modulus(proses_operasi(Troot->left), proses_operasi(Troot->right));	
	        default:
	            printf("Invalid operator: ");
	            exit(1);
    	}
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
        default:
            printf("Invalid operator: %c", opr);
            exit(1);
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

void EnqueOperator(Queue *listQ,char item){
	node P;
	
	P=CreateNodeList();
	P->oprtr=item;
	if(listQ->First==NULL){
		listQ->First=P;
		listQ->Last=P;
		listQ->Last->next=NULL;
	} else{
		P->next=NULL;
		listQ->Last->next=P;
		listQ->Last=P;
	}
}

void EnqueOperand(Queue *Q,float item){
	node P;
	
	P=CreateNodeList();
	P->operand=item;
	P->isoperator=0;
	if(Q->First==NULL){
		Q->First=P;
		Q->Last=P;
		Q->Last->next=NULL;
	} else{
		P->next=NULL;
		Q->Last->next=P;
		Q->Last=P;
	}
}

void proses_kalkulator(Queue *listQ, Stack *listS, char* input ){
	node Node;
	char token,oprtr,negatif;
	int num3=10;
	int i,temp, j;
	double num=0,num2;
	double angka;

    		for (i = 0; strlen(input); i++) {
    			token = input[i];
		        if (isdigit(token) || token=='.'||(token=='-'&&(isOperator(input[i-1])||i==0||input[i-1]=='(')) ) {
		            if(isdigit(token)){
						num=num*10+(token-'0');
					}else if(token=='.'){
						i++;
						while(isdigit(input[i])){
							num2=(input[i]-'0');
							num=num+(num2/num3);	
							num3=num3*10;
							i++;
						}
						num3=10;
						i--;
					}else if(token=='-'){
						negatif='-';
					}
					 if(isdigit(input[i+1])!=1&&input[i+1]!='.'){
					 	if(negatif=='-'){
					 		num=num*-1;
						 }
						negatif='\0';
						EnqueOperand(&(*listQ), num);
						num=0;
					}
				
		        }else if(isOperator(token)&&listS->Head!=NULL&&listS->Head->oprtr!='('){
					oprtr = listS->Head->oprtr;
					while(cek_prioritas(token)<=cek_prioritas(oprtr)&&listS->Head!=NULL&&listS->Head->oprtr!='('){
						EnqueOperator(&*listQ,PopStack(&(*listS)));
					}
					PushStack(&(*listS),token, &Node);
				}else if(token==')'){
					oprtr=listS->Head->oprtr;
					while(oprtr!='('&&listS->Head->next!=NULL){
						EnqueOperator(&*listQ,PopStack(&*listS));
						oprtr=listS->Head->oprtr;
					}
					if(oprtr=='('){
						PopStack(&*listS);
					}else{
						printf("format yang dimasukkan salah\n");
						break;
					}
				}else if (input[i] == 'p') {
				    char NamaOprtr[20];
					char bil[20];
					int j=0,k=0;
					double  hasil;

					while(input[i] != ')'){
						 if (isdigit(input[i]) || input[i] == '.') {
		                	bil[j++] = input[i];
		            	}else{
		            		NamaOprtr[k++] = input[i++];
		            		
						}
					}
					bil[j] = '\0';
					angka = strtof(bil , NULL);
					hasil = proses_1operasi(angka,NamaOprtr);
					EnqueOperand(&(*listQ),hasil);
					
//					stack_number[++stack_number_top] = strtod(nomor,NULL);
//					bilangan = stack_number[stack_number_top];
//					stack_number[stack_number_top] = proses_1operasi(bilangan,operator_log);
				} else if(input[i] == 's' || input[i] == 'c' || input[i] == 't' ){
					char trigono[20];
					char sudut[20];
					int j=0,k=0;
					double  hasil;

					while(input[i] != ')'){
						 if (isdigit(input[i]) || input[i] == '.') {
		                	sudut[j++] = input[i];
		            	}else{
		            		trigono[k++] = input[i++];
		            		
						}
					}
					sudut[j] = '\0';
					angka = strtof(sudut , NULL);
					hasil = operasi_trigono(angka,trigono);
					EnqueOperand(&(*listQ),hasil);
					
//					stack_number[++stack_number_top] = strtod(number,NULL);
//					number1 = stack_number[stack_number_top];
//					stack_number[stack_number_top] = operasi_trigono(number1,trigono);
				}else if (input[i] == 'l'){
					char log[10];
					char Num[100];
					double angka;
					double a,hasil;
					int j = 0,x = 0;
					if(isdigit(input[i-1])){
						a=DequeOperand(&*listQ);
						while(input[i]!=')'){
							if(isdigit(input[i]) || input[i]=='.'){
								Num[j++]=input[i];
							} else{
								log[x++]=input[i];
							}
							i++;
						}
						Num[j]='\0';
						angka=strtof(Num, NULL);
						hasil=processLogarithm(angka,a,log);
						EnqueOperand(&*listQ, hasil);	
					}else{
						while(input[i]!=')'){
							if(isdigit(input[i]) || input[i]=='.'){
								Num[j++]=input[i];
							} else{
								log[x++]=input[i];
							}
							i++;
						}
						Num[j]='\0';
						angka=strtof(Num, NULL);
						hasil=processLogarithm(angka,10,log);
						EnqueOperand(&*listQ, hasil);	
					}	
				}else if(token=='('){
					PushStack(&*listS,token, &Node);
				}else {
		           PushStack(&*listS,token, &Node);
				}
			}
			while(listS->Head!=NULL){
				oprtr=PopStack(&*listS);
				EnqueOperator(&*listQ,oprtr);
			}
			
			
}
#endif
