/* File  : drivlist.c			*/
/* Desk  : Driver list1.c		*/
/*         ANI RAHMANI / 23501007	*/
/* Tgl	 : 25/10/01			*/
/* Tgl modifikasi List1.c : 15/11/01    */

#include "list1.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{	/* Kamus */
	List L,L1,L3;
	infotype cari,X;
	address PS;
	int i,N;

	/* Algoritma */
	/* CREATE LIST & MENGISI ELEMEN LIST */
	 printf("Jumlah elemen List yang akan dimasukkan = ");
	 scanf("%d",&N);
	 CreateList(&L);
	 printf("List baru di-Create ");PrintInfo(L);

	 printf("\nIsi List setelah diisi sec.otomatis ");
	 for(i=1;i<=N;i++)
	 { /** Isi List sec. otomatis i*2   **/
			InsVLast(&L,i*2);
	 }
	 printf("List L = ");
	 PrintInfo(L);

	 /* INSERT Elemen List */
	 InsVLast(&L,9);          //insert node di ujung/tail
	 InsVFirst(&L,3);         //insert node di awal/head
	 printf("List L setelah Insert ");PrintInfo(L);

	 /* Beberapa operasi terhadap elemen List */
	 printf("Jumlah Elemen List = %d\n",NbElmt(L));
	 printf("Max Elemen = %d di addres %p \n",Max(L),AdrMax(L));
	 printf("Min Elemen = %d di addres %p \n",Min(L),AdrMin(L));
	 printf("Average = %5.2f\n",Average(L));

	 InversList(&L);  /* Inverse tanpa Alokasi */
	 printf("List L setelah Invers tanpa Alokasi =");PrintInfo(L);
	 L1=FInversList(L); /*Inverse dengan ALokasi */
	 printf("List L1 hasil Invers L dgn Alokasi = ");PrintInfo(L1);

	 CopyList(L1,&L3);
	 printf("Isi L3 ; copy dari L1 = ");PrintInfo(L3);

	 /*DelAll(&L3);
	 printf("L3 setelah dihapus = ");PrintInfo(L3);*/

	 printf("Masukkan nilai yang dicari di L1 : ");
	 scanf("%d",&cari);
	 PS=Search1(L1,cari); // Search1 akan menghasilkan address PS
	 printf("Nilai yg dicari ada di Address %p \n",PS);
	 printf("Ada ? == %d\n",FSearch(L1,PS)); // 1 jika ada

	 /* ** DEL-DEl -an ** */
/*	 printf("Data yang akan di Del dari List L1 = ");
	 scanf("%d",&X);
	 DelP(&L1,X);
	 PrintInfo(L1);
*/
	 printf("Penghapusan ELemen \n");
	 DelFirst(&L1,&PS);
	 printf("L1 setelah elemen first %d di-Del = ",PS);PrintInfo(L1);

	 DelVFirst(&L1,&X);
	 printf("L1 didel lagi elemen first %d = ",X);PrintInfo(L1);

	 DelVLast(&L1,&X);
	 printf("L1 setelah elemen Last %d di del = ",X);
	 PrintInfo(L1);


	return 0;
}

