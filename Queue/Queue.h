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

#include <stdbool.h>
#include "boolean.h"
#include "LIST1.H"

#define Nil 0
#define Front(Q) (Q).Front 
#define Rear(Q) (Q).Rear 
#define InfoFront(Q) (Q).Front->info 
#define InfoRear(Q) (Q).Rear->info  
#define Info(P) (P)->info  

/* Definisi elemen dan address */ 
typedef struct {
	/* Kategori penyakit kucing (Ringan, Sedang, Berat)
	 * Ditentukan dari parameter penyakit
	 */
	char *kategoriPenyakit; 
	/* List penyakit berupa string yang akan di define menajdi integer
	 * dan akan menjadi pertimbangan di prioritas queue
	 */
	List namaPenyakit;
	/* Nilai parameter penyakit pada linked list namaPenyakit */
	int parameterPenyakit; 
}penyakit;
typedef infoPelanggan {
	char nama[25]; // Nama Kucing
	int waktuDatang; // Waktu Kedatangan
	int waktuEstimasi; // Lama Waktu Estimasi Pelayanan
	int waktuMulai; // Waktu Estimasi Kucing Mulai Dilayani
	int waktuAkhir; // Waktu Estimasi Kucing Selesai Dilayani
	penyakit sakit; // Tipe Penyakit Kucing
}infoPelanggan;
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

/* Proses: Melakukan Print Daftar Antrian dari suatu Queue */
/* Proses Print dilakukan secara traversal */
void printQueue(Queue Q);


#endif // QUEUE_H
