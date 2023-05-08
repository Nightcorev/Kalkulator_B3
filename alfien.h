#ifndef alfien_H
#define alfien_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

/*Daftar modul*/
double logarithm(double number, double base);
double naturalLogarithm(double number);
double processLogarithm(double number, double base, char *op);
node CreateNodeList();
address BuildTree(infotype postfix[]);

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
//		if(isdigit(c)){
//			P=CreateNode(c);
//		} else{
//			P=CreateNode(c);
//			right(P)=stack[top--];
//			left(P)=stack[top--];
//		}
		stack[++top]=P;
		Q=Q->next;
	}
	return(stack[0]);
}
#endif
