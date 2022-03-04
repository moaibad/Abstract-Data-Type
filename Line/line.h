#include "boolean.h"
#include "point.h"
#ifndef LINE_H
#define LINE_H

/* definisi type data */
typedef struct{
	POINT start;
	POINT end;
} LINE; // type LINE

/*Fungsi untuk membuat LINE dari 2 nilai Point dari modul pemanggil
pStart : Titik awal bertipe POINT
pEnd : Titik akhir bertipe POINT
*/
LINE CreateLine(POINT pStart, POINT pEnd);

/*Fungsi untuk membuat LINE secara horizontal
pStart : Titik awal bertipe POINT
lengthX : panjang nilai X bertipe int
*/
LINE CreateHorizontalLine(POINT start, int lenghtX);

/*Fungsi untuk membuat LINE secara vertikal
start : Titik awal bertipe POINT
lengthY : panjang nilai Y bertipe int
*/
LINE CreateVerticalLine(POINT start, int lenghtY);

/*Prosedur untuk menampilkan Line ke layar
tampilkan nilai X dan Y dari Titik awal serta nilai X dan Y dari
Titik Akhir
*/
void PrintLine(LINE line);

/*Prosedur untuk memberikan nilai Titik awal bertipe POINT padasebuah Line*/
void SetPointStart(POINT pStart, LINE *line);

/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line*/
POINT GetPointStart(LINE line);

/*Prosedur untuk memberikan nilai Titik akhir bertipe POINT pada
sebuah Line*/
void SetPointEnd(POINT pEnd, LINE *line);

/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line */
POINT GetPointEnd(LINE line);

/*Fungsi untuk mengecek apakah nilai parameter line adalah sebuah
LINE atau bukan
Fungsi ini mengembalikan nilai true jika nilai titik awal (x,y)
!= nilai titik akhir (x,y)
dengan asumsi : jika nilai titik awal (x,y) = nilai titik akhir
(x,y) maka bukanlah sebuah line, akan tetapi titik yang bertumpuk
*/
boolean IsLine(LINE line);

/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai x pada titik awal
= nilai x pada titik akhir
*/
boolean IsHorizontalLine(LINE line);

/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai y pada titik awal
= nilai y pada titik akhir
*/
boolean IsVerticalLine(LINE line);

/*Fungsi untuk menghitung panjang dari sebuah line dan
mengembalikan nilai integer
panjang dihitung dari nilai titik awal dan titik akhirnya
*/
int LineLength(LINE line);

/*Prosedur untuk mereset Line menjadi nilai null*/
void ResetLine(LINE line);

/*Prosedur untuk mengecek apakah sebuah Line diagonal atau tidak*/
boolean isDiagonal(LINE line);

void CompareLines(LINE line1, LINE line2);

void TransposeVerticalLine(LINE *line);

void ResizeHorizontalLine(LINE line);

#endif
