#ifndef ikhsan_h
#define ikhsan_h
#define phi 3.14159265
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const float sudutSegitiga=180.0;
double sinHasil(double angleTrigonometri);
double cosHasil(double angleTrigonometri);
double tanHasil(double angleTrigonometri);
double cosecHasil(double angleTrigonometri);
double secHasil(double angleTrigonometri);
double cotanHasil(double angleTrigonometri);


double sinHasil(double angleTrigonometri){
	double hasilSin;
	
	hasilSin=(angleTrigonometri*phi)/sudutSegitiga;
	hasilSin=sin(hasilSin);
	return hasilSin;
}

double cosHasil(double angleTrigonometri){
	double hasilCos;
	
	hasilCos=(angleTrigonometri*phi)/sudutSegitiga;
	hasilCos=cos(hasilCos);
	return hasilCos;
}

double tanHasil(double angleTrigonometri){
	double hasilTan;
	
	hasilTan=(angleTrigonometri*phi)/sudutSegitiga;
	hasilTan=tan(hasilTan);
	return hasilTan;
}

double cosecHasil(double angleTrigonometri){
	double hasilCosec;
	
	hasilCosec=1/sinHasil(angleTrigonometri);
	return hasilCosec;
}

double secHasil(double angleTrigonometri){
	double hasilSec;
	
	hasilSec=1/cosHasil(angleTrigonometri);
	return hasilSec;
}

double cotanHasil(double angleTrigonometri){
	double hasilCotan;
	
	hasilCotan=1/tanHasil(angleTrigonometri);
	return hasilCotan;
}

double DequeOperand(Queue *A){
	float q;
	node First,Last,Throw;
	First=A->First;
	Last=A->Last;
	if(First==NULL){
		printf("Queue Empty");
	}else{
		if(First!=Last){
			while(First->next!=Last){
				First=First->next;
			}
			Throw=Last;
			q=Last->operand;
			A->Last=First;
			A->Last->next=NULL;
			free(Throw);
			return q;
		}else{
			Throw=Last;
			q=Last->operand;
			A->Last=NULL;
			A->First=NULL;
			free(Throw);
			return q;
		}
		
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
#endif
