#ifndef ikhsan_h
#define ikhsan_h
#define phi 3.14159265
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const float sudutSegitiga=180.0;
float trigonometri(double angleTrigonometri, char opsiTrigonometri);
float sinHasil(int angleTrigonometri);
float cosHasil(int angleTrigonometri);
float tanHasil(int angleTrigonometri);

float trigonometri(double angleTrigonometri, char opsiTrigonometri){
	float hasilTrigonometri;
	switch(opsiTrigonometri){
		case 's':
			hasilTrigonometri=sinHasil(angleTrigonometri);
			return hasilTrigonometri;
			break;
		case 'c':
			hasilTrigonometri=cosHasil(angleTrigonometri);
			return hasilTrigonometri;
			break;
		case 't':
			hasilTrigonometri=tanHasil(angleTrigonometri);
			return hasilTrigonometri;
			break;
		default:
			exit(1);
			break;
	}
}

float sinHasil(int angleTrigonometri){
	float hasilSin;
	
	hasilSin=(angleTrigonometri*phi)/sudutSegitiga;
	hasilSin=sin(hasilSin);
	return hasilSin;
}

float cosHasil(int angleTrigonometri){
	float hasilCos;
	
	hasilCos=(angleTrigonometri*phi)/sudutSegitiga;
	hasilCos=cos(hasilCos);
	return hasilCos;
}

float tanHasil(int angleTrigonometri){
	float hasilTan;
	
	hasilTan=(angleTrigonometri*phi)/sudutSegitiga;
	hasilTan=tan(hasilTan);
	return hasilTan;
}

float konversiSuhu(){
	int opsiSuhu1,opsiSuhu2;
	float suhu;
	printf("Pilih suhu awal\n");
	printf("1. Celcius\n2. Fahrenheit\n3. Reaumur\n4. Kelvin\n");
	scanf("%d",&opsiSuhu1);
	printf("Masukkan suhu : ");
	scanf("%d",&suhu);
	printf("1. Celcius\n2. Fahrenheit\n3. Reaumur\n4. Kelvin\n");
	scanf("%d",&opsiSuhu2);
	switch(opsiSuhu1){
		case 1:
			break;
			switch(opsiSuhu2){
				case 1:
					return suhu;
					break;
				case 2:
					suhu=((suhu*9)/5)+32;
					return suhu;
					break;
				case 3:
					suhu=(suhu*4)/5;
					return suhu;
					break;
				case 4:
					suhu=suhu+273.15;
					return suhu;
			}
		case 2:
			break;
			switch(opsiSuhu2){
				case 1:
					suhu=((suhu-32)*5)/9;
					return suhu;
					break;
				case 2:
					return suhu;
					break;
				case 3:
					suhu=((suhu-32)*4)/9;
					return suhu;
					break;
				case 4:
					suhu=(((suhu-32)*5)/9)+273.15;
					return suhu;
			}
			break;
		case 3:
			switch(opsiSuhu2){
				case 1:
					suhu=(suhu*5)/4;
					return suhu;
					break;
				case 2:
					suhu=((suhu*9)/4)+32;
					return suhu;
					break;
				case 3:
					return suhu;
					break;
				case 4:
					suhu=((suhu*5)/4)+273.15;
					return suhu;
			}
			break;
		case 4:
			switch(opsiSuhu2){
				case 1:
					suhu=suhu-273.15;
					return suhu;
					break;
				case 2:
					suhu=(((suhu-273.15)*9)/5)+32;
					return suhu;
					break;
				case 3:
					suhu=((suhu-273.5)*4)/5;
					break;
				case 4:
					return suhu;
			}
			break;			
	}
}



#endif
