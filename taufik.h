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



double proses_operasi(address Troot){
	if(Troot->isOperator==1){
		if(Troot->data=='+'){
			return perjumlahan(proses_operasi(Troot->left), proses_operasi(Troot->right));
		}else if(Troot->data=='-'){
			return pengurangan(proses_operasi(Troot->left), proses_operasi(Troot->right));
		}else if(Troot->data=='/'){
			return pembagian(proses_operasi(Troot->left), proses_operasi(Troot->right));
		}else if(Troot->data=='*'){
			return perkalian(proses_operasi(Troot->left), proses_operasi(Troot->right));
		}else if(Troot->data=='^'){
			return perpangkatan(proses_operasi(Troot->left), proses_operasi(Troot->right));
		}else if(Troot->data=='&'){
			return hitung_akar(proses_operasi(Troot->left), proses_operasi(Troot->right)); 
		}else if(Troot->data=='m'){
			return modulus(proses_operasi(Troot->left), proses_operasi(Troot->right));
		}else if(Troot->data=='%'){
			return hitungPersentase(proses_operasi(Troot->left), proses_operasi(Troot->right));   
		}else{
			 printf("\n\t\t\tInvalid operator ");
		}
	}
	return Troot->operand;
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

void PushStack(Stack *First, char item, node *P){
	*P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{

		(*P)->oprtr=item;
		(*P)->isoperator=1;
		(*P)->next=NULL;
		if(First->Head==NULL){
			(*First).Head=*P;
			(*First).Head->next=NULL;	
		}else{
			(*P)->next=First->Head;
			First->Head=*P;
		}
	
	
	}
}

char PopStack(Stack *First){
	node P;
	P=First->Head;
	First->Head=P->next;
	return P->oprtr;
	free(P);
}


void proses_kalkulator(Queue *listQ, Stack *listS, char* input ){
	node P;
	char token,oprtr,negatif;
	int num3=10;
	int i,temp;
	float num=0,num2;
	float angka;
	int j;
	for(i=0;i<strlen(input);i++){
		token=input[i];
		if(isdigit(token)||token=='.'||(token=='-'&&(isOperator(input[i-1])||i==0||input[i-1]=='('))){
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
				EnqueOperand(&*listQ, num);
				num=0;
			}
		}else if (token=='s' || token=='c' || token=='t' || token=='a'){
			char trigono[7];
			char sudut[20];
			int x=0;
			j=0;
			float hasil;
			while(input[i]!=')'){
				if(isdigit(input[i]) || input[i]=='.'){
					sudut[j++]=input[i];
				} else{
					trigono[x++]=input[i];
				}
				i++;
			}
			sudut[j]='\0';
			angka=strtof(sudut, NULL);
			hasil=operasi_trigono(angka,trigono);
		
			EnqueOperand(&*listQ, hasil);	
		}else if(isOperator(token)&&listS->Head!=NULL&&listS->Head->oprtr!='('){
			oprtr=listS->Head->oprtr;
			while(derajatOperator(token)<=derajatOperator(oprtr)&&listS->Head!=NULL&&listS->Head->oprtr!='('){
				EnqueOperator(&*listQ,PopStack(&*listS));
			}
			PushStack(&*listS,token, &P);
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
		}else if(token == 'l'){
			char log[10];
			char Num[100];
			float angka;
			float a,hasil;
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
			PushStack(&*listS,token, &P);
		}else if(token=='!'){
			float a,c;
			char t;
			t=token;
			if(isdigit(input[i-1])){
				a=DequeOperand(&*listQ);
				c=faktorial(a);
				EnqueOperand(&*listQ,c);
				
			}else{
				printf("\t\t\tformat yang anda masukkan salah: ");
//				listQ->invalid=1;
			}
		}
		else{
			PushStack(&*listS,token, &P);
		}
	}
	while(listS->Head!=NULL){
		oprtr=PopStack(&*listS);
		EnqueOperator(&*listQ,oprtr);
	}
			
			
}
#endif
