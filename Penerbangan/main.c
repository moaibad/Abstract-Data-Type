#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Menu();

int main(int argc, char *argv[]) {
	Queue Q;
	int pilihMenu,koper,datang;
	char nama[20];
	CreateQueue(&Q);
	
	/*AddQue(&Q, "Yujeng", 3, 2);
	AddQue(&Q, "Marsha", 1, 3);
	AddQue(&Q, "Chensing", 4, 20);
	AddQue(&Q, "Rahul", 2, 24);*/
	
	while(pilihMenu != 3){
		system("cls");
		printf("=======================");
		printf("\nIsi List Sekarang : \n\n");

		CetakQueue(Q);
		printf("\n=======================\n");
		
		Menu();
		scanf("%d",&pilihMenu);

		switch(pilihMenu){
			case 1 : 
				printf("Nama : ");scanf("%s",nama);
				printf("Waktu Kedatangan : ");scanf("%d",&datang);
				printf("Jumlah Koper : ");scanf("%d",&koper);
				AddQue(&Q, nama, koper, datang);
				printf("\nPenumpang %s telah ditambahkan ke dalam antrian",nama);
				getch();
				break;

			case 2 :
				DelQue(&Q);
				getch();
				break;

			case 3 :
				return 0;
		}
	}
}

void Menu(){
	printf("Pilih Menu Di bawah ini :\n\n");
	printf("1. Tambah Antrian\n");
	printf("2. Hapus Antrian\n");
	printf("3. Keluar Program\n");

	printf("\nPilihan : ");
}
