#ifndef ikhsan_h
#define ikhsan_h
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define phi 3.1415926535897931
#define limit 20

double sinHasil(double angleTrigonometri);
double cosHasil(double angleTrigonometri);
double tanHasil(double angleTrigonometri);
double cosecHasil(double angleTrigonometri);
double secHasil(double angleTrigonometri);
double cotanHasil(double angleTrigonometri);
double DequeOperand(Queue *A);
const float sudutSegitiga=180.0;

double sinHasil(double angleTrigonometri)
//melakukan proses Trigonometri SIN Referensi: https://medium.com/@Konstantinos_Gkizinos/c-program-to-calculate-sin-x-and-cos-x-without-using-math-h-ca62f7b3777c\
//Menggunakan Deret Maclaurin
{
	double sum; //variabel untuk menjumlahkan suku-suku
	double fa; //variabel untuk faktorial
	double pow; //variabel untuk menentukan pangkat dari trigonometri
	int i,j; //i dan j sebagai variabel looping
	sum = 0.0; //mendefinisikan sum menjadi 0
	
	angleTrigonometri=(angleTrigonometri*phi)/sudutSegitiga; //membuat sudut menjadi radian
	
	for(i = 0; i <= limit; i++) //karena Deret Maclaurin tak hingga, sehingga dibutuhkan limit
	{
		fa = 1.0; //Mendefinisikan faktorial menjadi 1
		pow = 1.0; //Mendefinisikan pangkat dari angleTrigonometri menjadi 1
		for(j = 1; j <= 2*i+1; j++) //loop untuk faktorial dan pangkatnya
		{
			fa *= j; //proses faktorial
			pow *= angleTrigonometri; //proses perpangkatan
		}
		sum += ((i%2?-1.0:1.0)/fa)*pow; //penjumlahan Deret
	}
	return sum; //mengembalikan penjumlahan
}

double cosHasil(double angleTrigonometri)
//melakukan proses Trigonometri COS referensi: https://medium.com/@Konstantinos_Gkizinos/c-program-to-calculate-sin-x-and-cos-x-without-using-math-h-ca62f7b3777c
{
	double sum; //variabel untuk menjumlahkan suku-suku
	double fa; //variabel untuk faktorial
	double pow; //variabel untuk menentukan pangkat dari trigonometri
	int i,j; //i dan j sebagai variabel looping
	sum = 0.0; //mendefinisikan sum menjadi 0
	
	angleTrigonometri=(angleTrigonometri*phi)/sudutSegitiga; //membuat sudut menjadi radian
	
	for(i = 0; i <= limit; i++) //karena Deret Maclaurin tak hingga, sehingga dibutuhkan limit
	{
		fa = 1.0; //Mendefinisikan faktorial menjadi 1
		pow = 1.0; //Mendefinisikan pangkat dari angleTrigonometri menjadi 1
		for(j = 1; j <= 2*i; j++) //loop untuk faktorial dan pangkatnya
		{
			fa *= j; //proses faktorial
			pow *= angleTrigonometri; //proses perpangkatan
		}
		sum += ((i%2?-1.0:1.0)/fa)*pow; //penjumlahan Deret
	}
	return sum; //mengembalikan penjumlahan
}

double tanHasil(double angleTrigonometri)
//melakukan proses Trigonometri TAN
{
	double result; //Mendifinisikan Result
	
	result=sinHasil(angleTrigonometri)/cosHasil(angleTrigonometri); //proses tan: sin/cos
	return result; //mengembalikan Result
}

double cosecHasil(double angleTrigonometri)
//melakukan proses Trigonometri COSEC
{
	double result; //Mendifinisikan Result
	
	result=1/sinHasil(angleTrigonometri); //proses tan: 1/sin
	return result; //mengembalikan Result
}

double secHasil(double angleTrigonometri)
//melakukan proses Trigonometri SEC
{
	double result; //Mendifinisikan Result
	
	result=1/cosHasil(angleTrigonometri); //proses tan: 1/cos
	return result; //mengembalikan Result
}

double cotanHasil(double angleTrigonometri)
//melakukan proses Trigonometri COTAN
{
	double result; //Mendifinisikan Result
	
	result=1/tanHasil(angleTrigonometri); //proses tan: 1/tan
	return result; //mengembalikan Result
}

double DequeOperand(Queue *listQueue)
//Tujuan dari modul ini adalah untuk melakukan deque pada queue
//Modul ini, digunakan untuk mengambil operand di depan operator
{
	float angka; //mendefinisikan variabel angka yang akan di deque sebagai float
	node First,Last,Throw; //mendefinisikan variabel first last throw bertipe node
	First=listQueue->First; //mengassign variabel first dengan variabel first pada listQueue
	Last=listQueue->Last; //mengassign variabel last dengan variabel last pada listQueue
	if(First==NULL){
		printf("Queue Empty"); //jika First kosong maka list kosong
	}else{
		if(First!=Last){ //jika First tidak menunjuk sama dengan last
			while(First->next!=Last){ //looping untuk menemukan last berdasarkan first
				First=First->next; //first akan terus ke first->next sampai looping berakhit
			}
			Throw=Last; //mengassign throw dengan last untuk menyimpan sementara
			angka=Last->operand; //mengassign angka dengan angka yang berada pada operand
			listQueue->Last=First; //mengassign listQueue-> last dengan First
			listQueue->Last->next=NULL; //Mengkosongkan last next karena last sudah di assign dengan throw
			free(Throw); //melakukan dealokasi pada throw
			return angka; //mengembalikan angka
		}else{ //jika First menunjuk sama dengan last
			Throw=Last; //mengassign throw dengan last untuk menyimpan sementara
			angka=Last->operand; //mengassign angka dengan angka yang berada pada operand yang ditunjuk last
			listQueue->Last=NULL; //mengkosongkan last pada listQueue
			listQueue->First=NULL; //mengkosongkan First pada listQueue
			free(Throw); //melakukan dealokasi pada throw
			return angka; //mengembalikan angka
		}
		
	}
}

double operasi_trigono(double bilangan1, char* trigono, char* kembali) 
//Modul ini untuk mengidentifikasi operator trigono
{
    double result = 0; //mendefinisikan result menjadi 0
    if (strcmp(trigono,"sin(") == 0) { //mengecek apakah operator trigono adalah sin
        result = sinHasil(bilangan1); //mengirim ke modul sinHasil untuk dihitung jika operator trigono adalah sin
    }else if (strcmp(trigono,"cos(") == 0) { //mengecek apakah operator trigono adalah cos
        result =  cosHasil(bilangan1); //mengirim ke modul cosHasil untuk dihitung jika operator trigono adalah cos
    }else if (strcmp(trigono,"tan(") == 0) { //mengecek apakah operator trigono adalah tan
    	if(bilangan1== 90||bilangan1== 270||bilangan1== 360){
    		*kembali='y';
    	}else{
 	        result =  tanHasil(bilangan1); //mengirim ke modul tanHasil untuk dihitung jika operator trigono adalah tan
		}
    }else if (strcmp(trigono,"csc(") == 0) { //mengecek apakah operator trigono adalah cosec
        if(bilangan1== 0||bilangan1== 180||bilangan1== 360){
    		*kembali='y';
    	}else{
    		result =  cosecHasil(bilangan1); //mengirim ke modul cosecHasil untuk dihitung jika operator trigono adalah cosec

		} 
    }else if (strcmp(trigono,"sec(") == 0) { //mengecek apakah operator trigono adalah sec
        if(bilangan1== 90||bilangan1== 270){
        	*kembali='y';
    	}else{
	        result =  secHasil(bilangan1); //mengirim ke modul secHasil untuk dihitung jika operator trigono adalah sec
		} 
    }else if (strcmp(trigono,"cot(") == 0) { //mengecek apakah operator trigono adalah cotan
    	if(bilangan1== 90||bilangan1== 270||bilangan1== 360){
    		*kembali='y';
    	}else{
    		result =  tanHasil(bilangan1); //mengirim ke modul cotanHasil untuk dihitung jika operator trigono adalah cotan

		}
    }else{
    	*kembali='y'; //mendefinisikan kembali sebagai 'y' agar bisa looping
    	return result; //mengembalikan result
	}
	return result; //mengembalikan result
}

#endif
