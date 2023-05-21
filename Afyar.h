#ifndef Afyar_h
#define Afyar_h
#include <math.h>

double perpangkatan (double x, double y);
double hitungPersentase(double angka, double persen);
double hitung_akar(double n, double a);

Stack PushStack(Stack First, char item);
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


Stack PushStack(Stack First, char item){
	node P;
	P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{

		P->oprtr=item;
		P->isoperator=1;
		P->next=NULL;
		if(First.Head==NULL){
			First.Head=P;
			First.Head->next=NULL;	
		}else{
			P->next=First.Head;
			First.Head=P;
		}
	return First;
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
