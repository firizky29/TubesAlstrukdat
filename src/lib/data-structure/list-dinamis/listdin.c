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

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
    /* KAMUS */
    /* ALGORITMA */
    BUFFER(*l) = (ElType*) malloc (capacity * sizeof (ElType));
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
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i) {
    /* KAMUS */
    /* ALGORITMA */
    return((i >= 0) && (i <= CAPACITY(l)));
}
boolean isIdxEff(ListDin l, IdxType i) {
    /* KAMUS */
    /* ALGORITMA */
    return((i >= 0) && (i <= NEFF(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
    /* KAMUS */
    /* ALGORITMA */
    return(NEFF(l) == 0);
}
/* *** Test list penuh *** */
boolean isFull(ListDin l) {
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
    while(!(isIdxValid(*l,n))) {
        scanf("%d", &n);
    }
    if (n > 0) {
        NEFF(*l) = n;
        for(i = 0; i < n; i++) {
            scanf(" %c", &CHARLOC(*l, i));
            scanf(" %f", &Absis(COORLOC(*l, i)));
            scanf(" %f", &Ordinat(COORLOC(*l, i)));
        }
    }
}

void displayList(ListDin l) {
    /* KAMUS */
    int i;
    /* ALGORITMA */
    printf("[");
    if (!(isEmpty(l))) {
        for (i = 0; i < getLastIdx(l); i++) {
            printf("(%c,", CHARLOC(l, i));
            TulisPOINT(COORLOC(l, i));
            printf("),");
        }
        printf("(%c,", CHARLOC(l,getLastIdx(l)));
        TulisPOINT(COORLOC(l, getLastIdx(l)));    
        printf(")");
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA (TIDAK DAPAT DIGUNAKAN) ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
// ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
//     /* KAMUS */
//     ListDin lNew;
//     int i;

//     /* ALGORITMA */
//     CreateListDin(&lNew, CAPACITY(l1));
//     NEFF(lNew) = NEFF(l1);
//     for (i = 0; i < length(l1); i++) {
//         if (plus) {
//             ELMT(lNew,i) = ELMT(l1,i) + ELMT(l2,i);
//         } else {
//             ELMT(lNew,i) = ELMT(l1,i) - ELMT(l2,i);
//         }
//     }
//     return lNew;
// }

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
        if ((CHARLOC(l1,i) != CHARLOC(l2,i)) || (Absis(COORLOC(l1,i)) != Absis(COORLOC(l2,i))) || (Ordinat(COORLOC(l1,i)) != Ordinat(COORLOC(l2,i)))) {
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
        if (CHARLOC(l,i) == charloc) {
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
        if ((Absis(COORLOC(l,i)) == X) && (Ordinat(COORLOC(l,i)) == Y)) {
            idx = i;
            found = true;
        } else {
            i++;
        }
    }
    return idx;
}

/* ********** NILAI EKSTREM (TIDAK DAPAT DIGUNAKAN) ********** */
// void extremes(ListDin l, ElType *max, ElType *min) {
//     /* KAMUS */
//     int i;

//     /* ALGORITMA */
//     *max = ELMT(l,0);
//     *min = ELMT(l,0);
//     for (i = 0; i < length(l); i++) {
//         if (ELMT(l,i) >= *max) {
//             *max = ELMT(l,i);
//         }
//         if (ELMT(l,i) <= *min) {
//             *min = ELMT(l,i);
//         }
//     }
// }

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

/* ********** TIDAK DAPAT DIGUNAKAN ********** */
// ElType sumList(ListDin l) {
//     /* KAMUS */
//     ElType sum;
//     int i;

//     /* ALGORITMA */
//     sum = 0;
//     if (!(isEmpty(l))) {
//         for (i = 0; i < length(l); i++) {
//             sum = sum + ELMT(l,i);
//         }
//     }
//     return sum;
// }
// int countVal(ListDin l, ElType val) {
//     /* KAMUS */
//     int count, i;

//     /* ALGORITMA */
//     count = 0;
//     if (!(isEmpty(l))) {
//         for (i = 0; i < length(l); i++) {
//             if (val == ELMT(l,i)) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }
// boolean isAllEven(ListDin l) {
//     /* KAMUS */
//     boolean flag;
//     int i;

//     /* ALGORITMA */
//     flag = true;
//     if (!(isEmpty(l))) {
//         i = 0;
//         while (i < length(l) && flag == true) {
//             if (ELMT(l,i) % 2 != 0) {
//                 flag = false;
//             } else {
//                 i++;
//             }
//         }
//     }
//     return flag;
// }

/* ********** SORTING (TIDAK DAPAT DIGUNAKAN) ********** */
// void sort(ListDin *l, boolean asc) {
//     /* KAMUS */
//     int i,j, idx;
//     ElType temp;

//     /* ALGORITMA */
//     for (i = 0; i < length(*l); i++) {
//         idx = i;
//         for (j = i+1; j < length(*l); j++) {
//             if (asc == true) {
//                 if (ELMT(*l,j) < ELMT(*l,idx)) {
//                     idx = j;
//                 }
//             } else { 
//                 if (ELMT(*l,j) > ELMT(*l,idx)) {
//                     idx = j;
//                 }
//             }
//         }
//         temp = ELMT(*l,idx);
//         ELMT(*l, idx) = ELMT(*l, i);
//         ELMT(*l, i) = temp;
//     }
// }

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, char charloc, float X, float Y) {
    /* KAMUS */
    /* ALGORITMA */
    CHARLOC(*l, length(*l)) = charloc;
    Absis(COORLOC(*l, length(*l))) = X;
    Ordinat(COORLOC(*l, length(*l))) = Y;
    NEFF(*l) = NEFF(*l) + 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, char *charloc, float *X, float *Y) {
    /* KAMUS */
    /* ALGORITMA */
    *charloc = CHARLOC(*l, getLastIdx(*l));
    *X = Absis(COORLOC(*l, getLastIdx(*l)));
    *Y = Ordinat(COORLOC(*l, getLastIdx(*l)));
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