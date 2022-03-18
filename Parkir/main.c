/* File main.c untuk Main Driver ADT Stack */
#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"

void Menu(){ 
	printf("==== PRAKTIKUM STACK ====");
	printf("\n1. Parkir");
	printf("\n2. Keluar");
	printf("\n3. Periksa Antrian");
	printf("\n\nPilihan Kamu : ");
}
/*Prosedur untuk menampilkan menu operasi stack*/

int main() {

	/* Membuat Stack */
	Stack S;
	int Arah;
	CreateEmpty(&S);

	int pilihMenu, X;
	
	while(pilihMenu != 3){
		system("cls");
	
		PrintStack(S);
		
		Menu();
		scanf("%d",&pilihMenu);

		switch(pilihMenu){
			case 1 : 
				printf("Masukan Mobil : ");scanf("%d",&X);		
				Push (&S, X);
				break;
			
			case 2 :
				printf("Masukan mobil yang ingin di keluarkan : ");scanf("%d",&X);
				printf("\nPlih Arah [1]Kanan | [2]Kiri : ");scanf("%d",&Arah);	
				KeluarParkir(&S, &X,Arah);
				break;
			
			case 3 :
				printf("Masukan elemen : ");scanf("%d",&X);	
				printf("\nMobil berada di antrian ke %d",CariMobil(S,X));
				break;
			default : printf("Kode operasi salah");getch();break;
		}
	}
	
	return 0;
}

