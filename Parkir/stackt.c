/* File stackt.c */ 
/* HEAD dan TAIL adalah alamat elemen pertama dan terakhir */ 
/* Kapasitas Queue=MaxEl bush elemen, dan indeks dibuat "sirkuler" */ 
#include "stackt.h"
#include <stdio.h>
/* Definisi ABSTRACT DATA TYPE POINT *
Stack S;

/******************* Prototype ****************/
/*** Konstruktor/Kreator ***/
void CreateEmpty(Stack *S){
	Top(*S) = Nil;
}
/* T.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosonq berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+l karena O tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
/*********** Predikat Untuk test keadaan KOLEKSI **/
boolean IsEmpty (Stack S){
	return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S){
	return Top(S) == MaxEl;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
/*********** Menambahkan sebuah elemen ke Stack **********/
void Push (Stack *S, infotype X){
	Top(*S) = Top(*S)+1;
	InfoTop(*S) = X; 
}
/* Menambahkan X sebagai elemen Stack S. */
/* T.S. S mungkin kosong, tabel penampung elemen stack TTDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
/*********** Menqhapus sebuah elemen Stack **********/
void Pop (Stack *S, infotype *X){
	*X = InfoTop(*S);
	Top(*S) = Top(*S)-1;
}
/* Menghapus X dari Stack S. */
/* T.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang l */

void KeluarParkir (Stack *S, infotype *X,int Arah){
	int i;
	int j = 1;
	int Temp[21];
	if(*X == InfoTop(*S)){
		Pop(&*S,&*X);
		if (Arah == 1){
			printf("Mobil %d keluar ke arah kanan\n", *X);
			getch();	
			}
		else{
			printf("Mobil %d keluar ke arah kiri\n", *X);
			getch();
		}
	}
	else{
		i = CariMobil(*S, *X);
		
		//Melakukan pemindahan elemen ke Temp
		for(Top(*S);Top(*S)>i;Top(*S)){		
			Temp[j] = InfoTop(*S);
			system("cls");
			Top(*S) = Top(*S)-1;
			PrintStack(*S);	
			if (Arah == 1){
				printf("Mobil %d keluar ke arah kiri\n", Temp[j]);	
			}
			else{
				printf("Mobil %d keluar ke arah kanan\n", Temp[j]);
			}
			int k=1;
			printf("=================================");
			printf("\nIsi Area Luar : ");
			for(k;k<=j;k++){
				printf("\nMobil %d",Temp[k]);
			}
			printf("\n=================================\n");
			j++;
			getch();
			
		}
		
		//Menghapus elemen yang dipilih
		Pop(&*S,&*X);
		if(Arah==1){
			system("cls");
			PrintStack(*S);
			printf("Mobil %d keluar ke arah kanan\n",*X);
		}
		else{
			system("cls");
			PrintStack(*S);
			printf("Mobil %d keluar ke arah kiri\n",*X);
		}
		
		//Mencetak isi elemen dari temp
		int k=1;
		printf("=================================");
		for(k;k<=j-1;k++){
				printf("\nMobil %d",Temp[k]);
			}
			printf("\n=================================\n");
		getch();
			
		PushTemp(&*S,Temp,j);
		
	}
}

void PushTemp(Stack *S,int Temp[21], int j){
	for(j=j-1;j>=1;j--){
		Push(&*S,Temp[j]);
		system("cls");
		PrintStack(*S);
		printf("Mobil %d kembali masuk ke parkiran\n",Temp[j]);
		
		printf("=================================");
		printf("\nIsi Area Luar : ");
		int k;
		for(k=1;k<=j-1;k++){
			printf("\nMobil %d",Temp[k]);
		}
		printf("\n=================================\n");
		getch();
	}	
}

int CariMobil(Stack S, infotype X){
	int i = 1;
	for(i;i<=MaxEl;i++){
		if((S).Parkir[i]==X){
			return i;
		}
	}
	return 0;
}

void PrintStack(Stack S){
	int i;
	printf("=================================");
	printf("\nIsi Parkiran Sekarang : \n");
	if(Top(S)!=Nil){
			for(i=1; i <= Top(S); i++){
			printf("Mobil %d\n", S.Parkir[i]);
		}	
	}
	else{
		printf("Parkiran Kosong");
	}
	
	printf("\n=================================\n");
}
/*Menampilkan nilai-nilai pada Stack S yang diurutkan berdasarkan data yang pertama kali masuk ke stack*/

