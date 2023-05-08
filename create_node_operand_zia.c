#include<stdio.h>
#include<stdlib.h>

address CreateNodeOperand(float input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->operand=input;
	P->isOperator=0;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}

