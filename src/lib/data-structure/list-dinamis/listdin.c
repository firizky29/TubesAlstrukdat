/* 
NIM : 13520074
Nama : Eiffel Aqila Amarendra
Tanggal : 14 September 2021
Topik praktikum : ADT List Dinamis
Deskripsi : Pra Praktikum 4 (Program listdin.c)
*/

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"


void setLoc(Location *L, int x, int y, char c){
    COORLOC(*L) = MakePoint(x, y);
    CHARLOC(*L) = c;
}

void displayLoc(Location L){
    TulisPoint(COORLOC(L));
    printf(" %c", CHARLOC(L));
}

boolean IsHQ (Location P){
/* Menghasilkan true jika P adalah titik HQ */
    return CHARLOC(P) == '8';
}

boolean isSpace(Location P){
    return CHARLOC(P) == ' ';
}

boolean isDropOffPoint(Location P){
    Pesanan T = TOP(curBag);
    return CHARLOC(P) == DROPOFFPESANAN(T);
}

boolean isPickUpPoint(Location P){
    Address p;

    p = FIRST(curToDoList);
    while(p!=NULL){
        if(CHARLOC(P)==PICKUPPESANAN(INFO(p))){
            return true;
        }
        p = NEXT(p);
    }
    return false;
}

boolean isMobitaPoint(Location P){
    return CHARLOC(curPosition)==CHARLOC(P)&&EQ(COORLOC(curPosition),COORLOC(P));
}
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
    /* KAMUS */
    /* ALGORITMA */
    BUFFER(*l) = (Location*) malloc (capacity * sizeof (Location));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealocate(ListDin *l) {
    /* KAMUS */
    /* ALGORITMA */
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l) {
    /* KAMUS */
    /* ALGORITMA */
    return (NEFF(l));
}
/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l) {
    /* KAMUS */
    /* ALGORITMA */
    return(length(l) - 1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListEmpty(ListDin l) {
    /* KAMUS */
    /* ALGORITMA */
    return(NEFF(l) == 0);
}
/* *** Test list penuh *** */
boolean isListFull(ListDin l) {
    /* KAMUS */
    /* ALGORITMA */
    return(NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
    /* KAMUS */
    int n, i;

    /* ALGORITMA */
    CreateListDin(l, CAPACITY(*l));
    scanf("%d", &n);
    while(!((n >= 0) && (n <= NEFF(*l)))) {
        scanf("%d", &n);
    }
    if (n > 0) {
        NEFF(*l) = n;
        for(i = 0; i < n; i++) {
            scanf(" %c", &CHARLOC(ELMT(*l, i)));
            scanf(" %d", &Absis(COORELMT(*l, i)));
            scanf(" %d", &Ordinat(COORELMT(*l, i)));
        }
    }
}

void displayList(ListDin l) {
    /* KAMUS */
    int i;
    /* ALGORITMA */
    printf("[");
    if (!(isListEmpty(l))) {
        for (i = 0; i < getLastIdx(l); i++) {
            printf("(%c,", CHARELMT(l, i));
            TulisPoint(COORELMT(l, i));
            printf("),");
        }
        printf("(%c,", CHARELMT(l,getLastIdx(l)));
        TulisPoint(COORELMT(l, getLastIdx(l)));    
        printf(")");
    }
    printf("]");
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
    /* KAMUS */
    boolean flag;
    int i;

    /* ALGORITMA */
    flag = true;
    i = 0;
    if (length(l1) == length(l2)) {
        while (i < length(l1) && flag == true) {
        if ((CHARELMT(l1,i) != CHARELMT(l2,i)) || (Absis(COORELMT(l1,i)) != Absis(COORELMT(l2,i))) || (Ordinat(COORELMT(l1,i)) != Ordinat(COORELMT(l2,i)))) {
            flag = false;
        } else {
            i++;
        }
        }
    } else {
        flag = false;
    }
    return(flag);
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfCharLoc(ListDin l, char charloc) {
    /* KAMUS */
    boolean found;
    IdxType idx;
    int i;

    /* ALGORITMA */
    idx = IDX_UNDEF;
    i = 0;
    found = false;
    while (i < length(l) && found == false) {
        if (CHARELMT(l,i) == charloc) {
            idx = i;
            found = true;
        } else {
            i++;
        }
    }
    return idx;
}

IdxType indexOfCoorLoc(ListDin l, int X, int Y) {
    /* KAMUS */
    boolean found;
    IdxType idx;
    int i;

    /* ALGORITMA */
    idx = IDX_UNDEF;
    i = 0;
    found = false;
    while (i < length(l) && found == false) {
        if ((Absis(COORELMT(l,i)) == X) && (Ordinat(COORELMT(l,i)) == Y)) {
            idx = i;
            found = true;
        } else {
            i++;
        }
    }
    return idx;
}


/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut) {
    /* KAMUS */
    int i;

    /* ALGORITMA */
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < length(lIn); i++) {
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, char charloc, int X, int Y) {
    /* KAMUS */
    /* ALGORITMA */
    CHARELMT(*l, length(*l)) = charloc;
    Absis(COORELMT(*l, length(*l))) = X;
    Ordinat(COORELMT(*l, length(*l))) = Y;
    NEFF(*l) = NEFF(*l) + 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, char *charloc, int *X, int *Y) {
    /* KAMUS */
    /* ALGORITMA */
    *charloc = CHARELMT(*l, getLastIdx(*l));
    *X = Absis(COORELMT(*l, getLastIdx(*l)));
    *Y = Ordinat(COORELMT(*l, getLastIdx(*l)));
    NEFF(*l) = NEFF(*l) - 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num) {
    /* KAMUS */
    ListDin lTemp;
    int i;

    /* ALGORITMA */
    copyList(*l, &lTemp);
    dealocate(l);
    CreateListDin(l, CAPACITY(lTemp) + num);
    NEFF(*l) = NEFF(lTemp);
    for (i = 0; i < length(lTemp); i++) {
        ELMT(*l,i) = ELMT(lTemp,i);
    }
    dealocate(&lTemp);
}

void shrinkList(ListDin *l, int num) {
    /* KAMUS */
    ListDin lTemp;
    int i;

    /* ALGORITMA */
    copyList(*l, &lTemp);
    dealocate(l);
    CreateListDin(l, CAPACITY(lTemp) - num);
    NEFF(*l) = NEFF(lTemp);
    for (i = 0; i < length(lTemp); i++) {
        ELMT(*l,i) = ELMT(lTemp,i);
    }
    dealocate(&lTemp);
}

void compactList(ListDin *l) {
    /* KAMUS */
    ListDin lTemp;
    int i;

    /* ALGORITMA */
    copyList(*l, &lTemp);
    dealocate(l);
    CreateListDin(l, NEFF(lTemp));
    NEFF(*l) = NEFF(lTemp);
    for (i = 0; i < length(lTemp); i++) {
        ELMT(*l,i) = ELMT(lTemp,i);
    }
    dealocate(&lTemp);
}

ListDin getNeighbor(Location L){
    ListDin P;
    CreateListDin(&P, COLS(adj));
    char c;
    int k = indexOfCharLoc(LocList, CHARLOC(L));
    for(int i=0; i<COLS(adj); i++){
        if(MAT(adj, k, i)){
            if(i==0){
                c = '8';
            }
            else{
                c = i+'A'-1;
            }
            insertLast(&P, c, Absis(COORELMT(LocList, i)), Ordinat(COORELMT(LocList, i)));
        }
    }
    return P;
}

void displayNeighbor(Location L){
    ListDin P;
    P = getNeighbor(L);
    for(int i=0; i<NEFF(P); i++){
        if(CHARELMT(P,i)=='8'){
            printf("%d. %s ", i+1, "HQ");
        }
        else{
            printf("%d. %c ", i+1, CHARELMT(P, i));
        }
        
        TulisPoint(COORELMT(P, i));
        printf("\n");
    }
}