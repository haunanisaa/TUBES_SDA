/* Program : main.c
 * Deskripsi : main driver Aplikasi Layanan Dokter Hewan
 * Nama : Hilma Sri Rahayu
 * Tanggal : 22 Juli 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Queue.h"

int main (){
	system("cls");
	system("COLOR F4");
	Queue Q;
	CreateQueue (&Q);
	
	int menuPilihan;
	
	do{
	printf("					====================================\n");
	printf("					||      Layanan Dokter Hewan      ||\n");
	printf("					||            NINUNINU            ||\n");
	printf("					------------------------------------\n");
	printf("					||     By: Hilma SR & Nisa HY     ||\n");
	printf("					====================================\n");
    	printf("					||  1. Registrasi                 ||\n");
    	printf("					||  2. Lihat Antrian              ||\n");
    	printf("					||  3. Proses Pelayanan           ||\n");
    	printf("					||  4. Keluar                     ||\n");
    	printf("					====================================\n\n");
    	printf("					Menu Pilihan : "); scanf("%d", &menuPilihan);
    	
    	if(menuPilihan == 1){
    		Registrasi(&Q);
    		PrintQueue(Q);
    		getch();
		}
		else if(menuPilihan == 2){
			PrintQueue(Q);
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

