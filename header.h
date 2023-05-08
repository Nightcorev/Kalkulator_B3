#ifndef header_h
#define header_h
#define Data(P) (P)->data
#define right(P) (P)->right
#define left(P) (P)->left
#define Nil NULL

typedef char infotype;
typedef struct Elemen *address;
typedef struct Elemen{
	infotype data;
	float operand;
	address right;
	address left;
	int isOperator;
}Tree;

typedef struct Node *node;
typedef struct Node{
	node next;
	infotype oprtr;
	float operand;
	int isoperator;
}ElmtList;

typedef struct{
	node Head;
}Stack;

typedef struct {
	node First;
	node Last;
}Queue;

#endif
