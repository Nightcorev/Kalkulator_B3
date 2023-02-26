#ifndef ikhsan_h
#define ikhsan_h
#define phi 3.14159265
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const float sudutSegitiga=180.0;
double trigonometri(double angleTrigonometri, char opsiTrigonometri);
float konversiSuhu();
double sinHasil(double angleTrigonometri);
double cosHasil(double angleTrigonometri);
double tanHasil(double angleTrigonometri);
double cosecHasil(double angleTrigonometri);
double secHasil(double angleTrigonometri);
double cotanHasil(double angleTrigonometri);
float operasiSuhu(int opsiSuhu1, int opsiSuhu2, float suhu);

double trigonometri(double angleTrigonometri, char opsiTrigonometri){
	double hasilTrigonometri;
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
		case 'o':
			hasilTrigonometri=cosecHasil(angleTrigonometri);
			return hasilTrigonometri;
			break;
		case 'e':
			hasilTrigonometri=secHasil(angleTrigonometri);
			return hasilTrigonometri;
			break;
		case 'a':
			hasilTrigonometri=cotanHasil(angleTrigonometri);
			return hasilTrigonometri;
			break;
		default:
			exit(1);
			break;
	}
}

double sinHasil(double angleTrigonometri){
	double hasilSin;
	
	hasilSin=(angleTrigonometri*phi)/sudutSegitiga;
	hasilSin=sin(hasilSin);
	return hasilSin;
}

double cosHasil(double angleTrigonometri){
	double hasilCos;
	
	hasilCos=(angleTrigonometri*phi)/sudutSegitiga;
	hasilCos=cos(hasilCos);
	return hasilCos;
}

double tanHasil(double angleTrigonometri){
	double hasilTan;
	
	hasilTan=(angleTrigonometri*phi)/sudutSegitiga;
	hasilTan=tan(hasilTan);
	return hasilTan;
}

double cosecHasil(double angleTrigonometri){
	double hasilCosec;
	
	hasilCosec=1/sinHasil(angleTrigonometri);
	return hasilCosec;
}

double secHasil(double angleTrigonometri){
	double hasilSec;
	
	hasilSec=1/cosHasil(angleTrigonometri);
	return hasilSec;
}

double cotanHasil(double angleTrigonometri){
	double hasilCotan;
	
	hasilCotan=1/tanHasil(angleTrigonometri);
	return hasilCotan;
}

float konversiSuhu(){
	int opsiSuhu1,opsiSuhu2;
	float suhu,hasilSuhu;
	printf("Pilih suhu awal\n");
	printf("1. Celcius\n2. Fahrenheit\n3. Reaumur\n4. Kelvin\nPilih = ");
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
