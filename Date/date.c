// Program : date.c
// Deskripsi : Body ADT DATE
// Created : Mohammad Fathul'Ibad
// Modified : 
// Tanggal : 26/02/2022
#include <stdio.h>
#include "date.h"

/*********** Operasi Primitif ************/
void CreateDate (date * D){
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */
	(*D).Tgl = 01;
	(*D).Bln = 01;
	(*D).Thn = 1900;
}


/****** Selector komponen ******/
int GetTgl (date D){
/* Mengambil bagian Tgl dari date */
	return D.Tgl;
}

int GetBln (date D){
/* Mengambil bagian Bln dari date */
	return D.Bln;
}

int GetThn (date D){
/* Mengambil bagian Thn dari date */
	return D.Thn;
}


/****** Pengubah komponen ******/
void SetTgl (int NewTgl, date * D){
/* Memberi nilai untuk Tgl */
	(*D).Tgl = NewTgl;
}

void SetBln (int NewBln, date * D){	
/* Memberi nilai untuk Bln */
	(*D).Bln = NewBln;
}

void SetThn (int NewThn, date * D){
/* Memberi nilai untuk Thn */
	(*D).Thn = NewThn;
}


/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/
void BacaDate (date * D){
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */
	int iTgl,iBln,iThn;
	printf("Input Tanggal : ");
	scanf("%d",&iTgl);
	(*D).Tgl = iTgl;
	printf("Input Bulan : ");
	scanf("%d",&iBln);
	(*D).Bln = iBln;
	printf("Input Tahun : ");
	scanf("%d",&iThn);
	(*D).Thn = iThn;
}

boolean isValid(date D){
/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */
	if((D.Bln==1||D.Bln==3||D.Bln==5||D.Bln==7||D.Bln==8||D.Bln==10||D.Bln==12) && (D.Tgl>=1&&D.Tgl<=31) && (D.Thn>=1)){
		return true;
	}
	else if((D.Bln==4||D.Bln==6||D.Bln==9||D.Bln==11) && (D.Tgl>=1&&D.Tgl<=30) && (D.Thn>=1)){
		return true;
	}
	else if((D.Bln==2) && (D.Tgl>=1&&D.Tgl<=28) && (!isKabisat(D)) && (D.Thn>=1)){
		return true;
	}
	else if((D.Bln==2) && (D.Tgl>=1&&D.Tgl<=29) && (isKabisat(D)) && (D.Thn>=1)){
		return true;
	}
	else{
		return false;
	}
}

void PrintObj (date D){
/* Print nilai D dengan format dd/mm/yyyy */
	printf("%02d/%02d/%04d\n",D.Tgl,D.Bln,D.Thn);
}


/****** Operator Relasional ******/
boolean isKabisat (date D){
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja */
	if(((D.Thn%4==0) && ((D.Thn%400==0)||(D.Thn%100!=0)))){
		return true;
	}
	else{
		return false;
	}	
}


/***** Predikat lain *******/
int TglAkhir (date D){
/* Memberikan tanggal terakhir dari sebuah bulan */
	if(D.Bln==1||D.Bln==3||D.Bln==5||D.Bln==7||D.Bln==8||D.Bln==10||D.Bln==12){
		return 31;
	}
	else if(D.Bln==4||D.Bln==6||D.Bln==9||D.Bln==11){
		return 30;
	}
	else if(D.Bln==2 && isKabisat){
		return 29;
	}
	else if(D.Bln==2 && !isKabisat){
		return 28;
	}
	
}

void DateBefore (date D){
/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */
	if(D.Tgl==1 && D.Bln==1){
		D.Tgl = TglAkhir(D);
		D.Bln = 12;
		D.Thn = D.Thn-1;
	}
	else if(D.Tgl==1){
		D.Tgl = TglAkhir(D);
		D.Bln = D.Bln-1;
	}
	else{
		D.Tgl = D.Tgl-1;
	}
	PrintObj(D);
}

void NextDate (date D){
/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */
	if(D.Tgl==TglAkhir(D) && D.Bln==12){
		D.Tgl = 1;
		D.Bln = 1;
		D.Thn = D.Thn+1;
	}
	else if(D.Tgl==TglAkhir(D)){
		D.Tgl = 1;
		D.Bln = D.Bln+1;
	}
	else{
		D.Tgl = D.Tgl+1;
	}
	PrintObj(D);
}


void SelisihDate (date D1, date D2){
/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal
	Asumsi : 1 tahun = 365 hari */
	int i,selisih,date1,date2;
	int HariDalamBulan[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	/*Mengubah date 1 menjadi hari*/
	date1 = (D1.Thn*365)+D1.Tgl;
	for(i=0; i<D1.Bln-1; i++){
		date1 = date1+HariDalamBulan[i];
	}
	
	/*Mengubah date 2 menjadi hari*/
	date2 = (D2.Thn*365)+D2.Tgl;
	for(i=0; i<D2.Bln-1; i++){
		date2 = date2+HariDalamBulan[i];
	}

	/*Menghitung selisih hari*/
	selisih = abs(date1-date2);
	printf("%d",selisih);
}

