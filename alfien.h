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

//build tree
address BuildTree(infotype postfix[]){
	address P;
	address stack[50];
	int i, len, top=-1;
	infotype c;
	
	len=strlen(postfix);
	
	for(i=0;i<len;i++){
		c=postfix[i];
		if(isdigit(c)){
			P=CreateNode(c);
		} else{
			P=CreateNode(c);
			right(P)=stack[top--];
			left(P)=stack[top--];
		}
		stack[++top]=P;
	}
	return(stack[0]);
}
#endif
