/*
    File         	: tree.h
    Description    	: Header ADT Tree (Struktur Organisasi)
    Author    		: Mohammad Fathul'Ibad
    Date/Version   	: 8 April 2022/1.0
    Compiler        : TDM-GCC 4.9.2
*/

#ifndef nbtree_d_H
#define nbtree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "tree.h"
#define Nil NULL
#define Nama(P) (P)->nama
#define Jabatan(P) (P)->jabatan
#define Parent(P) (P)->parent
#define Brother(P) (P)->nextBrother
#define Child(P) (P)->firstChild
#define Root(T) (T).root

typedef struct nbTreeNode *nbAddr;

typedef struct nbTreeNode{
	char jabatan[50];
	char nama[50]; 
  	nbAddr parent;
  	nbAddr firstChild; 
  	nbAddr nextBrother;
}ElmtTree;

typedef struct{
	nbAddr root;
}Tree;


void nbCreate(Tree *T);

nbAddr nbCNode(char* nama, char* jabatan);

nbAddr nbInsert(Tree *T, nbAddr parent, char* nama, char* jabatan);

void nbPre(nbAddr root);

nbAddr nbSearch(nbAddr root,char* nama);

void nbPreBawahan(nbAddr root);

void nbAtasan(nbAddr node);

void nbKepalaBagian(nbAddr root,nbAddr node);

#endif
