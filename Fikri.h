#ifndef Fikri_H
#define Fikri_H

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "header.h"

double faktorial(double n);
int derajatOperator(infotype oper);
int isOperator(infotype oper); 
double modulus(double a, double b);

int derajatOperator(infotype oper){
	if(oper=='+' || oper=='-'){
		return 1;
	} else if(oper=='*' || oper=='/'){
		return 2;
	} else if(oper=='^' || oper=='%' || oper=='m' || oper=='v'){
		return 3;
	} else{
		printf("Error, Operator Tidak Diketahui: %c", oper);
        exit(1);
	}
}

int isOperator(infotype oper){
	if(oper=='+' || oper=='-' || oper=='*' || oper=='/' || oper=='^' || oper=='%' || oper=='m' || oper=='v'){
		return 1;
	}
	return 0;
}

double faktorial(double n){
	double hasil=1;
	int i=1;
	
	while(i<=n){
		hasil=hasil*i;
		i++;
	}
	return hasil;
}
double modulus(double a, double b){
	double result;
	result= (int)a % (int)b;
	return result;
}
#endif
