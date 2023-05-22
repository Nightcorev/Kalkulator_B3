#ifndef Afyar_h
#define Afyar_h
#include "header.h"
#define EPS 1e-12  //batas toleransi, selisih antara nilai perkiraan akar yang baru dengan nilai perkiraan sebelumnya.

double perpangkatan (double x, double y);
double hitungPersentase(double angka, double persen);
double hitung_akar(double n, double a);

Stack PushStack(Stack First, char item);
char PopStack(Stack *First);

double perpangkatan (double x, double y){
	double i, a;          //variabel i akan digunakan sebagai penghitung dalam perulangan, variabel a akan digunakan untuk perpangkatan sementara.
	a=x;                  //agar kita dapat mengalikan a dengan x secara berulang dalam perulangan.
	
	for (i=1; i<y; i++){  //perulangan akan berlanjut selama nilai i lebih kecil dari y, Setiap kali perulangan dilakukan nilai i akan bertambah satu.
		a *= x;           //mengalikan nilai a dengan x dan menyimpan hasilnya kembali ke variabel a.
	}
	return a;             //mengembalikan nilai a sebagai hasil perpangkatan dari x pangkat y.
}

double hitungPersentase(double angka, double persen) {
    return angka * (persen / 100);   //nilai angka dikalikan dengan hasil pembagian persen dan 100.
}


double hitung_akar(double n, double a) {
   double d = n / 128; //deklarasikan variabel d sebagai n / 128 , titik awal perkiraan akar dan digunakan sebagai nilai awal xn.
    double xn = d;     // x_n
    double xnmin1;     // x_n-1 : Starting point
    int i = 1;         //untuk menghitung jumlah iterasi yang dilakukan.

    while (d > EPS) {  //akan berjalan selama selisih perkiraan akar (d) lebih besar dari EPS.
        xnmin1 = xn;   //menyimpan nilai perkiraan akar sebelumnya (xn) ke dalam xnmin1.
        xn = xnmin1 - ((xnmin1 * xnmin1 - n) / (2 * xnmin1));  //rumus iterasi metode Newton-Raphson untuk menghitung perkiraan baru dari akar.
        d = fabs(xn - xnmin1);  //Menghitung selisih antara perkiraan akar yang baru dengan perkiraan akar sebelumnya (d).
        ++i;          //meningkatkan nilai variabel i sebagai penghitungan iterasi yang telah dilakukan.
    }
    
    return xn;   //hasil perkiraan akar yang paling akurat dikembalikan sebagai nilai dari fungsi hitung_akar.
}


Stack PushStack(Stack First, char item){
	node P;                                  //mendeklarasikan variabel P sebagai pointer ke tipe data node.
	P = (node) malloc (sizeof (ElmtList));   //mengalokasikan memori untuk P menggunakan fungsi malloc.
	if(P==NULL){                             //pengecekan apakah alokasi memori berhasil atau tidak. 
		printf("Gagal Alokasi");             
	}else{
		P->oprtr=item;              //menetapkan nilai dari item ke anggota oprtr dari elemen P.
		P->isoperator=1;            //menetapkan nilai 1 ke anggota isoperator dari elemen P.
		P->next=NULL;               //menetapkan nilai NULL ke anggota next dari elemen P.
		if(First.Head==NULL){       //pengecekan apakah tumpukan (First) masih kosong atau tidak.
			First.Head=P;           //menetapkan P sebagai Head dari tumpukan (First).
			First.Head->next=NULL;  //menetapkan NULL ke anggota next dari elemen Head pada tumpukan (First).
		}else{  
			P->next=First.Head;     //menetapkan Head dari tumpukan (First) sebagai elemen berikutnya dari P.
			First.Head=P;           //menetapkan P sebagai elemen pertama dalam tumpukan (First).
		} 
	return First;                   //mengembalikan tumpukan (First) setelah elemen baru (P) dimasukkan ke dalamnya.s
	}
}

char PopStack(Stack *First){
	node P;                  //membuat variabel P yang bertipe node.
	P=First->Head;           //mengatur variabel P menjadi alamat elemen teratas (Head) tumpukan First.
	First->Head=P->next;     //memperbarui elemen teratas tumpukan First 
	return P->oprtr;         //mengembalikan nilai operator (oprtr) dari elemen teratas yang dihapus.
	free(P);                 //menghapus memori yang dialokasikan untuk elemen teratas yang telah dihapus.
}

#endif
