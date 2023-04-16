#ifndef alfien_H
#define alfien_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*Daftar modul*/
double logarithm(double number, double base);
double naturalLogarithm(double number);

//rumus logaritma
double logarithm(double number, double base)
{   
    return log(number)/log(base);
}

//rumus logaritma natural
double naturalLogarithm(double number)
{	
    return log(number);
}

double processLogarithm(double number, double base, char *op){
	int baseInt = base;
	double baseDouble = 10;
	
	if(strcmp(op,"log(")==0){
		return logarithm(number,base);
	}
	else if (strcmp(op,"ln(")==0){
		return naturalLogarithm(number);
	}
	else{
		printf("Operator is invalid: %s", op);
        exit(1);
	}
}
#endif
