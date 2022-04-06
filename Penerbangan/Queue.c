/*
Program : Queue.c (Penerbangan)
Author : 211524015, Mohammad Fathul'Ibad
Kelas : 1A
Deskripsi: Header file dari prototype Queue linked list
Tanggal :
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

void CreateQueue(Queue *Q){
	/* I.S : Q terdefinisi tidak diketahui isinya
	F.S : Q diinisialisasi dengan HEAD(Q)=nil, TAIL(Q)=nil
	*/
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}
	
address Alokasi(char nama[], int koper, int datang){
	/* mengirim sebuah address jika alokasi type Queue berhasil */
	address P;
	
	P = (address) malloc (sizeof (ElmQueue));
	if(P == Nil){
		return Nil;
	}
	else{
		strcpy(Nama(P),nama);
		Koper(P) = koper;
		Datang(P) = datang;
		Next(P) = Nil;
		
		return P;
	}
}

void DeAlokasi(address P){
/* P direlease dari memori */
	free(P);
}

void AddQue(Queue *Q,char nama[], int koper, int datang){
	
	address P = Alokasi(nama,koper,datang);
	
	if(IsQueueEmpty(*Q)){
		Head(*Q) = P;
		Tail(*Q) = P;
		Datang(P) = datang;
		Lama(P) = 0;
		Selesai(P) = Durasi(koper) + datang;
	}
	else{
		Lama(P) = Selesai(Tail(*Q)) - Datang(P);
		if(Lama(P)<=0){
			Lama(P)=0;
		}
		Selesai(P) = Selesai(Tail(*Q)) + Durasi(koper);
		Next(Tail(*Q)) = P;
		Tail(*Q) = P;
	}
}

void DelQue(Queue *Q){
	/* I.S : Q terdefinisi sembarang tidak kosong
	F.S : Q berkurang satu elemen didepan disimpan pada y
	proses : y=info(HEAD), HEAD(Q) = next(HEAD(Q))
	DeAlokasi elemen pertama*/
	address P;
	
	if(IsQueueEmpty(*Q)){
		printf("Tidak ada antrian");
	}
	else{
		if(Selesai(Head(*Q)) < Datang(Tail(*Q))){
			P = Head(*Q);
			Head(*Q) = Next(Head(*Q));
			Next(P) = Nil;
			printf("Penumpang %s telah selesai mengantri",Nama(P));
			DeAlokasi(P);
		}
		else{
			printf("Penumpang masih berada di dalam antrian!");
			getch();
		}
			
	}
	
}

int Durasi(int koper){
	return koper*3+5;
}

void CetakQueue(Queue Q){
	/* I.S : Q terdefinisi sembarang tidak kosong
	F.S : elemen Queue dicetak dilayar*/
	address P;
	
	if(IsQueueEmpty(Q)){
		printf("Antrian Kosong!\n");
		printf("========================================\n");
		Head(Q) = Nil;
		Tail(Q) = Nil;
	}
	else{
		P = Head(Q);
		while(Next(P) != Nil){
			printf("Nama : %s\nWaktu Datang : %d\nJumlah Koper : %d\nWaktu Mengantri : %d\nEstimasi Selesai : %d\n", Nama(P), Datang(P),Koper(P), Lama(P), Selesai(P));
			P = Next(P);
			printf("=============================================\n");
		}
		printf("Nama : %s\nWaktu Datang : %d\nJumlah Koper : %d\nWaktu Mengantri : %d\nEstimasi Selesai : %d\n", Nama(P), Datang(P),Koper(P), Lama(P), Selesai(P));
		printf("=============================================\n");
	}
}

boolean IsQueueEmpty(Queue Q){
	/* Mengirim true jika Queue kosong HEAD(Q)=nil
	false sebaliknya */
	if(Head(Q) == Nil){
		return true;
	}
	else{
		return false;
	}
}


