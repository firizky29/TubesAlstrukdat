// NIM : 13520076
// Nama : Claudia
// Tanggal : 27 Oktober 2021
// Topik Praktikum : ADT List Berkait
// Deskripsi : Membuat ADT List Berkait

#include<stdio.h>
#include"list_linked.h"

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(LinkedList *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(LinkedList l){
/* Mengirim true jika list kosong */
    return FIRST(l) == NULL;
}

/****************** GETTER SETTER ******************/
Pesanan getElmt(LinkedList l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    // tetep harus dicacah dari nol
    int idxcount = 0;
    Address p = FIRST(l);

    while (idxcount<idx){
        idxcount += 1;
        p = NEXT(p);
    }

    return INFO(p);
}

void setElmt(LinkedList *l, int idx, Pesanan val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    int idxcount = 0;
    Address p = FIRST(*l);

    while (idxcount<idx){
        idxcount += 1;
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOf(LinkedList l, Pesanan val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    int idxcount = 0;
    Address p = FIRST(l);
    boolean found = false;

    while (p != NULL && !found){
        if (isEqualPesanan(INFO(p),val)){
            found = true;
        } else {
            idxcount += 1;
            p = NEXT(p);
        }
    }

    if (found){
        return idxcount;
    } else {
        return IDX_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(LinkedList *l, Pesanan val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    Address p = newNode(val);
    if (p != NULL){
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLastLL(LinkedList *l, Pesanan val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if(isEmpty(*l)){ // kondisi jika l kosong
        insertFirst(l,val);
    } else { // jika l tidak kosong
        Address p = newNode(val);
        Address last = FIRST(*l); // lakukan pencarian terhadap address last
        while (NEXT(last) != NULL){
            last = NEXT(last);
        }
        // address elemen terakhir sudah ketemu
        NEXT(last) = p;
    }
}

void insertAt(LinkedList *l, Pesanan val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (idx == 0){
        insertFirst(l,val);
    } else {
        Address p = newNode(val);
        if (p != NULL){
            int idxcount = 0;
            Address location = FIRST(*l);
            while (idxcount<idx-1){
                idxcount += 1;
                location = NEXT(location);
            }
            // ketika idxcount == idx -1
            NEXT(p) = NEXT(location); // next p menunjuk ke address index ke-idx+1
            NEXT(location) = p; // next dari location menuju ke address index ke-idx
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(LinkedList *l, Pesanan *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    Address p = FIRST(*l);
    
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);

}

void deleteLastLL(LinkedList *l, Pesanan *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    Address p = FIRST(*l);
    Address location = NULL;

    while (NEXT(p) != NULL){
        location = p;
        p = NEXT(p); 
        // location selalu di belakang p
    }

    if (location == NULL){ // jika elemen list l hanya 1
        FIRST(*l) = NULL;
    } else {
        NEXT(location) = NULL;
    }
    *val = INFO(p);
    free(p);

}

void deleteAt(LinkedList *l, int idx, Pesanan *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    if (idx == 0){
        deleteFirst(l,val);
    } else {
        int idxcount = 0;
        Address location = FIRST(*l);
        
        while (idxcount<idx-1){
            idxcount += 1;
            location = NEXT(location);
        }
        Address p = NEXT(location);
        *val = INFO(p);
        NEXT(location) = NEXT(p);
        free(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/

int lengthLL(LinkedList l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int idxcount = 0;
    Address p = FIRST(l);

    while (p != NULL){
        idxcount += 1;
        p = NEXT(p);
    }

    return idxcount;
}
