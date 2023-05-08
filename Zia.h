#ifndef Zia_h
#define Zia_h

void pertambahan_kurang(){
	
	char op;
	int first, second;
	printf("Enter an operator (+, -): ");
	scanf ("%c", &op);fflush(stdin);
	printf("Enter Two Operands: ");
	scanf("%d %d", &first, &second);
	
	switch (op) {
		case '+':
		printf("%d + %d = %d", first, second, first + second);
		break;
		case '-':
		printf("%d - %d = %d", first, second, first - second);
		break;
		
		// operator doesn't match any constant
		default:
			printf("Error! operator is not correct");
			break;
	}
}

double perjumlahan(double bil1, double bil2){
	return  bil1 + bil2;
}
double pengurangan(double bil1, double bil2){
	return bil1 - bil2;
}
double perkalian(double bil1, double bil2){
	return bil1 * bil2;
}

double pembagian(double bil1, double bil2){
	return bil1 / bil2;
}

address CreateNodeOperand(float input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->operand=input;
	P->isOperator=0;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}

address CreateNodeOperator(char input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->data=input;
	P->isOperator=1;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}  

#endif
