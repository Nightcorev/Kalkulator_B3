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
double proses_operasi(address Troot);
void proses_kalkulator(Queue *listQ, char* input, char* kembali ); 

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
		}else if(Troot->data=='m'){
			return modulus(proses_operasi(Troot->left), proses_operasi(Troot->right));
		}else if(Troot->data=='%'){
			return hitungPersentase(proses_operasi(Troot->left), proses_operasi(Troot->right));   
		}else if(Troot->data=='v'){
			return hitung_akar(proses_operasi(Troot->right), proses_operasi(Troot->left));
		}else{
			 printf("\n\t\t\tInvalid operator ");
		}
	}
	return Troot->operand;
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

void proses_kalkulator(Queue *listQ, char* input, char* kembali){
	node P;
	Stack listS;
	char token,oprtr,negatif;
	int num3=10;
	int i,temp;
	double num=0,num2;
	double angka;
	int j;
	
	listS.Head=NULL;
	for(i=0;i<strlen(input);i++){
		token=input[i];
		if(isdigit(token)||token=='.'||(token=='-'&&(isOperator(input[i-1], &*kembali)||i==0||input[i-1]=='('))){
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
		}else if (token=='s' || token=='c' || token=='t'){
			char trigono[5];
			char sudut[20];
			int x=0;
			int j=0;
			float hasil;
			double angka1;
			if(!isdigit(input[i-1])){
				while(input[i]!=')'&&i<strlen(input)){
					if(isdigit(input[i]) || input[i]=='.'){
						sudut[j++]=input[i];
					} else{
						trigono[x++]=input[i];
					}
					i++;
				}
				if(input[i]!=')'){
					*kembali='y';
				}
				trigono[x]='\0';
				sudut[j]='\0';
				angka=strtod(sudut, NULL);
				hasil=operasi_trigono(angka,trigono,&*kembali);
				EnqueOperand(&*listQ, hasil);	
			}else{
				angka1=DequeOperand(&*listQ);
				while(input[i]!=')'){
					if(isdigit(input[i]) || input[i]=='.'){
						sudut[j++]=input[i];
					} else{
						trigono[x++]=input[i];
					}
					i++;
				}
				trigono[x]='\0';
				sudut[j]='\0';
				angka=strtod(sudut, NULL);
				hasil=operasi_trigono(angka,trigono,&*kembali);
				hasil*=angka1;
				EnqueOperand(&*listQ, hasil);
			}
		}else if(isOperator(token,&*kembali)&&listS.Head!=NULL&&listS.Head->oprtr!='('&&isdigit(input[i-1])){
			oprtr=listS.Head->oprtr;
			while(derajatOperator(token)<=derajatOperator(oprtr)&&listS.Head!=NULL&&listS.Head->oprtr!='('){
				EnqueOperator(&*listQ,PopStack(&listS));
			}
			listS=PushStack(listS,token);
		}else if(token==')'){
			oprtr=listS.Head->oprtr;
			while(oprtr!='('&&listS.Head->next!=NULL){
				EnqueOperator(&*listQ,PopStack(&listS));
				oprtr=listS.Head->oprtr;
			}
			if(oprtr=='('){
				PopStack(&listS);
			}else{
				printf("format yang dimasukkan salah\n");
				break;
			}
		}else if(token == 'l'){
			char numLog[20];
			int x=0;
			int j=0;
			double hasil;
			double angka1;
			if(isdigit(input[i-1])){
				angka1=DequeOperand(&*listQ);
				if((input[i+1]=='o')&&(input[i+2]=='g')&&(input[i+3]=='(')){
					i=i+4;
					while((input[i]!=')')&&(isdigit(input[i]))||(input[i]!=')')&&(input[i]=='.')){
						numLog[j++]=input[i];
						i++;
					}
					numLog[j]='\0';
					if(input[i]==')'){
						angka=strtof(numLog, NULL);
						hasil=logarithm(angka,angka1);
						EnqueOperand(&*listQ, hasil);
					}else{
						*kembali='y';
					}
				}else if((input[i+1]=='n')&&(input[i+2]=='(')){
					i=i+3;
					while((input[i]!=')')&&(isdigit(input[i]))||(input[i]!=')')&&(input[i]=='.')){
						numLog[j++]=input[i];
						i++;
					}
					numLog[j]='\0';
					if(input[i]==')'){
						angka=strtof(numLog, NULL);
						if(angka==0){
							*kembali='y';
						}else{
							hasil=naturalLogarithm(angka);
							hasil*=angka1;
							EnqueOperand(&*listQ, hasil);
						}
					}else{
						*kembali='y';
					}
				}
			}else{
				if((input[i+1]=='o')&&(input[i+2]=='g')&&(input[i+3]=='(')){
					i=i+4;
					while((input[i]!=')')&&(isdigit(input[i]))||(input[i]!=')')&&(input[i]=='.')){
						numLog[j++]=input[i];
						i++;
					}
					numLog[j]='\0';
					if(input[i]==')'){
						angka=strtof(numLog, NULL);
						hasil=logarithm(angka,10);
						EnqueOperand(&*listQ, hasil);
					}else{
						*kembali='y';
					}
				}else if((input[i+1]=='n')&&(input[i+2]=='(')){
					i=i+3;
					while((input[i]!=')')&&(isdigit(input[i]))||(input[i]!=')')&&(input[i]=='.')){
						numLog[j++]=input[i];
						i++;
					}
					numLog[j]='\0';
					if(input[i]==')'){
						angka=strtof(numLog, NULL);
						if(angka==0){
							*kembali='y';
						}else{
							hasil=naturalLogarithm(angka);
							EnqueOperand(&*listQ, hasil);
						}
					}else{
						*kembali='y';
					}
				}else{
					*kembali='y';
				}
			}
		}else if(token=='('){
			listS=PushStack(listS,token);
		}else if(token=='!'){
			float a,c;
			char t;
			t=token;
			if(isdigit(input[i-1])){
				a=DequeOperand(&*listQ);
				c=faktorial(a);
				EnqueOperand(&*listQ,c);
				
			}else{
				*kembali='y';
			}
		}
		else if(token=='v'&&!isdigit(input[i-1])){
			i++;
			float hasilakarkuadrat=0;
			int plus=0;
			char num[20];
			float num1;
			while(isdigit(input[i])||input[i]=='.'){
				num[plus++]=input[i];
				i++;
			}
			num1=strtof(num,NULL);
			hasilakarkuadrat=hitung_akar(num1,2);
			EnqueOperand(&*listQ,hasilakarkuadrat);
		}else{
			listS=PushStack(listS,token);
		}
	}
	while(listS.Head!=NULL){
		oprtr=PopStack(&listS);
		EnqueOperator(&*listQ,oprtr);
	}
}
#endif
