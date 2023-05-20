#ifndef ikhsan_h
#define ikhsan_h
#include <stdio.h>
#include <stdlib.h>
#define phi 3.1415926535897931
#define limit 20

const float sudutSegitiga=180.0;
double sinHasil(double angleTrigonometri);
double cosHasil(double angleTrigonometri);
double tanHasil(double angleTrigonometri);
double cosecHasil(double angleTrigonometri);
double secHasil(double angleTrigonometri);
double cotanHasil(double angleTrigonometri);

double sinHasil(double angleTrigonometri)
{
	double sum;
	double fa;
	double pow;
	int i,j;
	sum = 0.0;
	
	angleTrigonometri=(angleTrigonometri*phi)/sudutSegitiga;
	
	for(i = 0; i <= limit; i++)
	{
		fa = 1.0;
		pow = 1.0;
		for(j = 1; j <= 2*i+1; j++)
		{
			fa *= j;
			pow *= angleTrigonometri;
		}
		sum += ((i%2?-1.0:1.0)/fa)*pow;
	}
	return sum;
}

double cosHasil(double angleTrigonometri)
{
	double sum;
	double fa;
	double pow;
	sum = 0.0;
	int i,j;
	
	angleTrigonometri=(angleTrigonometri*phi)/sudutSegitiga;
	
	for(i = 0; i <= limit; i++)
	{
		fa = 1.0;
		pow = 1.0;
		for(j = 1; j <= 2*i; j++)
		{
			fa *= j;
			pow *= angleTrigonometri;
		}
		sum += ((i%2?-1.0:1.0)/fa)*pow;
	}
	return sum;
}

double tanHasil(double angleTrigonometri){
	double result;
	
	result=sinHasil(angleTrigonometri)/cosHasil(angleTrigonometri);
	return result;
}

double cosecHasil(double angleTrigonometri){
	double result;
	
	result=1/sinHasil(angleTrigonometri);
	return result;
}

double secHasil(double angleTrigonometri){
	double result;
	
	result=1/cosHasil(angleTrigonometri);
	return result;
}

double cotanHasil(double angleTrigonometri){
	double result;
	
	result=1/tanHasil(angleTrigonometri);
	return result;
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
