/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H
#include "../../boolean.h"
#include "../pesanan/pesanan.h"


#define STACK_CAP 100
typedef int IdxType;
#define IDX_UNDEF -1
typedef struct {
  Pesanan buffer[STACK_CAP]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
  int Neff;
} Stack;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define IDX_TOP(s) (s).idxTop
#define     TOP(s) (s).buffer[(s).idxTop]
#define    NEFF(s) (s).NEFF

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isStackEmpty(Stack s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isStackFull(Stack s);
/* Mengirim true jika tabel penampung nilai s stack penuh */
boolean isCanUpgrade(stack s);
/* Mengirim true jika s masih upgradeable */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, int val);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, int *val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

#endif