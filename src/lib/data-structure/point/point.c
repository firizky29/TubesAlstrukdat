#include <stdio.h>
#include <math.h>
#include <point.h>

/* *** Konstruktor membentuk Point *** */
Point MakePoint (int X, int Y) {
/* Membentuk sebuah Point dari komponen-komponennya */
    /* KAMUS */
    Point P;
    /* ALGORITMA */
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}


void TulisPoint (Point P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" tanpa spasi, enter, 
   atau karakter lain di depan, belakang, atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */
    /* KAMUS */
    /* ALGORITMA */
    printf("(%d,%d)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap Point *** */
boolean EQ (Point P1, Point P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    /* KAMUS */
    /* ALGORITMA */
    return (Absis(P1)== Absis(P2) && Ordinat(P1) == Ordinat(P2));
}


void PlusDelta (Point* P, int deltaX, int deltaY){
/* P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
   /* ALGORITMA */
    Absis(*P)+=deltaX;
    Ordinat(*P)+=deltaY;
}



