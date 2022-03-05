#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void Menu();
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	List List;
	char pilih;
	int pilihMenu;
	infotype X,Y;
	
	printf("Apakah anda ingin membuat list? [Y/N] : ");
	scanf(" %c",&pilih);
	
	switch(pilih){
		case 'Y' :
		CreateList(&List);
		printf("\n=======================");
		printf("\nList berhasil dibuat!");
		printf("\nIsi List Sekarang : ");
		PrintInfo(List);
		printf("\n=======================\n");
		system("pause");
		
		do{
			system("cls");
			printf("=======================");
			printf("\nIsi List Sekarang : ");
			PrintInfo(List);
			printf("\n=======================\n");
			Menu();
			scanf("%d",&pilihMenu);
			
			switch(pilihMenu){
				case 1 : 
					printf("Masukan elemen : ");scanf("%d",&X);
					system("cls");			
					InsVFirst(&List,X);break;
				
				case 2 :
					printf("Masukan elemen : ");scanf("%d",&X);
					InsVLast(&List,X);break;
				
				case 3 :
					printf("Masukan elemen : ");scanf("%d",&X);
					printf("Masukan mau di depan elemen mana : ");scanf("%d",&Y);
					InsVAfter(&List,X,Y);
					break;
				
				case 4 :
					DelVFirst(&List,&X);
					printf("Elemen di depan telah terhapus!");
					getch();
					break;
				
				case 5 :
					DelVLast(&List,&X);
					printf("Elemen di belakang telah terhapus!");
					getch();
					break;
										
				case 6 :
					printf("Masukan elemen yang mau dihapus : ");scanf("%d",&X);
					DelP(&List,X);
					printf("Elemen %d telah terhapus!",X);
					getch();
					break;
				
				case 7 :
					DelAll(&List);
					printf("Semua elemen telah terhapus!");
					getch();
					break;
				case 8 :
					printf("Jumlah elemen pada list adalah : %d",NbElmt(List));
					getch();
					break;	
				case 9 :
					printf("Nilai maksimal elemen pada list adalah : %d",Max(List));
					getch();
					break;
				case 10 :
					printf("Nilai minimal elemen pada list adalah : %d",Min(List));
					getch();
					break;
				case 11 :
					printf("Nilai rata-rata elemen pada list adalah : %d",Average(List));
					getch();
					break;	
				case 12 :
					printf("Program dihentikan!");
					break;
				default : printf("Masukan insert yang valid!");break;
			}
		
		}while(pilihMenu != 12);
				
		
		case 'N' : return 0; 	
	}
	return 0;
}

void Menu(){
	printf("Pilih Menu Di bawah ini :\n\n");
	printf("1. Memasukan elemen di depan list\n");
	printf("2. Memasukan elemen di belakang list\n");
	printf("3. Memasukan elemen di tengah list\n");
	printf("4. Menghapus elemen di depan list\n");
	printf("5. Menghapus elemen di belakang list\n");
	printf("6. Menghapus elemen di tengah list\n");
	printf("7. Menghapus semua elemen pada list\n");
	printf("8. Menghitung jumlah elemen pada list\n");
	printf("9. Mencari nilai maksimal elemen pada list\n");
	printf("10. Mencari nilai minimal elemen pada list\n");
	printf("11. Mencari nilai rata-rata elemen pada list\n");
	printf("12. Keluar Program");
	
	printf("\nPilihan : ");
}
