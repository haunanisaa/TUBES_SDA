/* Program : main.c
 * Deskripsi : main driver Aplikasi Layanan Dokter Hewan
 * Nama : Hilma Sri Rahayu
 * Tanggal : 22 Juli 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "queue.h"

int main (){
	System("cls");
	System("COLOR F4");
	Queue Q;
	CreateQueue (&Q);
	
	int menuPilihan;
	
	do{
	printf("========Aplikasi Layanan Dokter Hewan========\n\n");
    	puts("1. Registrasi\n");
    	puts("2. Lihat Antrian\n");
    	puts("3. Proses Pelayanan\n");
    	puts("4. Keluar\n\n");
    	printf("Menu Pilihan : \n"); scanf("%d", &menuPilihan);
    	
    	if(menuPilihan == 1){
    		Registrasi(&Q);
    		PrintQueue(Q);
    		getch();
		}
		else if(menuPilihan == 2){
			PrintQueue(Q);
			puts("sfdsdf");
		}
		else if(menuPilihan == 3){
			//belum
		}
		else if(menuPilihan == 4){
			exit(0);
		}
		else{
			printf("	  Masukan anda salah\n");
			printf("	Masukan angka dari 1-4\n");
			printf("	  Silakan coba lagi");
		}

	}
	while(menuPilihan !=4);
	return 0;
}

