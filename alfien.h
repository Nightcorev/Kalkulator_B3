#ifndef alfien_H
#define alfien_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "header.h"
#include "Zia.h"

/*Daftar modul*/
double logarithm(double number, double base);
double naturalLogarithm(double number);
double processLogarithm(double number, double base, char *op, char *kembali);
node CreateNodeList();
address Create_Tree(Queue Z);

/*rumus logaritma*/
double logarithm(double number, double base)
{ 
	if (number <= 0 || base <= 0 || base == 1) {
    	return 0; 		/*Nilai logaritma tidak terdefinisi untuk number <= 0, base <= 0, atau base = 1*/
    }
    return naturalLogarithm(number) / naturalLogarithm(base);	
}

/*rumus logaritma natural*/
double naturalLogarithm(double number)
{	
	/*referensi https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having*/
	/*kamus data*/
	double old_sum = 0.0;
    double xmlxpl = (number - 1) / (number + 1);	/*menghitung perbedaan rasio yang digunakan dalam perhitungan iteratif logaritma alami*/
    double xmlxpl_2 = xmlxpl * xmlxpl;				/*menyimpan kuadrat dari xmlxpl*/
    double denom = 1.0;
    double frac = xmlxpl;
    double term = frac;     						/*denom start from 1.0*/
    double sum = term;
    
	/*proses*/
	if (number <= 0) {
        return 0; 					/*Nilai logaritma tidak terdefinisi untuk number <= 0*/
    }

    while ( sum != old_sum ){		/*looping berjalan selama sum berbeda dengan old_sum*/
        old_sum = sum;  			/*menyimpan nilai sum selama proses looping*/
        denom += 2.0;				
        frac *= xmlxpl_2;
        sum += frac / denom;
    }
    return 2.0 * sum;
}

double processLogarithm(double number, double base, char *op, char *kembali){
	if(strcmp(op,"log(")==0){	/*jika operator yang diinputkan yaitu log(*/
			return logarithm(number,base);	

	}else if (strcmp(op,"ln(")==0){	
		if(number!=0){			/*jika operator yang diinputkan yaitu ln(*/
			return naturalLogarithm(number);
		}else{
			*kembali='y';
			return 0;
		}	
	}else{	
		/*jika operator yang diinputkan tidak sesuai dengan aturan*/
		//printf("\t\t\tOperator is invalid: %s", op);
		*kembali='y';
		return 0;
	}
}

//Create Node
node CreateNodeList(){
	node P;
	
	P = (node) malloc (sizeof (ElmtList));		/*alokasi node pada memory*/
	if(P==NULL){								/*jika terjadi gagal alokasi*/
		printf("Gagal Alokasi");
	}else{
		(P)->next = NULL;			/*(P)->next diisikan null, karena belum terdapat node setelahnya*/
		(P)->isoperator = 1;		/*(P)->isoperator diisikan 1 untuk menandakan node tersebut adalah node operator*/
	} 
	
	return P;
}

address Create_Tree(Queue Z){
	/*kamus data*/
	address P;
	address stack[50];
	node Q;
	int top=-1;
	infotype c;
	float d;
	
	/*proses*/
	Q=Z.First; 				/*node Q diisikan dengan node yang ditunjuk oleh first*/
	
	while(Q!=NULL){
		if(Q->isoperator==1){			/*pengecekan node adalah node operator atau bukan*/
			c=Q->oprtr;					/*variabel c bertipe char diisikan dengan info dari Q->oprtr, yaitu operator dari kalkulator*/
			P=CreateNodeOperator(c);	/*variabel address P akan dialokasikan ke memory menjadi node tree*/
			right(P)=stack[top--];		/*anak kanan P diisikan dengan stack[top]*/
			left(P)=stack[top--];		/*anak kiri P diisikan dengan stack[top]*/
		}else{
			d=Q->operand;				/*variabel d bertipe float diisikan dengan info dari Q->operand, yaitu operand(angka) dari kalkulator*/
			P=CreateNodeOperand(d);		/*variabel address P akan dialokasikan ke memory menjadi node tree*/
		}
		stack[++top]=P;					/*variabel stack[top] diisikan dengan alamat P*/
		Q=Q->next;						/*node Q diisi dengan alamat dari Q->next*/
	}
	return(stack[0]);
}
#endif
