#ifndef taufik_h
#define taufik_h
#include <stdio.h>
#include "ikhsan.h"
#include "Afyar.h"
#include "alfien.h"
#include "Zia.h"
#include "Fikri.h"
#define PHI 1.6180339887

//Deklarasi Modul Tampilan
void menu_kalkulator_scientifik();
double proses_1operasi(double bilangan1, char* opr);
double proses_operasi(address Troot);
double operasi_logaritma(double bilangan1,double bilangan2, char* logaritma);
void EnqueOperator(Queue *listQ,char item);
void EnqueOperand(Queue *Q,float item);
void proses_kalkulator(Queue *listQ, Stack *listS, char* input);
//Isi Program


void menu_kalkulator_scientifik(){
	printf("\n\t\t\t------------------------------------------------------");
	printf("\n\t\t\t|               Scientifik Kalkulator                |");
	printf("\n\t\t\t|                   Kelompok B3                      |");
	printf("\n\t\t\t|----------------------------------------------------|");
	printf("\n\t\t\t| Keterangan :                                       |");
	printf("\n\t\t\t| (^) = untuk operasi perpangkatan                   |");
	printf("\n\t\t\t| (m) = untuk operasi modulus                        |");
	printf("\n\t\t\t| (&) = untuk operasi akar pangkat n                 |");
	printf("\n\t\t\t| (!) = untuk operasi faktorial                 |");
	printf("\n\t\t\t| (%%) = untuk operasi hitung persentase              |");
	printf("\n\t\t\t|                                                    |");
	printf("\n\t\t\t| Guide :                                            |");
	printf("\n\t\t\t| 1. Tidak menggunakan spasi                         |");
	printf("\n\t\t\t| 2. untuk operasi trigonometri                      |");
	printf("\n\t\t\t|    contohnya seperti berikut : cos(90)             |");
	printf("\n\t\t\t| 3. untuk operasi logaritma                         |");
	printf("\n\t\t\t|    contohnya seperti berikut : 2log(3)             |");
	printf("\n\t\t\t| 4. untuk operasi menghitung persentase             |");
	printf("\n\t\t\t|    cara menggunakannya seperti berikut : 20%%100=20%%|");
	printf("\n\t\t\t------------------------------------------------------");
}


double proses_1operasi(double bilangan1, char* opr){
	double result = 0;
	 if (strcmp(opr, "phi(") == 0) {
        result = hitung_phi(bilangan1);
    }else{
    	printf("Invalid operator: %c", opr);
            exit(1);
	}
}



double proses_operasi(address Troot){
	if(Troot->isOperator==1){ // Mengecek apakah Troot ialah operator atau bukan
		if(Troot->data=='+'){ //Mengecek apakah subvar data pada Troot ialah karakter '+'
			// jika iya akan melakuan proses perjumlahan yang diambil dari Zia.h lalu mereturn hasilnya
			return perjumlahan(proses_operasi(Troot->left), proses_operasi(Troot->right)); 
			
		}else if(Troot->data=='-'){ //Mengecek apakah subvar data pada Troot ialah karakter '-'
			// jika iya akan melakuan proses pengurangan yang diambil dari Zia.h lalu mereturn hasilnya
			return pengurangan(proses_operasi(Troot->left), proses_operasi(Troot->right)); 
			
		}else if(Troot->data=='/'){ //Mengecek apakah subvar data pada Troot ialah karakter '/'
			// jika iya akan melakuan proses pembagian yang diambil dari Zia.h lalu mereturn hasilnya
			return pembagian(proses_operasi(Troot->left), proses_operasi(Troot->right));			
			
		}else if(Troot->data=='*'){ //Mengecek apakah subvar data pada Troot ialah karakter '*'
			// jika iya akan melakuan proses perkalian yang diambil dari Zia.h lalu mereturn hasilnya
			return perkalian(proses_operasi(Troot->left), proses_operasi(Troot->right));
			
		}else if(Troot->data=='^'){ //Mengecek apakah subvar data pada Troot ialah karakter '^'
			// jika iya akan melakuan proses perpangkatan yang diambil dari Afyar.h lalu mereturn hasilnya
			return perpangkatan(proses_operasi(Troot->left), proses_operasi(Troot->right));
			
		}else if(Troot->data=='&'){ //Mengecek apakah subvar data pada Troot ialah karakter '&'
			// jika iya akan melakuan proses hitung_akar yang diambil dari Afyar.h lalu mereturn hasilnya
			return hitung_akar(proses_operasi(Troot->left), proses_operasi(Troot->right)); 
			
		}else if(Troot->data=='m'){ //Mengecek apakah subvar data pada Troot ialah karakter 'm'
			// jika iya akan melakuan proses modulus yang diambil dari Fikri.h lalu mereturn hasilnya
			return modulus(proses_operasi(Troot->left), proses_operasi(Troot->right));
			
		}else if(Troot->data=='%'){ //Mengecek apakah subvar data pada Troot ialah karakter '%'
			// jika iya akan melakuan proses hitungPersentase yang diambil dari Afyar.h lalu mereturn hasilnya
			return hitungPersentase(proses_operasi(Troot->left), proses_operasi(Troot->right));   
			
		}else{
			 printf("\n\t\t\tInvalid operator ");
		}
	}
	// Jika Troot bukan operator makan akan mereturn bilangan operand
	return Troot->operand;
}

double operasi_logaritma(double bilangan1,double bilangan2, char* logaritma) {
    double result = 0;
    if (strcmp(logaritma, "nl(") == 0) { //Mengecek isi dari variabel logaritma menggunakan string compare  
        result = naturalLogarithm(bilangan2); // Jika berisi "nl(" akan melakukan peroses natural Logaritma dengan memanggil modul dari alfien.h
    }
    else if (strcmp(logaritma, "log(") == 0) {//Mengecek isi dari variabel logaritma menggunakan string compare  
        result =  logarithm(bilangan1,bilangan2); // Jika berisi "log(" akan melakukan peroses Logaritma dengan memanggil modul dari alfien.h
    }else{
    	printf("\n\t\t\tInvalid operator ");
	}
	return result; 
}

void EnqueOperator(Queue *listQ,char item){
	node P;
	
	P=CreateNodeList(); //Memanggil modul CrateNodeList dari alfien.h untuk membuat node queue baru
	P->oprtr=item; //memasukkan subvar oprtr dari subvar node P dengan item
	if(listQ->First==NULL){ // Mengecek apakah subvar dari listQ bernilai NULL jika iya First dan Last akan menunjuk node P dan next Last akan berisi Null
		listQ->First=P;
		listQ->Last=P;
		listQ->Last->next=NULL;
	} else{ // Jika tidak subvar next pada Last akan menunjuk node P dan Last akan berpindah pada node P 
		P->next=NULL;
		listQ->Last->next=P;
		listQ->Last=P;
	}
}

void EnqueOperand(Queue *Q,float item){
	node P;
	
	P=CreateNodeList(); //Memanggil modul CrateNodeList dari alfien.h untuk membuat node queue baru
	P->operand=item; //memasukkan subvar operand dari subvar node P dengan item
	P->isoperator=0; //subvar isOperator pada node P akan diberi nilai 0 yang menunjukan bukan Operator
	if(Q->First==NULL){ // Mengecek apakah subvar dari listQ bernilai NULL jika iya First dan Last akan menunjuk node P dan next Last akan berisi Null
		Q->First=P;
		Q->Last=P;
		Q->Last->next=NULL;
	} else{ // Jika tidak subvar next pada Last akan menunjuk node P dan Last akan berpindah pada node P 
		P->next=NULL;
		Q->Last->next=P;
		Q->Last=P;
	}
}



void proses_kalkulator(Queue *listQ, Stack *listS, char* input){
	/*referensi https://en.wikipedia.org/wiki/Shunting_yard_algorithm#:~:text=In%20computer%20science%2C%20the%20shunting,abstract%20syntax%20tree%20(AST). 
	Proses Infix to Postfix*/
	
	node P; 
	char token, oprtr, negatif;
	int num3 = 10;
	int i, temp;
	float num = 0, num2;
	float angka;
	int j;

	for (i = 0; i < strlen(input); i++){
		token = input[i]; // Inisialisasi token dengan nilai yang diinputkan satu per satu

		// Mengecek apakah token merupakan digit atau tanda negatif pada bilangan
		if (isdigit(token) || token == '.' || (token == '-' && (isOperator(input[i - 1]) || i == 0 || input[i - 1] == '('))){
			if (isdigit(token)){ // Mengecek apakah token merupakan digit
				num = num * 10 + (token - '0'); // jika iya akan dihitung lalu diubah menjadi nilai numerik yang sesuai mengunakan konversi ASCII
			}
			else if (token == '.'){ //Mengecek apakah token adalah tanda desimal
				i++;
				while (isdigit(input[i])){ // Melakukan looping dari . hingga bukan bilangan desimal
					num2 = (input[i] - '0'); // Mengambil nilai setelah tanda desimal menjadi nilai numerik
					num = num + (num2 / num3); // Menggabungkan angka sebelum tanda desimal dengan yang sesudah desimal
					num3 = num3 * 10; //Memperbarui nilai pembagi dengan mengalikan 10 agar dapat memproses digit-desimal selanjutnya dengan benar
					i++;
				}
				num3 = 10; // Mereset ulang nilai pembagi dengan 10 agar bisa nanti digunakan lagi
				i--;
			}
			else if (token == '-'){ // Mengecek apakah token - jika iya maka negatif diisi - yang menandakan bilangan negatif
				negatif = '-';
			}

			// Jika token berikutnya bukan digit atau titik desimal, maka bilangan selesai dibaca dan dimasukkan ke Queue
			if (isdigit(input[i + 1]) != 1 && input[i + 1] != '.'){
				if (negatif == '-'){ // Mengecek apakah bilangan negatif jika iya akan dikalikan -1 untuk mendapatkan nilai negatif
					num = num * -1;
				}
				negatif = '\0'; //Mereset variabel negatif menjadi variabel kosong
				EnqueOperand(&*listQ, num); // Melakukan proeses Enque atau menambahkan node ke Queue
				num = 0; //Mereset num menjadi 0
			}
		}
		// Jika token merupakan operator trigonometri (s, c, t, a)
		else if (token == 's' || token == 'c' || token == 't' || token == 'a'){
			char trigono[7];
			char sudut[20];
			int x = 0;
			j = 0;
			float hasil;

			// Membaca sudut dan operator trigonometri secara lengkap yang ada di input selama karakter saat ini bukan ')'
			while (input[i] != ')'){
				if (isdigit(input[i]) || input[i] == '.'){ // Mengecek apakah karakter saat ini merupakan digit atau desimal
					sudut[j++] = input[i];
				}
				else{ // jika bukan akan dianggap huruf bagian dari trigonometri sepreti cos/sin/tan
					trigono[x++] = input[i];
				}
				i++;
			}
			sudut[j] = '\0'; // dimaksud untuk mengakhiri dari string sudut dengan menambahkan karakter null ke arrat sudut
			angka = strtof(sudut, NULL); // mengubah nilai yang ada di sudut menjadi float dan ditampung di angka
			hasil = operasi_trigono(angka, trigono); // memanggil modul dari header ikhsan.h untuk mengoprasikan trigonometri dan mendapatkan nilai hasilnya

			EnqueOperand(&*listQ, hasil); // Melakukan proeses Enque atau menambahkan node ke Queue
		}
		// Jika token merupakan operator matematika , Stack tidak kosong dan pada Head stack bukan tanda '('
		else if (isOperator(token) && listS->Head != NULL && listS->Head->oprtr != '('){
			oprtr = listS->Head->oprtr; // Mengambil operator yang ada di bagian paling atas dari stack
			while (derajatOperator(token) <= derajatOperator(oprtr) && listS->Head != NULL && listS->Head->oprtr != '('){
				/* Loop ini akan berjalan selama derajat operator saat ini (token) lebih kecil atau sama dengan derajat operator di puncak stack (oprtr), 
				stack operator tidak kosong, dan operator di puncak stack bukan tanda kurung buka ('('). Catatan derajatOperator dipanggil dari Fikri.h*/
				EnqueOperator(&*listQ, PopStack(&*listS)); 
				oprtr = listS->Head->oprtr;
			}
			PushStack(&*listS, token, &P); // Melakukan push stackt atau menyimpan node baru  ke stack menggunakan modul dari Afyar.h
		}
		// Jika token adalah tanda kurung tutup
		else if (token == ')'){
			oprtr = listS->Head->oprtr;
			while (oprtr != '(' && listS->Head->next != NULL){ 
			// Melakukan looping selama operator di puncak stack (oprtr) bukan tanda kurung buka '(' dan stack operator memiliki lebih dari satu elemen
				EnqueOperator(&*listQ, PopStack(&*listS)); // Memimndahkan memindahkan operator-operator dari stack operator ke Queue
				oprtr = listS->Head->oprtr;
			}
			if (oprtr == '('){ // Setelah looping mengecek apakah operator di head stack tanda '(' jika iya akan melakukan Pop stack jika bukan akan menampilkan format salah
				PopStack(&*listS); //PopStack menggunakan modul dari Afyar.h
			}
			else{
				printf("format yang dimasukkan salah\n");
				break;
			}
		}
		// Jika token adalah karakter 'l' (untuk logaritma)
		else if (token == 'l'){
			char log[10];
			char Num[100];
			float angka;
			float a, hasil;
			int j = 0, x = 0;

			// Membaca basis logaritma dan bilangan (jika ada)
			if (isdigit(input[i - 1])){ // Mengecek apakah ada basis logaritmanya atau tidak
				a = DequeOperand(&*listQ); // Mengambil basis logaritma menggunakan modul Deque yang dipanggil dari ikhsan.h
				while (input[i] != ')'){ // Melakukan looping hingga menemukan tanda kurung tutup
					if (isdigit(input[i]) || input[i] == '.'){ // Mengecek apakah karakter saat ini merupakan digit atau desimal
						Num[j++] = input[i]; // jika iya akan dimasukkan ke array Num yang nantinya akan dikonversi menjadi angka
					}
					else{
						log[x++] = input[i]; //jika tidak akan dimasukkan ke array log yang akan memenuhi maksudnya apakah log atau ln
					}
					i++;
				}
				Num[j] = '\0'; // mengakhiri array Num 
				angka = strtof(Num, NULL); // mengubah kumpulan char yang ada pada array num menjadi float
				hasil = processLogarithm(angka, a, log); // mengambil hasil yang dilakukan di modul prosesLogarithm
				EnqueOperand(&*listQ, hasil);
			}
			else{ // jika tidak ada basis logaritmanya akan dianggap sebagai basis 10 lalu mealukkan hal yang sama seperti sebelumnya
				while (input[i] != ')'){
					if (isdigit(input[i]) || input[i] == '.'){
						Num[j++] = input[i];
					}
					else{
						log[x++] = input[i];
					}
					i++;
				}
				Num[j] = '\0';
				angka = strtof(Num, NULL);
				hasil = processLogarithm(angka, 10, log);
				EnqueOperand(&*listQ, hasil);
			}
		}
		// Jika token adalah karakter seru (!) untuk faktorial
		else if (token == '!'){
			float numFaktor, hasil;
			char t;
			t = token;

			// Mengecek Jika operand sebelumnya adalah bilangan
			if (isdigit(input[i - 1])){ 
				numFaktor = DequeOperand(&*listQ); // mengambil nilai dari bilangan sebelum karakter ! menggunakan modul Deque
				hasil = faktorial(numFaktor);  // Mengambil hasil proses faktorial dari modul faktorial() dari Fikri.h
				EnqueOperand(&*listQ, hasil);
			}
			else{
				printf("\t\t\tformat yang anda masukkan salah: ");
				// listQ->invalid=1;
			}
		}
		// Jika token bukan karakter di atas, diasumsikan sebagai operator matematika dan dimasukkan ke dalam Stack
		else{
			PushStack(&*listS, token, &P);
		}
	}

	// Mengosongkan Stack ke dalam Queue dengan melakukan looping sampai isi Stack kosong atau head bernilai Null
	while (listS->Head != NULL){
		oprtr = PopStack(&*listS);
		EnqueOperator(&*listQ, oprtr);
	}
}

#endif
