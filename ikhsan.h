#ifndef ikhsan_h
#define ikhsan_h
#define phi 3.14159265
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const float sudutSegitiga=180.0;
float trigonometri(double angleTrigonometri, char opsiTrigonometri);
float konversiSuhu();
float sinHasil(int angleTrigonometri);
float cosHasil(int angleTrigonometri);
float tanHasil(int angleTrigonometri);
float operasiSuhu(int opsiSuhu1, int opsiSuhu2, float suhu);

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
	float suhu,hasilSuhu;
	printf("Pilih suhu awal\n");
	printf("1. Celcius\n2. Fahrenheit\n3. Reaumur\n4. Kelvin\n");
	scanf("%d",&opsiSuhu1);
	printf("Masukkan suhu : ");
	scanf("%f",&suhu);
	printf("1. Celcius\n2. Fahrenheit\n3. Reaumur\n4. Kelvin\n");
	scanf("%d",&opsiSuhu2);
	hasilSuhu=operasiSuhu(opsiSuhu1,opsiSuhu2,suhu);
	printf("hasil konversinya adalah %.2f",hasilSuhu);
	return 0;
}

float operasiSuhu(int opsiSuhu1, int opsiSuhu2, float suhu){	
	switch(opsiSuhu1){
		case 1:
			if(opsiSuhu2==1){
				return suhu;
			}else if(opsiSuhu2==2){
				suhu=((suhu*9)/5)+32;
				return suhu;
			}else if(opsiSuhu2==3){
				suhu=(suhu*4)/5;
				return suhu;
			}else if(opsiSuhu2==4){
				suhu=suhu+273.15;
				return suhu;
			}else{
				exit(1);
			}
			break;
		case 2:
			if(opsiSuhu2==1){
				suhu=((suhu-32)*5)/9;
				return suhu;
			}else if(opsiSuhu2==2){
				return suhu;
			}else if(opsiSuhu2==3){
				suhu=((suhu-32)*4)/9;
				return suhu;
			}else if(opsiSuhu2==4){
				suhu=(((suhu-32)*5)/9)+273.15;
				return suhu;
			}else{
				exit(1);
			}			
			break;
		case 3:
			if(opsiSuhu2==1){
				return suhu;
			}else if(opsiSuhu2==2){
				suhu=((suhu*9)/5)+32;
				return suhu;
			}else if(opsiSuhu2==3){
				suhu=(suhu*4)/5;
				return suhu;
			}else if(opsiSuhu2==4){
				suhu=suhu+273.15;
				return suhu;
			}else{
				exit(1);
			}			
			break;
		case 4:
			if(opsiSuhu2==1){
				suhu=suhu-273.15;
				return suhu;
			}else if(opsiSuhu2==2){
				suhu=(((suhu-273.15)*9)/5)+32;
				return suhu;
			}else if(opsiSuhu2==3){
				suhu=((suhu-273.5)*4)/5;
			}else if(opsiSuhu2==4){
				return suhu;
			}else{
				exit(1);
			}			
			break;			
	}
}


#endif
