#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(int argc, char *argv[]) {
	POINT p1,p2;
	int x=0, y=0;
	
	printf("Masukan koordinat Point ke-1 <x y> : ");
	scanf("%d %d", &x, &y); // input atribut point dari user
	p1 = CreatePoint(x,y); // buat point dari inputan user
	printf("Point ke-1 berada pada koordinat : ");
	PrintPoint(p1);
	printf("\nKoordinat X dari Point ke-1 : %d", GetX(p1));
	printf("\nKoordinat Y dari Point ke-1 : %d\n\n", GetY(p1));
	
	
	printf("Masukan koordinat Point ke-2 <x y>: ");
	scanf("%d %d", &x, &y);
	MakePoint(&p2,x,y);
	printf("Point ke-2 berada pada koordinat : ");
	PrintPoint(p2);
	printf("\nKoordinat X dari Point ke-2 : %d", GetX(p2));
	printf("\nKoordinat Y dari Point ke-2 : %d\n\n", GetY(p2));
	
	
	printf("Jarak antara Point ke-1 dan Point ke-2 adalah : %d\n\n", Jarak(p1,p2));
	
	
	ReSet(&p1);
	printf("Point ke-1 setelah di reset adalah : ");
	PrintPoint(p1);
	
	
	printf("\n\nMasukan koordinat Point ke-2 <x y>: ");
	scanf("%d %d", &x, &y);
	SetX(&p2,x);
	SetY(&p2,y);
	
	printf("\nPoint ke-1 berada pada koordinat : ");
	PrintPoint(p1);
	printf("\nPoint ke-2 berada pada koordinat : ");
	PrintPoint(p2);
	
	getch();
	
	return 0;
}
