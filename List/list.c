// Program : list.c
// Deskripsi : Body ADT List
// Created : 
// Modified : Mohammad Fathul'Ibad
// Tanggal : 02/03/2022
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L){
	/* Mengirim true jika List Kosong */
	if(First(L)==Nil){
		return true;
	}
	else{
		return false;
	}
}


/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L){
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
	First(*L)=Nil;
}


/**** Manajemen Memory ****/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	address P;
	
	P = (address) malloc (sizeof (ElmtList));
	if(P == Nil){
		return Nil;
	}
	else{
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}	
}

void DeAlokasi (address P){
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */	
	free(P);
}


/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */	
	address P;
	boolean Ketemu;
	
	P = First(L);
	Ketemu = false;
	
	while((!Ketemu) && (P != Nil)){
		if(Info(P)==X){
			Ketemu = true;
		}
		else{
			P = Next(P);
		}
	}
	return P;
}

boolean FSearch (List L, address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */	
	address tP;
	boolean Ketemu;
	
	tP = First(L);
	Ketemu = false;
	
	while((!Ketemu) && (P != Nil)){
		if(tP == P){
			Ketemu = true;
		}
		else{
			tP = Next(tP);
		}
	}
	return Ketemu;
}

address SearchPrec (List L, infotype X){
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */	
	address P;
	boolean Ketemu;
	
	P = First(L);
	Ketemu = false;
	
	if(P == Nil){
		return Nil;
	}
	else if(Info(P) == X){
		return Nil;
	}
	else{
		while ((Next(P)!=Nil) && (!Ketemu)){
			if(Info(Next(P))==X){
				Ketemu = true;
			}
			else{
				P = Next(P);
			}
		}
	}
	
	if(Next(P) == Nil){
		return Nil;
	}
	else{
		return P;
	}
	
}


/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P){
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List * L, address P, address Prec){
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List * L, address P){
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
	address Last;

	if(First(*L)==Nil){
		InsertFirst(L,P);
	}
	else{
		Last = First(*L);
		while(Next(Last) != Nil){
			Last = Next(Last);
		}
		InsertAfter(L,P,Last);
	}
}


/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X){
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	InsertFirst(L,Alokasi(X));
}

void InsVLast (List * L, infotype X){
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
	if(First(*L) == Nil){
		InsertFirst(L,Alokasi(X));
	}
	else{
		InsertLast(L,Alokasi(X));
	}
}


/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P){
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
	*P = First(*L);
	First(*L) = Next(First(*L));
}

void DelP (List * L, infotype X){
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
	address P,Prec;
	
	if(X == Info(First(*L))){
		DelFirst(L,&Prec);
	}
	else{
		Prec = First(*L);
		while(Info(Next(Prec)) != X){
			Prec = Next(Prec);
		}
		DelAfter(L,&P,Prec);
	}
}

void DelLast (List * L, address * P){
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
	address Last,PrecLast;
	
	Last = First(*L);
	PrecLast = Nil;
	while(Next(Last) != Nil){
		PrecLast = Last;
		Last = Next(Last);
	}
	*P = Last;
	if(PrecLast == Nil){
		First(*L) = Nil;
	}
	else{
		Next(PrecLast) = Nil;
	}
}

void DelAfter (List * L, address * Pdel, address Prec){
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X){
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
	address P;
	
	P = First(*L);
	*X = Info(P);
	First(*L) = Next(First(*L));
	Next(P) = Nil;
	DeAlokasi(P);
}

void DelVLast (List * L, infotype * X){
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
	address P;
	
	DelLast(L,&P);
	*X = Info(P);
	DeAlokasi(P);
}


/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L){
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
	address P;
	
	if(ListEmpty(L)){
		printf("List Kosong \n");
	}
	else{
		P = First(L);
		while(Next(P) != Nil){
			printf("%d, ",Info(P));
			P = Next(P);
		}
		printf("%d\n",Info(P));
	}
}

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
	address P;
	int element = 0;
	
	while(P != Nil){
		element++;
		P = Next(P);
	}
	return element;
}

infotype Max (List L){
/* Mengirimkan nilai Info(P) yang maksimum */
	address P;
	infotype max;
	
	P = First(L);
	max = Info(P);
	P = Next(P);
	while(P != Nil){
		if(max <= Info(P)){
			max = Info(P);
		}
		P = Next(P);
	}
	return max;
}

address AdrMax (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
	address P;
	infotype max;
	
	max = Max(L);
	P = Search(L,max);
	return P;
}

infotype Min (List L){
/* Mengirimkan nilai Info(P) yang minimum */
	address P;
	infotype min;
	
	P = First(L);
	min = Info(P);
	P = Next(P);
	while(P != Nil){
		if(min >= Info(P)){
			min = Info(P);
		}
		P = Next(P);
	}
	return min;
}

address AdrMin (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
	address P;
	infotype min;
	
	min = Min(L);
	P = Search(L,min);
	return P;
}

infotype Average (List L){
/* Mengirimkan nilai rata-rata Info(P) */
	address P;
	float jumlah;
	
	P = First(L);
	jumlah = Info(P);
	P = Next(P);
	while(P != Nil){
		jumlah = jumlah + Info(P);
		P = Next(P);
	}
	return jumlah/NbElmt(L);
}


/***************************************/
/*******  PROSES TERHADAP LIST  ********/
/***************************************/

void DelAll (List * L){
/* Delete semua elemen list dan alamat elemen di dealokasi */
	free(L);
}

void InversList (List * L){
/* IS : L sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */
/*	Membalik elemen list, tanpa melakukan alokasi / dealokasi */
	address P,Q,R;
	
	P = First(*L);
	Q = Nil;
	
	while(P != Nil){
		R = Next(P);
		Next(P) = Q;
		Q = P;
		P = R;
	}
	First(*L) = Q;
}

List FInversList (List L){
/* Mengirimkan list baru, hasil invers dari L */
	InversList(&L);
	return L;
}

void CopyList (List L1, List * L2){
/* IS : L1 sembarang */
/* FS : L2 = l1 */
/* L1 dan L2 "menunjuk" ke list yang sama, Tidak ada alokasi / dealokasi */
	*L2 = L1;
}

List FCopyList (List L){
/* Mengirimkan List yang merupakan salinan L */
	List Copied;
	CopyList(L,&Copied);
	return Copied;
}

void CpAlokList (List Lin, List * Lout);
/* IS : Lin Sembarang */
/* FS : Jika semua alokasi berhasi, maka Lout berisi hasil copy Lin */
/* 	Jika ada alokasi yang gagal, maka Lout = Nil dan semua elemen yang */
/*	terlanjur di alokasi, maka didealokasikan */
/* 	Dengan melakukan alokasi elemen */
/*	Lout adalah  list kosong jika ada alokasi elemen yang gagal */

void Konkat (List L1, List L2, List * L3);
/* IS : L1 dan L2 sembarang */
/* FS : L1 dan L2 tetap, L3 adalah hasil konkatenansi L1 dan L2 */
/*	Jika semua alokasi berhasil , maka L3 adalah hasil konkatenasi */
/*	Jika ada alokasi gagal, semua elemen yang sudah di alokasi harus */
/* 	di dealokasi dan L3 = Nil */
/* Konkatenasi dua buah list : L1 dan L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang "baru". Jika ada alokasi yang */
/*	  GAGAL, maka L3 harus bernilai nil dan semua elemen yang pernah di */
/*	  alokasi didealokasi */

void Konkat1 (List * L1, List * L2, List * L3);
/* IS : L1 dan L2 sembarang */
/* FS : L1 dan L2 kosong, L3 adalah hasil konkatenansi L1 dan L2 */
/*	Konkatenasi dua buah List L1 dan L2; menghasilkan L3 yang baru */
/* 	(dengan elemen List L1 dan L2) */
/*	dan L1 serta L2 menjadi list kosong */
/* 	Tidak ada alokasi / dealokasi pada procedure ini */

void PecahList (List * L1, List * L2, List L);
/* IS : L mungkin kosong */
/* FS : berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah : untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil , maka separuh adalah NbElmt (L) div 2 */
