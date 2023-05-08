#ifndef Fikri_H
#define Fikri_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double modulus(double a, double b);

double modulus(double a, double b){
	double result;
	result= (int)a % (int)b;
	return result;
}
#endif
