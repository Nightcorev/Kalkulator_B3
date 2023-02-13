#ifndef Afyar_h
#define Afyar_h

void Judul();
int perpangkatan (int x, int y);

#include <stdio.h>

void Judul();
int perpangkatan (int x, int y);

void Judul (){
	printf ("PROGRAM PERPANGKATAN \n\n");
}

int perpangkatan (int x, int y){
	int i, a;
	a=x;
	
	for (i=1; i<y; i++){
		a *= x;
	}
	return a;
}



float hitungPersentase(float angka, float persen) {
    return angka * (persen / 100);
}



#endif
