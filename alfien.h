#ifndef alfien_H
#define alfien_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "header.h"
#include "Zia.h"

/*Daftar modul*/
double logarithm(double number, double base);
double naturalLogarithm(double number);
double processLogarithm(double number, double base, char *op);
node CreateNodeList();
address Create_Tree(Queue Z);

//rumus logaritma
double logarithm(double number, double base)
{ 
	double  divResult = number;
    double result;

    if (number <= 0 || base <= 0) { /*jika number atau base kurang sama dengan 0*/
        result = 0;
    }else if (base == number) {	/*jika number sama dengan base*/
        result = 1;
    }else {
       	for (result = 0; divResult >= base; result++) { /*looping berjalan selama divResult lebih besar sama dengan base*/
            divResult = divResult/base;
        }
        if (divResult != 1) { /*jika divResult dari hasil looping tidak sama dengan 1*/
            result = result+(divResult/base);
        }
    }

    return result;
}

//rumus logaritma natural
double naturalLogarithm(double number)
{	
	/*referensi https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having*/
    double old_sum = 0.0;
    double xmlxpl = (number - 1) / (number + 1);
    double xmlxpl_2 = xmlxpl * xmlxpl;
    double denom = 1.0;
    double frac = xmlxpl;
    double term = frac;     // denom start from 1.0
    double sum = term;

    while ( sum != old_sum )
    {
        old_sum = sum;
        denom += 2.0;
        frac *= xmlxpl_2;
        sum += frac / denom;
    }
    return 2.0 * sum;
}

double processLogarithm(double number, double base, char *op){
	int baseInt = base;
	
	if(strcmp(op,"log(")==0){
		if (base != 0.0){
			return logarithm(number,base);	
		}else{
			return logarithm(number,10.0);
		}
	}
	else if (strcmp(op,"ln(")==0){
		return naturalLogarithm(number);
	}
	else{
		printf("\t\tOperator is invalid: %s", op);
        exit(1);
	}
}

//Create Node
node CreateNodeList(){
	node P;
	
	P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{
		(P)->next=NULL;
		(P)->isoperator=1;
	} 
	
	return P;
}

address Create_Tree(Queue Z){
	address P;
	address stack[50];
	node Q;
	int i, len, top=-1;
	infotype c;
	float d;
	
	Q=Z.First;
	
	while(Q!=NULL){
		if(Q->isoperator==1){
			c=Q->oprtr;
			P=CreateNodeOperator(c);
			right(P)=stack[top--];
			left(P)=stack[top--];
		}else{
			d=Q->operand;
			P=CreateNodeOperand(d);
		}
		stack[++top]=P;
		Q=Q->next;
	}
	return(stack[0]);
}
#endif
