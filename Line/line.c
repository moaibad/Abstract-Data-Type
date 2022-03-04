#include <stdio.h>
#include "line.h"

/*Fungsi untuk membuat LINE dari 2 nilai Point dari modul pemanggil
pStart : Titik awal bertipe POINT
pEnd : Titik akhir bertipe POINT
*/
LINE CreateLine(POINT pStart, POINT pEnd){
	LINE L;
	L.start = pStart;
	L.end = pEnd;
	
	return L;
}

/*Fungsi untuk membuat LINE secara horizontal
pStart : Titik awal bertipe POINT
lengthX : panjang nilai X bertipe int
*/
LINE CreateHorizontalLine(POINT start, int lenghtX){
	LINE L;
	POINT end;
	
	SetY(&end, start.y);
	SetX(&end, start.x+lenghtX);
	L.start = start;
	L.end = end;
	
	return L;
}

/*Fungsi untuk membuat LINE secara vertikal
start : Titik awal bertipe POINT
lengthY : panjang nilai Y bertipe int
*/
LINE CreateVerticalLine(POINT start, int lenghtY){
	LINE L;
	POINT end;
	
	SetY(&end, start.y+lenghtY);
	SetX(&end, start.x);
	L.start = start;
	L.end = end;
	
	return L;
}

/*Prosedur untuk menampilkan Line ke layar
tampilkan nilai X dan Y dari Titik awal serta nilai X dan Y dari
Titik Akhir
*/
void PrintLine(LINE line){
	printf("Titik Awal : ");PrintPoint(line.start);
	printf("\nTitik Akhir : ");PrintPoint(line.end);
}

/*Prosedur untuk memberikan nilai Titik awal bertipe POINT padasebuah Line*/
void SetPointStart(POINT pStart, LINE *line){
	(*line).start = pStart;
}

/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line*/
POINT GetPointStart(LINE line){
	return line.start;
}

/*Prosedur untuk memberikan nilai Titik akhir bertipe POINT pada
sebuah Line*/
void SetPointEnd(POINT pEnd, LINE *line){
	(*line).end = pEnd;
}

/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line */
POINT GetPointEnd(LINE line){
	return line.end;
}

/*Fungsi untuk mengecek apakah nilai parameter line adalah sebuah
LINE atau bukan
Fungsi ini mengembalikan nilai true jika nilai titik awal (x,y)
!= nilai titik akhir (x,y)
dengan asumsi : jika nilai titik awal (x,y) = nilai titik akhir
(x,y) maka bukanlah sebuah line, akan tetapi titik yang bertumpuk
*/
boolean IsLine(LINE line){
	if((line.start.x == line.end.x) && (line.start.y == line.end.y)){
		return false;
	}
	else{
		return true;
	}
}

/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai x pada titik awal
= nilai x pada titik akhir
*/
boolean IsHorizontalLine(LINE line){
	if(line.start.y == line.end.y){
		return true;
	}
	else{
		return false;
	}
}

/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai y pada titik awal
= nilai y pada titik akhir
*/
boolean IsVerticalLine(LINE line){
	if(line.start.x == line.end.x){
		return true;
	}
	else{
		return false;
	}
}

/*Fungsi untuk menghitung panjang dari sebuah line dan
mengembalikan nilai integer
panjang dihitung dari nilai titik awal dan titik akhirnya
*/
int LineLength(LINE line){
	Jarak(GetPointStart(line),GetPointEnd(line));
}

/*Prosedur untuk mereset Line menjadi nilai null*/
void ResetLine(LINE line){
	line.start.x = 0;
	line.start.y = 0;
	line.end.x = 0;
	line.end.y = 0;
}

/*Prosedur untuk mengecek apakah sebuah Line diagonal atau tidak*/
boolean isDiagonal(LINE line){
	if(!IsHorizontalLine(line) && !IsVerticalLine(line)){
		return true;
	}
	else false;
}

void CompareLines(LINE line1, LINE line2){
	if (LineLength(line1) > LineLength(line2)){
		printf ("\nLine 1 lebih panjang dari Line 2");
	}else if (LineLength(line2) > LineLength(line1)){
		printf ("\nLine 2 lebih panjang dari Line 1");
	}else if (LineLength(line1) == LineLength(line2)){
		printf ("\nKedua garis sama panjang");
	}
}

void ResizeHorizontalLine(LINE line){
	int panjang;
	if (IsHorizontalLine(line)){
		printf("\nMasukan panjang x yang ingin ditambah : ");
		scanf("%d", &panjang);
		line.end.x = line.end.x + panjang;
	}else{
		return;
	}
}
