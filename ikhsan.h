#ifndef ikhsan_h
#define ikhsan_h
#define phi 3.14159265
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const float sudutSegitiga=180.0;
double sinHasil(double angleTrigonometri);
double cosHasil(double angleTrigonometri);
double tanHasil(double angleTrigonometri);
double cosecHasil(double angleTrigonometri);
double secHasil(double angleTrigonometri);
double cotanHasil(double angleTrigonometri);


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

#endif
