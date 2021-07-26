/* Program: Queue.h
 * Deskripsi: Spesifikasi ADT Queue menggunakan Linked List
 * Nama: Ardhiansyah
 * Tanggal: 23 April 2011
 * Compiler: GCC 4.9.2
 * Update: Muhammad Saiful Islam
 * Tanggal Update: 7 April 2015
 * Tanggal Update 2: 20 Mei 2015
 * Update: Asri Maspupah
 * Tanggal Update: 7 Mei 2021
 * Modifikasi : Nisa Hauna
 * Tanggal Modifikasi : 18 Juli 2021
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include "boolean.h"
#include "LIST1.H"

#define Front(Q) (Q).Front 
#define Rear(Q) (Q).Rear 
#define InfoFront(Q) (Q).Front->info 
#define InfoRear(Q) (Q).Rear->info  
#define Info(P) (P)->info 
#define Next(P) (P)->next 

/* Definisi elemen dan address */ 
typedef struct infoPelanggan {
	char nama[25]; // Nama Hewan
	int waktuDatang; // Waktu Kedatangan
	int waktuEstimasi; // Lama Waktu Estimasi Pelayanan
	int waktuMulai; // Waktu Estimasi Kucing Mulai Dilayani
	int waktuAkhir; // Waktu Estimasi Kucing Selesai Dilayani
	int nilaiPrioritas; // Nilai Prioritas Setiap Antrian Hewan
	List listPenyakit; // List Penyakit Hewan
}infoPelanggan;
typedef infoPelanggan infotype;
typedef struct NodeQueue *addrNQ;
typedef struct NodeQueue {
    infotype info; // address Node NBTree
    addrNQ next;
} NodeQueue;
typedef struct {
    addrNQ Front; // tag antrian depan
    addrNQ Rear; // tag antrian belakang
} Queue;

/***** Manajemen memori *****/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
 * Jika alokasi berhasil, modul mengembalikan P; Info(P) = X, Next(P) = NULL.
 * P adalah pointer yang menunjuk ke node Queue sebagai hasil alokasi.
 * Jika alokasi gagal, modul mengembalikan NULL.
 */
addrNQ Alokasi(infotype X);

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node queue).
 * I.S.: P terdefinisi.
 * F.S.: P dikembalikan ke sistem.
 */
void Dealokasi(addrNQ *P);

/***** Manajemen Queue *****/
/* Membuat sebuah Queue kosong dengan Front(Q) = Nil dan Rear (Q) = Nil 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
*/
void CreateQueue(Queue *Q);

/* Mengetahui apakah Queue kosong atau tidak. 
   mengirimkan true, jika Queue Kosong yaitu Front(Q) = Nil dan Rear (Q) = Nil
   Sebaliknya false
*/
bool IsQueueEmpty(Queue Q);

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */ 
/* F.S. info baru (data) menjadi Rear yang baru dengan node Rear yang lama mengaitkan pointernya ke node yang baru */ 
void enQueue(Queue *Q, infotype data);

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari Queue dengan aturan FIFO */ 
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */  
/* F.S. info yang diambil = nilai elemen Front pd I.S. */ 
/* Front(Q) menunjuk ke next antrian atau diset menjadi NIll, Q mungkin kosong */ 
void deQueue(Queue *Q, infotype *data);

/* Mengirimkan banyaknya elemen queue jika Q berisi atrian atau 
   mengirimkan 0 jika Q kosong 
*/ 
int NBElmt(Queue Q); 

/* Melakukan pencetakan daftar penyakit hewan */
void printPenyakit();

/* Proses : Melakukan pengecekan kategori penyakit hewan berdasarkan nilai prioritas antrian */
char *kategoriPenyakit(int Penyakit);

/* Menentukan nilai prioritas dari suatu antrian berdasarkan jumlah penyakit yang diderita */
int HitungNilaiPrioritas(int Ringan, int Sedang, int Berat);

/* Mengembalikan waktu estimasi pelayanan berdasarkan nilai prioritas antrian */
int PeriksaWaktuEstimasi(int Penyakit);

/* Menghitung waktu estimasi pelayanan */
int HitungWaktuEstimasi(int Ringan, int Sedang, int Berat);

/* Menghitung waktu mulai dan selesai pelayanan */
void HitungWaktu(Queue *Q, infotype *X);

/* Menghitung waktu selesai pelayanan */
/*void HitungWaktuSelesai(Queue *Q, infotype *X); */

/* Proses: Melakukan pencetakan daftar antrian dari suatu Queue 
 * Proses Print dilakukan secara traversal */
void printQueue(Queue Q);

/* Melakukan registrasi penambahan data pelanggan 
 * I.S = Q mungkin kosong atau Q mungkin berisi antrian
 * F.S = Data baru ditambahkan ke antrian */
void Registrasi(Queue *Q);

/* Memproses antrian untuk dilakukan pelayanan sehingga hewan keluar dari antrian 
 * I.S = Q mungkin kosong atau Q mungkin berisi antrian
 * F.S = Data yang di proses akan keluar dari antrian */
void prosesAntrian(Queue *Q);


#endif // QUEUE_H
