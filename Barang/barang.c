#include <stdio.h>
#include "barang.h"

BARANG CreateBarang(char *nama, long harga){
	BARANG barang;
	barang.nama_barang = nama;
	barang.harga = harga;
	return barang;
}

void SetNamaBarang(BARANG barang, char *nama){
	barang.nama_barang = nama;
}

char *GetNamaBarang(BARANG barang){
	return(barang.nama_barang);
}

void SetHargaBarang(BARANG barang, long harga){
	barang.harga = harga;
}

int GetHargaBarang(BARANG barang){
	return(barang.harga);
}

int GetHargaDiskon(BARANG barang, float diskon){
	int harga;
	
	harga = (barang.harga *(1-(diskon/100)));
}

void TampilBarang(BARANG barang){
	printf("%s\n",barang.nama_barang);
	printf("   %d\n",barang.harga);
}
