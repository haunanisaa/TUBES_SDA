/* Program : Queue.c
 * Deskripsi : Implementasi body dari Queue.h
 * Nama : Nisa Hauna
 * Tanggal : 18 Juli 2021
 * Compiler : GCC
 */

#include "Queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

 /***** Manajemen memori *****/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
 * Jika alokasi berhasil, modul mengembalikan P; Info(P) = X, Next(P) = NULL.
 * P adalah pointer yang menunjuk ke node Queue sebagai hasil alokasi.
 * Jika alokasi gagal, modul mengembalikan NULL.
 */
addrNQ Alokasi(infotype X){
	addrNQ P;
    P = (addrNQ)malloc(sizeof(NodeQueue));

    if(P != Nil) { /* Berhasil  */
        P->info = X;
        P->next = Nil;
        return P;
   	} else {
   		return Nil;
	}
}

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node
queue).
* I.S.: P terdefinisi.
* F.S.: P dikembalikan ke sistem.
*/
void Dealokasi(addrNQ *P){
	(*P)->next = Nil;
    free(*P);
}

/***** Manajemen Queue *****/
/* Membuat sebuah Queue kosong dengan Front(Q) = Nil dan Rear (Q) = Nil 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
*/
void CreateQueue(Queue *Q){
	(*Q).Front = Nil;
	(*Q).Rear = Nil;
}

/* Mengetahui apakah Queue kosong atau tidak. 
   mengirimkan true, jika Queue Kosong yaitu Front(Q) = Nil dan Rear (Q) = Nil
   Sebaliknya false
*/
bool IsQueueEmpty(Queue Q){
	if (Q.Front == Nil && Q.Rear == Nil) {
		return true;
	} else {
		return false;
	}
}

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */ 
/* F.S. info baru (data) menjadi Rear yang baru dengan node Rear yang lama mengaitkan pointernya ke node yang baru */ 
void enQueue(Queue *Q, infotype data){
	addrNQ P = Alokasi(data);
    if(P != Nil) {
        // Proses enQueue
        if (IsQueueEmpty((*Q))) { // Jika Queue Kosong
            (*Q).Front = P;
            (*Q).Rear = P;
        } else { // Jika Queue Tidak Kosong
        	if(Front(*Q) == Rear(*Q)){
        		if (P->info.nilaiPrioritas > (*Q).Front->info.nilaiPrioritas){
        			(*Q).Front=P;
        			P->next=(*Q).Rear;
				} else {
					(*Q).Rear = P;
					(*Q).Front->next = P;
				}
			} else {
				if(P->info.nilaiPrioritas > (*Q).Front->info.nilaiPrioritas){
					P->next = (*Q).Front;
					(*Q).Front = P;
				} else if (P->info.nilaiPrioritas <= (*Q).Rear->info.nilaiPrioritas){
					(*Q).Rear->next = P;
					P = (*Q).Rear;
				} else {
					addrNQ move;
					addrNQ after;
					addrNQ before;
					
					move = (*Q).Front;
					do {
						before = move;
						move = move->next;
					} while (move->info.nilaiPrioritas >= P->info.nilaiPrioritas);
					
					if (move->next != Nil){
						after = move->next;
						if (move->info.nilaiPrioritas < P->info.nilaiPrioritas){
							before->next = P;
							P->next = move;
						} else {
							while (move->info.nilaiPrioritas <= after->info.nilaiPrioritas){
								if (move->info.nilaiPrioritas > after->info.nilaiPrioritas){
									P->next = after;
									move->next = P;
								}
								move = after;
								after = after->next;
							}
						}
					} else if (move->next==Nil){
						before->next = P;
						P->next = move;
					}
				}	
			}
        }
    }
}

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari Queue dengan aturan FIFO */ 
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */  
/* F.S. info yang diambil = nilai elemen Front pd I.S. */ 
/* Front(Q) menunjuk ke next antrian atau diset menjadi NIll, Q mungkin kosong */ 
void deQueue(Queue *Q, infotype *data){
	addrNQ P;

    // Proses deQueue
    if (IsQueueEmpty((*Q))) { // Jika Queue Kosong
		printf("	Antrian Masih Kosong \n");
	} else  {
		if((*Q).Front == (*Q).Rear) { // Jika Queue hanya berisi 1 Buah Elemen
            (*data) = (*Q).Front->info;
            P = (*Q).Front;
            Dealokasi(&P);
            (*Q).Front = Nil;
            P = (*Q).Rear;
            Dealokasi(&P);
            (*Q).Rear = Nil;
        } else { // Jika Queue berisi lebih dari 1 elemen
            (*data) = (*Q).Front->info;
            P = (*Q).Front;
            (*Q).Front = (*Q).Front->next;
            P->next = Nil;

            Dealokasi(&P);
        }
	}
}

/* Mengirimkan banyaknya elemen queue jika Q berisi atrian atau 
   mengirimkan 0 jika Q kosong 
*/ 
int NBElmt(Queue Q){
	addrNQ P;
    int jmlElement = 0;

	if(IsQueueEmpty(Q)){
		jmlElement = 0;
	} else{
        P = Q.Front;
        do {
            jmlElement++;
            P = P->next;
        } while(P != Nil);
	}

	return jmlElement;
}

char *arrPenyakit[9] = {
	"Penyakit Kulit",
	"Luka Ringan",
	"Bersin",
	"Cacingan",
	"Diare",
	"Luka Dalam",
	"Kerongkongan Berlendir dan Berbau Busuk",
	"Penyakit Kuning",
	"Terkena Virus"
};

/* Melakukan pencetakan daftar penyakit hewan */
void printPenyakit(){
	int i;
	for (i=0; i<9; i++){
		printf("	%d. %s\n",i+1, arrPenyakit[i]);
	}
}

/* Proses : Melakukan pengecekan kategori penyakit hewan berdasarkan nilai prioritas antrian */
char *kategoriPenyakit(int Penyakit){
	if (Penyakit<4){
		return "Ringan";
	} else if (Penyakit<7){
		return "Sedang";
	} else if (Penyakit<10){
		return "Berat";
	}	
}

/* Menentukan nilai prioritas dari suatu antrian berdasarkan jumlah penyakit yang diderita */
int HitungNilaiPrioritas(int Ringan, int Sedang, int Berat){
	int nilai = 1;
	if (Berat >= 1){
		nilai += 4;
	}
	if (Sedang >= 2){
		nilai += 3;
	}
	if (Ringan >= 3){
		nilai += 2;
	}
	
	return nilai;
}

/* Mengembalikan waktu estimasi pelayanan berdasarkan nilai prioritas antrian */
int PeriksaWaktuEstimasi(int Penyakit){
	if (Penyakit<4){
		return 15;
	} else if (Penyakit<7){
		return 30;
	} else if (Penyakit<10){
		return 45;
	}
}

/* Menghitung waktu estimasi pelayanan */
int HitungWaktuEstimasi(int Ringan, int Sedang, int Berat){
	return (Ringan*15) + (Sedang*30) + (Berat*45);
}

/* Menghitung waktu mulai pelayanan */
void HitungWaktuMulai(Queue *Q, infotype *X){
	addrNQ P, T;
	
	P = (*Q).Front;
	if(IsQueueEmpty(*Q)){
		X->waktuMulai = X->waktuDatang;
	} else {
		if(X->nilaiPrioritas > P->info.nilaiPrioritas){
			X->waktuMulai = P->info.waktuMulai;
			P->info.waktuMulai = X->waktuAkhir;
			do {
				Next(P)->info.waktuMulai = P->info.waktuAkhir;
				P = Next(P);
			} while (Next(P) != Nil);
		} else if(X->nilaiPrioritas <= P->info.nilaiPrioritas){
			do {
				if(X->nilaiPrioritas <= P->info.nilaiPrioritas){
					T = P;
					P = P->next;
				} else {
					X->waktuMulai = P->info.waktuMulai;
					P->info.waktuMulai = X->waktuAkhir;
					do {
						Next(P)->info.waktuMulai = P->info.waktuAkhir;
						P = P->next;
					} while (P->next != Nil);
					break;
				}
			} while (P != Nil);
		}
	}
}

/* Menghitung waktu selesai pelayanan */
void HitungWaktuSelesai(Queue *Q, infotype *X){
	addrNQ P, T;
	
	P = (*Q).Front;
	if(IsQueueEmpty(*Q)){
		X->waktuAkhir = X->waktuDatang + X->waktuEstimasi;
	} else {
		if(X->nilaiPrioritas > P->info.nilaiPrioritas){
			X->waktuAkhir = X->waktuMulai + X->waktuEstimasi;
			P->info.waktuAkhir = P->info.waktuMulai + P->info.waktuEstimasi;
			do {
				Next(P)->info.waktuAkhir = P->info.waktuAkhir + Next(P)->info.waktuEstimasi;
				P = Next(P);
			} while (Next(P) != Nil);
		} else if(X->nilaiPrioritas <= P->info.nilaiPrioritas){
			do {
				if(X->nilaiPrioritas <= P->info.nilaiPrioritas){
					T = P;
					P = P->next;
				} else {
					X->waktuAkhir = X->waktuMulai + X->waktuEstimasi;
					P->info.waktuAkhir = P->info.waktuMulai + P->info.waktuEstimasi;
					do {
						Next(P)->info.waktuAkhir = P->info.waktuAkhir + Next(P)->info.waktuEstimasi;
						P = P->next;
					} while (P->next != Nil);
					break;
				}
			} while (P != Nil);
		}
	}
} 

/* Proses: Melakukan Pencetakan Daftar Antrian dari suatu Queue */
/* Proses Print dilakukan secara traversal */
void printQueue(Queue Q){
	system("cls");
	addrNQ P;
	
	int i=1, j;
	int lenght;
	
	if(IsQueueEmpty(Q)){
		printf("	* Tidak Ada Antrian yang Terdaftar *\n\n");
	} else {
		P = Q.Front;
		printf("	====================================\n");
		printf("	           Daftar Antrian\n");
		printf("	====================================\n");
		while(P != Nil){
			printf("	No. Antrian                 : %d\n", i++);
			printf("	Nama Hewan                  : %s\n", P->info.nama);
			printf("	Datang di menit ke          : %d\n", P->info.waktuDatang);
			printf("	Penyakit yang Diderita      : ");
			PrintInfo(P->info.listPenyakit, arrPenyakit);
			printf("	Nilai Prioritas             : %d\n", P->info.nilaiPrioritas);
			printf("	Estimasi Waktu Pelayanan    : %d\n", P->info.waktuEstimasi);
			printf("	Waktu Mulai Pelayanan       : %d\n", P->info.waktuMulai);
			printf("	Waktu Selesai Pelayanan     : %d\n", P->info.waktuAkhir);
			
			printf("	------------------------------------\n");
			
			P = Next(P);
		}		
	}
}

/* Melakukan registrasi penambahan data pelanggan 
 * I.S = Q mungkin kosong atau Q mungkin berisi antrian
 * F.S = Data baru ditambahkan ke antrian */
void Registrasi(Queue *Q){
	system("cls");
	infotype X;
	CreateList(&X.listPenyakit);
	infoPenyakit Y;
	
	int tempPenyakit[9];
	int i, totalPenyakit;
	
	printf("	====================================\n");
	printf("	             Registrasi\n");
	printf("	====================================\n");
	printf("	Nama Hewan                  : "); scanf("%s", &X.nama);
	fflush(stdin);
	printf("	Datang di menit ke          : "); scanf("%d", &X.waktuDatang);
	fflush(stdin);
	
	printf("\n");
	printf("	*** List Penyakit ***\n");
	printPenyakit();
	printf("\n");
	printf("	Jumlah Penyakit             : "); scanf("%d", &totalPenyakit);
	printf("	No. Penyakit yang Diderita  : ");
	for (i=0; i<totalPenyakit; i++){
		scanf("		%d", &tempPenyakit[i]);
	}
	
	int countR = 0;
	int countS = 0;
	int countB = 0;
	for (i=0; i<totalPenyakit; i++){
		Y.Penyakit = tempPenyakit[i];
		strcpy(Y.kategori, kategoriPenyakit(tempPenyakit[i]));
		Y.waktuEstimasi = PeriksaWaktuEstimasi(tempPenyakit[i]);
		InsVLast(&X.listPenyakit, Y);
		
		if ((tempPenyakit[i]>0) && (tempPenyakit[i]<4)){
			countR++;
		}
		if ((tempPenyakit[i]>=4) && (tempPenyakit[i]<7)){
			countS++;
		}
		if ((tempPenyakit[i]>=7) && (tempPenyakit[i]<10)){
			countB++;
		}
	}
	X.nilaiPrioritas = HitungNilaiPrioritas(countR, countS, countB);
	X.waktuEstimasi = HitungWaktuEstimasi(countR, countS, countB);
	HitungWaktuMulai(*(&Q), &X);
	HitungWaktuSelesai(*(&Q), &X);
	
	enQueue(Q, X);
	printf("\n");
	printf("	Ketik apa saja untuk lanjut! \n\n");
	getch();
}

/* Memproses antrian untuk dilakukan pelayanan sehingga hewan keluar dari antrian 
 * I.S = Q mungkin kosong atau Q mungkin berisi antrian
 * F.S = Data yang di proses akan keluar dari antrian */
void prosesAntrian(Queue *Q){
	infotype X;
	char pilih='Y';
	
	
	if(IsQueueEmpty(*Q)){
		printf("\n");
        printf("	* Tidak Ada Antrian yang Terdaftar *\n\n");
    } else {
    	while(pilih=='Y' && !IsQueueEmpty(*Q)){
    	printf("	====================================\n");
		printf("	           Proses Antrian\n");
		printQueue(*Q);
		printf("	Memulai Proses Pelayanan [Y/N]? "); 
		fflush(stdin);
		scanf("%c", &pilih);
		
		if(pilih=='Y'){
			deQueue(Q, &X);
		}
    	}
	}

    getch();
}
