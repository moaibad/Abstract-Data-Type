/* Program : barang.h
Deskripsi : Header ADT Barang
oleh : Lukmannul Hakim Firdaus
Tgl/Version :
*/
#ifndef BARANG_H
#define BARANG_H

typedef struct{
char *nama_barang;
long harga;
} BARANG;

BARANG CreateBarang(char *nama, long harga);

void SetNamaBarang(BARANG barang, char *nama);

char *GetNamaBarang(BARANG barang);

void SetHargaBarang(BARANG barang, long harga);

int GetHargaBarang(BARANG barang);

int GetHargaDiskon(BARANG barang, float diskon);

void TampilBarang(BARANG barang);
#endif
