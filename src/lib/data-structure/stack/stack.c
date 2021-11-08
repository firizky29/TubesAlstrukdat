/* NIM/NAMA : 13520095/FIRIZKY ARDIANSYAH */
/* TANGGAL : 16/10/2021 */
/* LIBRARY STACK*/
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    IDX_TOP(*s) = IDX_UNDEF;
}

/* ************ Prototype ************ */
boolean isStackEmpty(Stack s){
/* Mengirim true jika s kosong: lihat definisi di atas */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return IDX_TOP(s) == IDX_UNDEF;
}
boolean isStackFull(Stack s){
/* Mengirim true jika tabel penampung nilai s stack penuh */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return IDX_TOP(s) == CURCAP(s)-1;
}

boolean isCanUpgrade(Stack s){
/* Mengirim true jika s masih upgradeable */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return CURCAP(s) == STACK_CAP;
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, Pesanan val){
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if(isStackEmpty(*s)){
        IDX_TOP(*s) = 0;
    }
    else{
        IDX_TOP(*s)++;
    }
    TOP(*s) = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, Pesanan *val){
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *val = TOP(*s);
    if(IDX_TOP(*s)==0){
        IDX_TOP(*s) = IDX_UNDEF;
    }
    else{
        IDX_TOP(*s)--;
    }
}