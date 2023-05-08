#ifndef Fikri_H
#define Fikri_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double kalkulatorMeter();
void prosesKonversi(double nilai, char Satuan_1[], char Satuan_2[]); 
double modulus(double a, double b);

void prosesKonversi(double nilai, char Satuan_1[], char Satuan_2[]) {
    double konversi[7][7] = {
        {1, 10, 100, 1000, 10000, 100000, 1000000}, //index_1 [0] = kilometer
        {0.1, 1, 10, 100, 1000, 10000, 100000}, //index_1 [1] = hektometer
        {0.01, 0.1, 1, 10, 100, 1000, 10000}, //index_1 [2] = dekameter
        {0.001, 0.01, 0.1, 1, 10, 100, 1000}, //index_1 [3] = meter
        {0.0001, 0.001, 0.01, 0.1, 1, 10, 100}, //index_1 [4] = decimeter
        {0.00001, 0.0001, 0.001, 0.01, 0.1, 1, 10}, //index_1 [5] = centimeter 
        {0.000001, 0.00001, 0.0001, 0.001, 0.01, 0.1, 1} //index_1 [6] = milimeter
    //index_2  [0],   [1] ,  [2]  , [3] , [4] , [5], [6]
    };
	int index_1 = -1, index_2 = -1, i;
    char units[7][10] = {"kilometer", "hektometer", "dekameter", "meter", "decimeter", "centimeter", "milimeter"};
	
	//mencari index_1
    for (i = 0; i < 7; i++) {
        if (strcmp(units[i], Satuan_1) == 0) {
            index_1 = i;
            break;
        }
    }
	
	//mencari index_2
    for (i = 0; i < 7; i++) {
        if (strcmp(units[i], Satuan_2) == 0) {
            index_2 = i;
            break;
        }
    }
    
    double ambilNilaiFaktor = konversi[index_1][index_2];

    double hasil = nilai * ambilNilaiFaktor;
//	printf("%d - %d", index1, index2);

	printf("\t\t\t%.6lf %s = %.6lf %s\n", nilai, Satuan_1, hasil, Satuan_2);
}



double kalkulatorMeter(){
	double inputNilai_1, inputNilai_2;
    char inputSatuan_1[10], inputSatuan_2[10];
	printf("\t\t\t=======================================");
	printf("\n\t\t\t| kilometer | hektometer | dekameter  |");
	printf("\n\t\t\t---------------------------------------");
	printf("\n\t\t\t|   meter   | decimeter  | centimeter |");
	printf("\n\t\t\t---------------------------------------");
	printf("\n\t\t\t|             milimeter               |");
	printf("\n\t\t\t=======================================");

    printf("\n\t\t\tMasukan nilai dan satuan //contoh(2.5kilometer): ");
    scanf("%lf %s", &inputNilai_1, inputSatuan_1);
	
    printf("\t\t\tsatuan yang ingin di ubah //contoh(meter): ");
    scanf("%s", inputSatuan_2);
	
    if (strcmp(inputSatuan_1, inputSatuan_2) == 0) {
        printf("\t\t\t%.2lf %s = %.2lf %s\n", inputNilai_1, inputSatuan_1, inputNilai_1, inputSatuan_2);
    } else if (inputNilai_1 > inputNilai_2) { //inputNilai_2 bernilai 0
    	prosesKonversi(inputNilai_1, inputSatuan_1, inputSatuan_2);
    } else {
        printf("\n\t\t\t*error.....input anda masukan tidak sesuai dengan contoh\n");
    }
}

double modulus(double a, double b){
	double result;
	result= (int)a % (int)b;
	return result;
}
#endif
