#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main(int argc, char *argv[]) {	
	date D1,D2;
	
	//CreateDate
	printf("==========CreateDate==========\n");
	CreateDate(&D1);
	printf("Date 1 setelah CreateDate : ");
	PrintObj(D1);
	
	//GetTgl dari D1
	printf("\n\n=============Get==============");
	printf("\nTanggal dari D1 : %d\n",GetTgl(D1));
	//GetBln dari D1
	printf("Bulan dari D1 : %d\n",GetBln(D1));
	//GetThn dari D1
	printf("Tahun dari D1 : %d\n",GetThn(D1));

	//SetTgl D1
	printf("\n\n=============Set==============");
	SetTgl(4,&D1);
	//SetBln dari D1
	SetBln(12,&D1);
	//SetThn dari D1
	SetThn(2021,&D1);
	printf("\nDate 1 setelah SetTgl, SetBln, SetThn : ");
	PrintObj(D1);
	
	//BacaDate
	printf("\n\n===========BacaDate===========\n");
	BacaDate(&D2);
	printf("Date 2 setelah BacaDate : ");
	PrintObj(D2);
	
	//isValid
	printf("\n\n===========isValid============");
	if(isValid(D1)){
		printf("\nDate 1 valid");
	}
	else{
		printf("\nDate 1 tidak valid");
	}
	if(isValid(D2)){
		printf("\nDate 2 valid");
	}
	else{
		printf("\nDate 2 tidak valid");
	}
	
	//isKabisat
	printf("\n\n\n==========isKabisat===========");
	if(isKabisat(D1)){
		printf("\nDate 1 adalah tahun kabisat");
	}
	else{
		printf("\nDate 1 bukan tahun kabisat");
	}
	if(isKabisat(D2)){
		printf("\nDate 2 adalah tahun kabisat");
	}
	else{
		printf("\nDate 2 bukan tahun kabisat");
	}
	
	//TglAkhir
	printf("\n\n\n===========TglAkhir===========");
	printf("\nTanggal akhir dari bulan pada date 1 adalah : %d",TglAkhir(D1));
	printf("\nTanggal akhir dari bulan pada date 2 adalah : %d\n\n",TglAkhir(D2));
	
	//DateBefore
	printf("\n==========DateBefore==========\n");
	printf("Tanggal sebelumnya dari date 1 adalah : ");
	DateBefore(D1);
	printf("Tanggal sebelumnya dari date 2 adalah : ");
	DateBefore(D2);
	
	//NextDate
	printf("\n\n===========NextDate===========\n");
	printf("Tanggal berikutnya dari date 1 adalah : ");
	NextDate(D1);
	printf("Tanggal berikutnya dari date 2 adalah : ");
	NextDate(D2);
	
	//SelisihDate
	printf("\n\n=========SelisihDate==========\n");
	printf("Selisih tanggal dari date 1 dan date 2 adalah : ");
	SelisihDate(D1,D2);
	printf(" hari");
	
	return 0;
}
