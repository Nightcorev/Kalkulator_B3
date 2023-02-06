#ifndef ikhsan_h
#define ikhsan_h
#define phi 3.14159265
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const float sudutSegitiga=180.0;
void trigonometri();
float sinHasil(int angleTrigonometri);
float cosHasil(int angleTrigonometri);
float tanHasil(int angleTrigonometri);

void trigonometri(){
	float hasilTrigonometri;
	int opsiTrigonometri;
	int angleTrigonometri;
	char opsiKembali;
	printf("Pilih Trigonometri\n");
	printf("1. Sin\n2. Cos\n3. Tan\n");
	printf("masukkan opsi = ");
	scanf("%d",&opsiTrigonometri);
	printf("Masukkan sudut = ");
	scanf("%d",&angleTrigonometri);
	switch(opsiTrigonometri){
		case 1:
			hasilTrigonometri=sinHasil(angleTrigonometri);
			break;
		case 2:
			hasilTrigonometri=cosHasil(angleTrigonometri);
			break;
		case 3:
			hasilTrigonometri=tanHasil(angleTrigonometri);
			break;
			break;
		default:
			exit(1);
			break;
	}
	printf("Hasilnya adalah %.2f",hasilTrigonometri);
	fflush;
}

float sinHasil(int angleTrigonometri){
	float hasilSin;
	
	hasilSin=angleTrigonometri*phi/sudutSegitiga;
	hasilSin=sin(hasilSin);
	return hasilSin;
}

float cosHasil(int angleTrigonometri){
	float hasilCos;
	
	hasilCos=angleTrigonometri*phi/sudutSegitiga;
	hasilCos=cos(hasilCos);
	return hasilCos;
}

float tanHasil(int angleTrigonometri){
	float hasilTan;
	
	hasilTan=angleTrigonometri*phi/sudutSegitiga;
	hasilTan=tan(hasilTan);
	return hasilTan;
}

#endif
