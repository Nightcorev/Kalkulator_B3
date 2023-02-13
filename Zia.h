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

int perjumlahan(int bil1, int bil2){
	return  bil1 + bil2;
}
int pengurangan(int bil1, int bil2){
	return bil1 - bil2;
}
int perkalian(int bil1, int bil2){
	return bil1 * bil2;
}

int pembagian(int bil1, int bil2){
	return bil1 / bil2;
}


#endif
