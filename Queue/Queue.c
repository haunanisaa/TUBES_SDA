/* Program : Queue.c
 * Deskripsi : Implementasi body dari Queue.h
 * Nama : Nisa Hauna
 * Tanggal : 18 Juli 2021
 * Compiler : GCC
 */
 
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
	// if (Q.Front == Nil && Q.Rear == Nil) {
	//	return true;
	// } else {
	//	return false;
	// }
	
	int jmlAntrian = NBElmt(Q);
	if (jmlAntrian == 0){
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
            (*Q).Rear->next = P;
            (*Q).Rear = P;
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
		printf("Antrian Masih Kosong \n");
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

/* Proses: Melakukan Print Daftar Antrian dari suatu Queue */
/* Proses Print dilakukan secara traversal */
void printQueue(Queue Q){
	addrNQ P;
	
	P = Q.Front;
	if(P==Nil){
		printf("Antrian Masih Kosong \n");
	} else {
		while(P != Nil){
			printf("[ %d ] - ", Info(P));
			P = P->next;
		}
		printf("[ %d ] - \n", Info(P));
	}
}
