/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDIN_H
#define LISTDIN_H

// #include "../../../boolean.h"
#include <point.h>
#include <global.h>
#include <matrix.h>

#define IDX_UNDEF -1
typedef int IdxType;
/*  Kamus Umum */

/* Definisi elemen dan koleksi objek */
typedef struct {
    char charLoc;  /* berisi alfabetis lokasi, 8 jika HQ, A-Z jika lokasi lain, BLANK jika kosong */
    Point coorLoc;
} Location; /* type elemen list */


typedef struct{
    Location *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDin;
extern ListDin LocList;
extern Location curPosition;

/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i
   l.buffer[i].charloc untuk mengakses karakter lokasi elemen ke-i
   l.buffer[i].coorloc untuk mengakses  koordinat lokasi elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity
#define CHARELMT(l,i) CHARLOC(((l).buffer[i]))
#define COORELMT(l, i) COORLOC((l).buffer[i])
#define CHARLOC(L) (L).charLoc
#define COORLOC(L) (L).coorLoc


void setLocComponent(Location *L, int x, int y, char c);
/* Set lokasi di titik (x, y) bangunan c*/
void setLoc(Location *L, Location L1);
/* Mengcopy lokasi L1 ke L */
void displayLoc(Location L);
/* display lokasi */
boolean IsHQ (Location P);
/* Mereturn True jika P ada di HQ */
boolean isSpace(Location P);
/* Mereturn True jika titik di lokasi P tidak ada bangunannya */
boolean isDropOffPoint(Location P);
/* Mereturn True jika barang paling atas dari tas perlu di dropoff di P */
boolean isPickUpPoint(Location P);
/* Mereturn True jika Lokasi P memiliki barang untuk di pickup*/
boolean isMobitaPoint(Location P);
/* Mereturn True jika P adalah current position dari Mobita*/
ListDin getNeighbor(Location L);
/* Menghasilkan list dari tetangga lokasi L */
void displayBuilding(ListDin P);
/* Menampilkan list of bangunan P */
boolean isAdjacent(Location L1, Location L2);
/* Mengirimkan true jika L2 bisa dicapai dari L1 */
boolean HasVIPItem(Location P);
/* Mengirimkan true jika ada VIP item di location P */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocate(ListDin *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListEmpty(ListDin l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isListFull(ListDin l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l);
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void displayList(ListDin l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai (A,(10,1)), (B,(1,15)), (C,(1,9)) akan dicetak: [(A,(10,1)), (B,(1,15)),(C,(1,9))] */
/* Jika list kosong : menulis [] */


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfCharLoc(ListDin l, char charloc);
/* Search apakah ada karakter lokasi elemen List l yang bernama charloc */
/* Jika ada, menghasilkan indeks i terkecil, dengan karakter lokasi elemen ke-i = charloc */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

IdxType indexOfCoorLoc(ListDin l, int X, int Y);
/* Search apakah ada koordinat lokasi elemen List l yang berkoordinat (X,Y) */
/* Jika ada, menghasilkan indeks i terkecil, dengan koordinat lokasi elemen ke-i = (X,Y)) */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM (TIDAK DAPAT DIGUNAKAN) ********** */
/* void extremes(ListDin l, ElType *max, ElType *min); */
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, char charloc, int X, int Y);
/* Proses: Menambahkan charloc, X, dan Y sebagai karakter dan koordinat lokasi elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, char *charloc, int *X, int *Y);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. charloc, X, dan Y adalah karakter dan koordinat lokasi elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactList(ListDin *l);
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */


#endif