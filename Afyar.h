#ifndef Afyar_h
#define Afyar_h

#include <math.h>


int perpangkatan (int x, int y);
double hitungPersentase(double angka, double persen);
double akarKuadrat(double x);


double perpangkatan (double x, double y);
double hitungPersentase(double angka, double persen);
double hitung_akar(double n, double a);
double hitung_phi(double input);

void PushStack(Stack *First, char item, node *P);
char PopStack(Stack *First);

double perpangkatan (double x, double y){
	double i, a;
	a=x;
	
	for (i=1; i<y; i++){
		a *= x;
	}
	return a;
}


double hitungPersentase(double angka, double persen) {
    return angka * (persen / 100);
}


double hitung_akar(double n, double a) {
   double hasil = pow(n, 1/a);
   return hasil;
}


double hitung_phi(double input){
return input*M_PI;
}


double hitung_phi(double input){
return input*M_PI;
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

#endif
