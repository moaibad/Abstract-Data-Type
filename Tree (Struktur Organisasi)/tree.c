/*
    File         	: tree.c
    Description    	: Body ADT Tree (Struktur Organisasi)
    Author    		: Mohammad Fathul'Ibad
    Date/Version   	: 8 April 2022/1.0
    Compiler        : TDM-GCC 4.9.2
*/

#include <malloc.h>
#include "tree.h"

void nbCreate(Tree *T){
	Root(*T) = Nil;
}

nbAddr nbCNode(char* nama, char* jabatan){
	nbAddr P;
	P =(nbAddr) malloc(sizeof(ElmtTree));
	if (P != Nil){
		Parent(P) = Nil;
		Brother(P) = Nil;
		Child(P) = Nil;
		strcpy(Nama(P),nama);
		strcpy(Jabatan(P),jabatan);
	}
	return P;
}

nbAddr nbInsert(Tree *T, nbAddr parent, char* nama, char* jabatan){
		nbAddr P,temp;
		P = nbCNode(nama,jabatan);
		
		if (P != NULL){
			if (parent == NULL){
				Root(*T) = P;
			}
			else{
				temp = parent;
	
				if(Child(temp) != Nil){
					temp = Child(temp);
					while(Brother(temp) != Nil){
					temp = Brother(temp);
					}
					Brother(temp) = P;
					Parent(P) = parent;
				}
				else{
					Child(temp) = P;
					Parent(P) = parent;
				}
				
			}
	
		}
		
		return P;
}

void nbPre(nbAddr root){
	if (root!=Nil){
		printf("Nama : %s\nJabatan : %s\n\n", Nama(root),Jabatan(root));
		nbPre(Child(root));
		nbPre(Brother(root));
	
	}
}

nbAddr nbSearch(nbAddr root, char* src){
	nbAddr nSrc;
	if (root!=NULL){
		int compare = strcmp(Nama(root),src);
		if (compare == 0){
			return root;
		}		
		else{
			nSrc=nbSearch(Child(root),src);
			if (nSrc==NULL){
				return nbSearch(Brother(root),src);
			}	
			else{
				return nSrc;	
			}	
		}
	}
	return NULL;
}

void nbPreBawahan(nbAddr root){
	printf("Bawahan dari %s adalah : \n\n",Nama(root));
	root = Child(root);
	if (root!=Nil){
		printf("Nama : %s\nJabatan : %s\n\n", Nama(root),Jabatan(root));
		nbPre(Child(root));
		nbPre(Brother(root));
	}
}

void nbAtasan(nbAddr node){
	printf("Atasan dari %s adalah : \n\n",Nama(node));
	
	node = Parent(node);
	if(node!=Nil){
		printf("Nama : %s\nJabatan : %s\n\n", Nama(node),Jabatan(node));
	}
	else{
		printf("Orang tersebut tidak memiliki atasan");
	}
	
}

void nbKepalaBagian(nbAddr root,nbAddr node){
	printf("Kepala Bagian dari %s adalah : \n\n",Nama(node));
	while(Parent(node)!=root){
		node = Parent(node);
	}
	printf("Nama : %s\nJabatan : %s\n\n", Nama(node),Jabatan(node));
}

