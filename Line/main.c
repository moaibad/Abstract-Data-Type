#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x = 0;
	int y = 0;
	int x2 = 0;
	int y2 = 0;
	int lenghtX,lenghtY;
	POINT start,end;
	LINE line1,line2,line3;
	
	/**************Line 1**************/
	printf("==========Line 1==========\n");
	printf("Masukan koordinat Point Start <x y> : ");
	scanf("%d %d", &x, &y);
	printf("Masukan koordinat Point End <x y> : ");
	scanf("%d %d", &x2, &y2);
	
	start = CreatePoint(x,y);
	end = CreatePoint(x2,y2);
	
	line1 = CreateLine(start,end);
	PrintLine(line1);
	
	printf("\nPoint Start dengan menggunakan GetPointStart : (%d,%d)",GetPointStart(line1).x,GetPointStart(line1).y);
	printf("\nPoint End dengan menggunakan GetPointEnd : (%d,%d)",GetPointEnd(line1).x,GetPointEnd(line1).y);
	
	printf("\nPanjang Line 1 adalah : %d",LineLength(line1));
	
	
	/**************Line 2**************/
	printf("\n\n\n==========Line 2==========\n");
	printf("Masukan koordinat Point Start <x y> : ");
	scanf("%d %d", &x, &y);
	start = CreatePoint(x,y);
	
	printf("Masukan panjang X : ");
	scanf("%d", &lenghtX);
	
	line2 = CreateHorizontalLine(start,lenghtX);	
	PrintLine(line2);
	
	printf("\nPanjang Line 2 adalah : %d",LineLength(line2));
	
	printf("\n\nMasukan koordinat Point End <x y> : ");
	scanf("%d %d", &x2, &y2);
	end = CreatePoint(x2,y2);
	
	SetPointEnd(end, &line2);
	
	printf("Line 2 sekarang adalah : \n");
	PrintLine(line2);
	printf("\nPanjang Line 2 sekarang adalah : %d",LineLength(line2));
	
	
	/**************Line 3**************/
	printf("\n\n\n==========Line 3==========\n");
	start = CreatePoint(5,10);
	end = CreatePoint(5,10);
	
	line3 = CreateVerticalLine(start,lenghtY);
	PrintLine(line3);
	if(!IsLine(line3)){
		ResetLine(line3);
		printf("\nLine 3 bukan merupakan baris, Line di reset");
	}
	
	/**************Cek Vertikal/Horizontal**************/
	printf("\n\n\n==========Cek Vertikal/Horizontal==========");
	if (IsHorizontalLine(line1)){
		printf("\nLine 1 merupakan garis horizontal");
	}else if (IsVerticalLine(line1)){
		printf("\nLine 1 merupakan garis vertikal");
	}else{
		printf("\nLine 1 bukan garis horizontal/vertikal");
	}
	
	if (IsHorizontalLine(line2)){
		printf("\nLine 2 merupakan garis horizontal");
	}else if (IsVerticalLine(line2)) {
		printf("\nLine 2 merupakan garis vertikal");
	}else{
		printf("\nLine 2 bukan garis horizontal/vertikal");
	}
	
	
	return 0;
}
