/*
    File         	: main.c
    Description    	: Main Driver ADT Tree (Struktur Organisasi)
    Author    		: Mohammad Fathul'Ibad
    Date/Version   	: 8 April 2022/1.0
    Compiler        : TDM-GCC 4.9.2
*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char *argv[]) {
	Tree T;
	nbAddr p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
	nbAddr temp;
	nbCreate(&T);
	
	//Kepala Pusat
	p1 = nbInsert(&T,Nil,"Ujang Kartiwa","Kepala Lembaga");
	
	//Kepala Bagian
	p2 = nbInsert(&T,p1,"Dana Sukirman","Kepala Bagian Keuangan");
	p3 = nbInsert(&T,p1,"Hoerul Anam","Kepala Bagian SDM");
	p4 = nbInsert(&T,p1,"Engkos Koswara","Kepala Bagian Perencanaan");
	
	//Kepala Sub Bagian
	nbInsert(&T,p2,"Noviyanti","Kepala Sub Bagian Pelaksana Keuangan");
	p6 = nbInsert(&T,p3,"Mujani Gani","Kepala Sub Bagian Tata Laksana");
	p7 = nbInsert(&T,p3,"Sambas Nugroho","Kepala Sub Bagian Kepegawaian");
	p8 = nbInsert(&T,p4,"Evi Sukaesih","Kepala Sub Bagian Evaluasi");
	p9 = nbInsert(&T,p4,"Irvan Susilo","Kepala Sub Bagian Pendataan");
	p10 = nbInsert(&T,p4,"Tati Sulastri","Kepala Sub Bagian Anggaran");
	
	//Staff
	nbInsert(&T,p6,"Opik Taufik","Staff");
	nbInsert(&T,p6,"Marcelino","Staff");
	nbInsert(&T,p7,"Ukar Mustopa","Staff");
	nbInsert(&T,p7,"Jaelani Supri Utama","Staff");	
	nbInsert(&T,p7,"Markonah","Staff");
	nbInsert(&T,p8,"Kartono","Staff");
	nbInsert(&T,p9,"Candra Dimuka","Staff");
	nbInsert(&T,p10,"Hartanto Utomo","Staff");
	nbInsert(&T,p10,"Muktadi","Staff");
	
	//Isi Tree
	printf("==================================================\n");
	printf("Isi Tree secara Pre Order : \n\n");
	nbPre(Root(T));
	printf("==================================================\n");
	
	//Atasan
	temp = nbSearch(Root(T),"Kartono");
	nbAtasan(temp);
	printf("==================================================\n");
	
	//Bawahan		
	temp = nbSearch(Root(T),"Sambas Nugroho");
	nbPreBawahan(temp);
	printf("==================================================\n");
	
	//Kepala Bagian
	temp = nbSearch(Root(T),"Opik Taufik");
	nbKepalaBagian(Root(T),temp);
	printf("==================================================\n");
	
	return 0;
}
