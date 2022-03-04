#include <stdio.h>
#include <stdlib.h>
#include "barang.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	BARANG barang;
	char namabarang[10];
	long harga;
	char member;
	int jumlah,total;
	
	
	printf("Nama Barang   : ");
	scanf("%s",&namabarang);
	printf("Harga Barang  : ");
	scanf("%ld", &harga);
	printf("Jumlah        : ");	
	barang = CreateBarang(namabarang, harga);
	
	scanf("%d",&jumlah);	
	printf("Member? [Y/N] : ");
	scanf(" %c",&member);
	
	printf("\n\n========= Invoice =========\n");
	switch(member){
		case 'Y' :
			TampilBarang(barang);
			total = jumlah*GetHargaDiskon(barang,50);
			printf("Disc 50%%\n");
			printf("\nTotal Tagihan  %d",total);
			break;					
		case 'N':
			TampilBarang(barang);
			total = jumlah*harga;
			printf("\nTotal Tagihan  %d",total);
			break;
		
		default : printf("member input invalid");
	}
	printf("\n===========================\n");
	getch();
	
	
	return 0;
}
