/*
Program : Queue.h (Penerbangan)
Author : 211524015, Mohammad Fathul'Ibad
Kelas : 1A
Deskripsi: Header file dari prototype Queue linked list
Tanggal :
*/

#ifndef _QUEUE_H
#define _QUEUE_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
//pendefinisian pointer
#define Nil NULL
#define Nama(P) (P)->nama
#define Next(P) (P)->next
#define Koper(P) (P)->koper
#define Datang(P) (P)->datang
#define Lama(P) (P)->lama
#define Selesai(P) (P)->selesai
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
//Pembentukan tipe Queue
typedef struct tElmQueue *address;
typedef struct tElmQueue{
char nama[20];
int datang;
int selesai;
int koper;
int lama;
address next;
}ElmQueue;
typedef struct{

address HEAD;
address TAIL;
}Queue;

//Prototype Queue/ primitif Queue dengan pointer
//Konstruktor
void CreateQueue(Queue *Q);
/* I.S : Q terdefinisi tidak diketahui isinya
F.S : Q diinisialisasi dengan HEAD(Q)=nil, TAIL(Q)=nil
*/
address Alokasi(char nama[], int koper, int datang);
/* mengirim sebuah address jika alokasi type Queue berhasil */
void DeAlokasi(address P);
/* P direlease dari memori */

//Operasi Queue
void AddQue(Queue *Q,char nama[], int koper, int datang);
/* I.S : Q terdefinisi sembarang mungkin kosong
F.S : Q bertambah sebuah elemen bernilai X dibelakang
proses : HEAD (Q) merupakan elemen terakhir dari Q
*/
void DelQue(Queue *Q);
/* I.S : Q terdefinisi sembarang tidak kosong
F.S : Q berkurang satu elemen didepan disimpan pada y
proses : y=info(HEAD), HEAD(Q) = next(HEAD(Q))
DeAlokasi elemen pertama

*/
//Operasi I/O terhadap Queue
void CetakQueue(Queue Q);
/* I.S : Q terdefinisi sembarang tidak kosong
F.S : elemen Queue dicetak dilayar
*/
//Operasi boolean dan relasi terhadap Queue
boolean IsQueueEmpty(Queue Q);
/* Mengirim true jika Queue kosong HEAD(Q)=nil
false sebaliknya */

int Durasi(int koper);
#endif
