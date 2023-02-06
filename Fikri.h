#ifndef Fikri_H
#define Fikri_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kalkulatorMeter(){
	int pilihan, x, y, z, nilaiSatuan, i=1, hasil, pangkat;
	printf("=========================================================");
	printf("\n| (0)Km | (1)Hm | (2)Dam | (3)m | (4)Dm | (5)Cm | (6)Mm |");
	printf("\n|=======================================================|");
	
	printf("\nPilih satuan meteran:");
	scanf("%d", &pilihan);
	x = pilihan;
	 
	
	if (pilihan <= 6){
		printf("Masukan nilai panjang dari satuan meteran:");
		scanf("%d", &nilaiSatuan);
		printf("pilih satuan meteran yang ingin diubah:");
		scanf("%d", &pilihan);
		y = pilihan;
		
		if (x < y){
			z=y-x;
			pangkat = pow(10,z);
			hasil = nilaiSatuan*pangkat;
			printf("Hasil nya adalah: %d", hasil);
		}else if (x > y){
			z=x-y;
			pangkat = pow(10,z);
			hasil = nilaiSatuan/pangkat;
			printf("Hasil nya adalah: %d", hasil);
		}else if (x == y){
			printf("Hasil nya adalah: %d", nilaiSatuan);
		}
	}else{
		printf("input yang anda masukan tidak tersedia. . .\n");
		system("pause");
		system("cls");
		kalkulatorMeter();
	}
	
	return 0;
}

#endif
