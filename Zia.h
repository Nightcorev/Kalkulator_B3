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

//Modul Create Node Operand
address CreateNodeOperand(float input){ 
	address P; 
	P = (address) malloc (sizeof (Tree)); //mengalokasikan memori bertipe data Tree menggunakan fungsi malloc.
	P->operand=input;                     //Memperbarui nilai operand di node yang ditunjuk oleh P dengan nilai dari parameter input.
	P->isOperator=0;                      //Mengatur nilai isOperator di node yang ditunjuk oleh P menjadi 0
	P->left=NULL;                         //Menginisialisasi pointer left di node yang ditunjuk oleh P dengan NULL
	P->right=NULL;                        //Menginisialisasi pointer right di node yang ditunjuk oleh P dengan NULL
	return P;                             //Mengembalikan alamat dari node
	 
}

//Modul Create Node Operator
address CreateNodeOperator(char input){   //Fungsi ini mengambil satu parameter input bertipe data "char".
	address P;
	P = (address) malloc (sizeof (Tree)); //Baris ini mengalokasikan memori untuk objek bertipe data Node menggunakan fungsi malloc.
	P->data=input;                        
	P->isOperator=1;                      //Mengatur nilai isOperator di node yang ditunjuk oleh P menjadi 1
	P->left=NULL;
	P->right=NULL;
	return P;                             //Mengembalikan alamat dari node
	
}  


#endif
