#ifdef Zia_h
#define Zia_h
#include <stdio.h>

int main(){
	
	char op;
	int first, second;
	printf("Enter an operator (+, -): ");
	scanf ("%c", &op);
	printf("Enter Two Operands: ");
	scanf("%d %d", &first, &second);
	
	switch (op) {
		case '+':
		printf("%1d + %1d = %1d", first, second, first + second);
		break;
		case '-':
		printf("%1d - %1d = %1d", first, second, first - second);
		break;
		
		// operator doesn't match any constant
		default:
			printf("Error! operator is not correct");
	}
	
	return 0;
}

#endif
