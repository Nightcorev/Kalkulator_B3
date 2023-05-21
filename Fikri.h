#ifndef Fikri_H
#define Fikri_H

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "header.h"

double faktorial(double n);
int derajatOperator(infotype oper);
int isOperator(infotype oper); 
double modulus(double a, double b);

int derajatOperator(infotype oper){
	if(oper=='+' || oper=='-'){ 
		return 1; //jika yang diinputkan user terdapat operator '+' atau '-', maka akan mengembalikan nilai dari variabel oper dengan nilai 1
	} else if(oper=='*' || oper=='/'){
		return 2;//jika yang diinputkan user terdapat operator '*' atau '/', maka akan mengembalikan nilai dari variabel oper dengan nilai 2
	} else if(oper=='^' || oper=='%' || oper=='m' || oper=='v'){
		return 3;//jika yang diinputkan user terdapat operator '^' atau '%' atau 'm' atau 'v', maka akan mengembalikan nilai dari variabel oper dengan nilai 3
	} else{
		printf("Error, Operator Tidak Diketahui: %c", oper);//jika operator yang sama dengan di selection, maka operator tersebut tidak diketahui
        exit(1);
	}
}

int isOperator(infotype oper){
	if(oper=='+' || oper=='-' || oper=='*' || oper=='/' || oper=='^' || oper=='%' || oper=='m' || oper=='v'){
		return 1; //jika operator yang diinput oleh user sama dengan di selection, maka akan mengembalikan nilai dari variabel oper dengan nilai 1
	}
	return 0;
}

double faktorial(double n){ //modul untuk memproses hasil dari faktorial melalui variabel n
	double hasil=1; //variabel hasil diberi nilai 1
	int i=1; //variabel i diberi nilai 1
	
	while(i<=n){ //melakukan perulangan hingga mencapai nilai n (nilai yang diinput oleh user) 
		hasil=hasil*i; //nilai dari variabel hasil dikalikan dengan nilai dari variabel i
		i++; //selama perulangan berlanjut, variabel i melakukan pertambahan nilai
	}
	return hasil; //mengembalikan nilai dari variabel hasil
}

double modulus(double a, double b){ //modul untuk memproses hasil dari modulus melalui variabel a dan variabel b
	double result; //deklarasi variabel result untuk menyimpan hasil dari modulus variabel a dengan b
	result= (int)a % (int)b; //melakukan proses modulus pada variabel a dan b, lalu hasil nilai tersebut disimpan ke variabel result 
	return result; //mengembalikan nilai dari variabel result
}
#endif
