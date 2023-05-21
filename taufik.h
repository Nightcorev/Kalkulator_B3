#ifndef taufik_h
#define taufik_h
#include <stdio.h>
#include "ikhsan.h"
#include "Afyar.h"
#include "alfien.h"
#include "Zia.h"
#include "Fikri.h"


//Deklarasi Modul Tampilan
void menu_kalkulator_scientifik();
double proses_operasi(address Troot);
void EnqueOperator(Queue *listQ,char item);
void EnqueOperand(Queue *Q,float item);
void proses_kalkulator(Queue *listQ, char* input, char* kembali);

//Isi Program


void menu_kalkulator_scientifik(){
	printf("\n\t\t\t------------------------------------------------------");
	printf("\n\t\t\t|               Scientifik Kalkulator                |");
	printf("\n\t\t\t|                   Kelompok B3                      |");
	printf("\n\t\t\t|----------------------------------------------------|");
	printf("\n\t\t\t| Keterangan :                                       |");
	printf("\n\t\t\t| (^) = untuk operasi perpangkatan                   |");
	printf("\n\t\t\t| (m) = untuk operasi modulus                        |");
	printf("\n\t\t\t| (v) = untuk operasi akar pangkat n                 |");
	printf("\n\t\t\t| (log) = untuk operasi logaritma                    |");
	printf("\n\t\t\t| (ln) = untuk operasi natural logaritma             |");
	printf("\n\t\t\t| (!) = untuk operasi faktorial                      |");
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
	printf("\n\t\t\t| 5. untuk operasi faktorial                         |");
	printf("\n\t\t\t|    contohnya seperti berikut : 2!                  |");
	printf("\n\t\t\t------------------------------------------------------");
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
			
		}else if(Troot->data=='v'){ //Mengecek apakah subvar data pada Troot ialah karakter '&'
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

void proses_kalkulator(Queue *listQ, char* input, char* kembali){
	/*referensi https://en.wikipedia.org/wiki/Shunting_yard_algorithm#:~:text=In%20computer%20science%2C%20the%20shunting,abstract%20syntax%20tree%20(AST). 
	Proses Infix to Postfix*/
	
	
	node P;
	Stack listS;
	char token,oprtr,negatif;
	int num3=10;
	int i,temp;
	double num=0,num2;
	double angka;
	int j;
	
	listS.Head=NULL;
	for(i=0;i<strlen(input);i++){
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
		}else if (token=='s' || token=='c' || token=='t'){ 		// Jika token merupakan operator trigonometri (s, c, t, a)
			char trigono[5];
			char sudut[20];
			int x=0;
			int j=0;
			float hasil;
			double angka1;
			
			// memeriksa apakah karakter sebelum operator trigonometri bukan digit
			if(!isdigit(input[i-1])){
				while(input[i]!=')'&&i<strlen(input)){ 
				//  loop akan membaca karakter-karakter setelah operator trigonometri hingga menemui tanda kurung tutup (')') atau akhir dari input.
				
					if(isdigit(input[i]) || input[i]=='.'){ // Mengecek apakah karakter saat ini merupakan digit atau desimal yang akan disimpan di sudut
						sudut[j++]=input[i];
					} else{ // jika bukan akan dianggap huruf bagian dari trigonometri seperti cos/sin/tan
						trigono[x++]=input[i];
					}
					i++;
				}
				if(input[i]!=')'){ // jika tidak ada tanda kurung tutup akan kembali ke menu utama
					*kembali='y';
				}
				trigono[x]='\0'; // dimaksud untuk mengakhiri dari string trigono dengan menambahkan karakter null ke array trigono
				sudut[j]='\0'; // dimaksud untuk mengakhiri dari string sudut dengan menambahkan karakter null ke array sudut
				angka=strtod(sudut, NULL); // mengubah nilai yang ada di sudut menjadi float dan ditampung di angka
				hasil=operasi_trigono(angka,trigono,&*kembali); // memanggil modul dari header ikhsan.h untuk mengoprasikan trigonometri dan mendapatkan nilai hasilnya
				EnqueOperand(&*listQ, hasil);	// menyimpan hasil ke queue
			}else{
				/*Jika karakter sebelum operator trigonometri adalah digit, berarti operator trigonometri tersebut menerima operand dari antrian operand */
				angka1=DequeOperand(&*listQ); // mengambil operand sebelum trigono dan disimpan ke angka1
				while(input[i]!=')'){
						//  loop akan membaca karakter-karakter setelah operator trigonometri hingga menemui tanda kurung tutup (')') atau akhir dari input.
					if(isdigit(input[i]) || input[i]=='.'){ // Mengecek apakah karakter saat ini merupakan digit atau desimal yang akan disimpan di sudut
						sudut[j++]=input[i];
					} else{ // jika bukan akan dianggap huruf bagian dari trigonometri seperti cos/sin/tan
						trigono[x++]=input[i];
					}
					i++;
				}
				trigono[x]='\0'; // dimaksud untuk mengakhiri dari string trigono dengan menambahkan karakter null ke array trigono
				sudut[j]='\0'; // dimaksud untuk mengakhiri dari string sudut dengan menambahkan karakter null ke array sudut
				angka=strtod(sudut, NULL); // mengubah nilai yang ada di sudut menjadi float dan ditampung di angka
				hasil=operasi_trigono(angka,trigono,&*kembali); // memanggil modul dari header ikhsan.h untuk mengoprasikan trigonometri dan mendapatkan nilai hasilnya
				hasil*=angka1; // mengalikan operand sebelum logaritma dengan hasil
				EnqueOperand(&*listQ, hasil); // menyimpan hasil ke queue
			}
			// Jika token merupakan operator matematika , Stack tidak kosong dan pada Head stack bukan tanda '(' dan ada bilangan sebelum operator
		}else if(isOperator(token)&&listS.Head!=NULL&&listS.Head->oprtr!='('&&isdigit(input[i-1])){
			oprtr=listS.Head->oprtr; // Mengambil operator yang ada di bagian paling atas dari stack
			while(derajatOperator(token)<=derajatOperator(oprtr)&&listS.Head!=NULL&&listS.Head->oprtr!='('){
				/* Loop ini akan berjalan selama derajat operator saat ini (token) lebih kecil atau sama dengan derajat operator di puncak stack (oprtr), 
				stack operator tidak kosong, dan operator di puncak stack bukan tanda kurung buka ('('). Catatan derajatOperator dipanggil dari Fikri.h*/
				EnqueOperator(&*listQ,PopStack(&listS));
			}
			listS=PushStack(listS,token); // Melakukan push stackt atau menyimpan node baru  ke stack menggunakan modul dari Afyar.h
		}else if(token==')'){
			oprtr=listS.Head->oprtr;
			while(oprtr!='('&&listS.Head->next!=NULL){
				// Melakukan looping selama operator di puncak stack (oprtr) bukan tanda kurung buka '(' dan stack operator memiliki lebih dari satu elemen
				EnqueOperator(&*listQ,PopStack(&listS));
				oprtr=listS.Head->oprtr;
			}
			if(oprtr=='('){ // Setelah looping mengecek apakah operator di head stack tanda '(' jika iya akan melakukan Pop stack jika bukan akan menampilkan format salah
				PopStack(&listS); //PopStack menggunakan modul dari Afyar.h
			}else{
				printf("format yang dimasukkan salah\n");
				break;
			}
		}// Jika token adalah karakter 'l' (untuk logaritma)
		else if (token == 'l'){
			char log[10];
			char Num[100];
			float angka;
			float a, hasil;
			int j = 0, x = 0;

			// Membaca basis logaritma dan bilangan
			if (isdigit(input[i-1])){
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
			hasil = processLogarithm(angka, a, log, &*kembali); // mengambil hasil yang dilakukan di modul prosesLogarithm
			EnqueOperand(&*listQ, hasil);	
			}
			else{
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
				hasil = processLogarithm(angka, 10, log, &*kembali); // mengambil hasil yang dilakukan di modul prosesLogarithm
				EnqueOperand(&*listQ, hasil);
			}

		}else if(token=='('){ // token ialah tanda kurung buka maka dimasukkan ke stack
			listS=PushStack(listS,token);
		}else if(token=='!'){
			float numFaktor,hasil;
			char t;
			t=token;
			// Mengecek Jika operand sebelumnya adalah bilangan
			if (isdigit(input[i - 1])){ 
				numFaktor = DequeOperand(&*listQ); // mengambil nilai dari bilangan sebelum karakter ! menggunakan modul Deque
				hasil = faktorial(numFaktor);  // Mengambil hasil proses faktorial dari modul faktorial() dari Fikri.h
				EnqueOperand(&*listQ, hasil);
			}else{
				*kembali='y';
			}
		}
		else if(token=='v'&&!isdigit(input[i-1])){
			// memeriksa apakah token saat ini adalah operator akar kuadrat, yaitu 'v'.  dan apakah karakter sebelum operator akar kuadrat bukan digit
			i++;
			float hasilakarkuadrat=0;
			int plus=0;
			char num[20];
			float num1;
			while(isdigit(input[i])||input[i]=='.'){
				// Selama  karakter saat ini adalah digit atau titik desimal, loop akan berjalan untuk membaca karakter-karakter tersebut dan menyimpannya dalam array num.
				num[plus++]=input[i];
				i++;
			}
			num1=strtof(num,NULL); // mengubah nilai num menjadi float
			hasilakarkuadrat=hitung_akar(num1,2); // melakukan operasi hitung akar yang diambil dari model di Afyar.h
			EnqueOperand(&*listQ,hasilakarkuadrat); //memasukkan hasilnya kedalam queue
		}else{
			// Jika token bukan karakter di atas, diasumsikan sebagai operator matematika dan dimasukkan ke dalam Stack
			listS=PushStack(listS,token);
		}
	}
	while(listS.Head!=NULL){
		// Mengosongkan Stack ke dalam Queue dengan melakukan looping sampai isi Stack kosong atau head bernilai Null
		oprtr=PopStack(&listS);
		EnqueOperator(&*listQ,oprtr);
	}
}
#endif
