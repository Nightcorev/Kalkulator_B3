#ifndef alfien_H
#define alfien_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*Daftar modul*/
double logarithm(double number, double base);
double naturalLogarithm(double number);

//rumus logaritma
double logarithm(double number, double base)
{
	double log = 0;
    
    if (number <= 0 || base <= 0 || base == 1) {
        return -1;
    }
    
    while (number >= base) {
        number /= base;
        log++;
    }
    
    return log;
}

//rumus logaritma natural
double naturalLogarithm(double number)
{	
    return log(number);
}

//process
//double processLogarithm(double number, double base, char op[]){
//	if(strcmp(op,"log(")==0){
//		return logarithm(number,base);
//	}
//	else if(strcmp(op,"ln(")==0){
//		return naturalLogarithm(number);
//	}
//	else{
//		printf("Operator is invalid: %s", op);
//        exit(1);
//	}
//}

//int process(){
//	int a = 0, i = 0, num_top = 0, index_angka= -1, top_no = 0;
//	char inputan[100], num[100], operator_log[100], nomor[100];
//    double bilangan, bilangan2, angka[100];;
//	
//	printf("Masukkan ekspresi : "); scanf("%s", inputan);
//	for (a=0; a<strlen(inputan); a++){
//		if(isdigit(inputan[a])) {
//	        while (isdigit(inputan[a]) || inputan[a] == '.') {
//	            num[num_top++] = inputan[a++];
//	        }
//	  		num[num_top++]='\0';
//	        angka[++index_angka] = strtod(num,NULL);
//	    	a--;
//		}
//		else if (inputan[a] == 'l'){
//			while(inputan[a]!=')'){
//            	if(isdigit(inputan[a])||inputan[a]=='.'){
//            		nomor[top_no++] = inputan[a++];
//				}else {
//				    operator_log[i++] = inputan[a++];
//				    operator_log[100] = '\0';    
//				}
//				
//			}
//			nomor[top_no] = '\0';
//			angka[++index_angka] = strtod(nomor, NULL);
//			bilangan = angka[index_angka--];
//			bilangan2 = angka[index_angka];
//			angka[index_angka]=processLogarithm(bilangan,bilangan2,operator_log);
//			
//			printf("hasil: %lf\n", angka[0]);
//	
//			return 0;
//		}
//	}
//}

//output logaritma
//void resultLogarithm(double result)
//{
//	printf("Hasil : %lf", result);
//}

//rumus power (opsional)
//double power(double x, int n) {
//    double result = 1;
//    int i;
//    
//    if (n > 0) {
//        for (i = 1; i <= n; i++) {
//            result *= x;
//        }
//    } else if (n < 0) {
//        for (i = 1; i <= -n; i++) {
//            result /= x;
//        }
//    }
//    
//    return result;
//}
#endif
