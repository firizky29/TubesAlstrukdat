#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** Konstruktor membentuk Point *** */
Point MakePoint (float X, float Y) {
/* Membentuk sebuah Point dari komponen-komponennya */
    /* KAMUS */
    Point P;
    /* ALGORITMA */
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPoint (Point * P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   Point P berdasarkan dari nilai absis dan ordinat tersebut */
    /* KAMUS */
    float X, Y;
    /* ALGORITMA */
    scanf("%f %f", &X, &Y);
    *P =  MakePoint(X, Y);
}
void TulisPoint (Point P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" tanpa spasi, enter, 
   atau karakter lain di depan, belakang, atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */
    /* KAMUS */
    /* ALGORITMA */
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap Point *** */
boolean EQ (Point P1, Point P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    /* KAMUS */
    /* ALGORITMA */
    return (Absis(P1)== Absis(P2) && Ordinat(P1) == Ordinat(P2));
}
boolean NEQ (Point P1, Point P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return (!EQ(P1,P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (Point P) {
/* Menghasilkan true jika P adalah titik origin */
    /* KAMUS */
    /* ALGORITMA */
    return (Absis(P) == 0 && Ordinat(P) == 0);
}
boolean IsOnSbX (Point P) {
/* Menghasilkan true jika P terletak Pada sumbu X */
    /* KAMUS */
    /* ALGORITMA */
    return (Absis(P) != 0 && Ordinat(P) == 0);
}
boolean IsOnSbY (Point P) {
/* Menghasilkan true jika P terletak pada sumbu Y */
    /* KAMUS */
    /* ALGORITMA */
    return (Absis(P) == 0 && Ordinat(P) != 0);
}
int Kuadran (Point P) {
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, dan P tidak terletak di salah satu sumbu */
    /* KAMUS */
    /* ALGORITMA */
    if (Absis(P) > 0 && Ordinat(P) > 0) {
        return 1;
    } else if (Absis(P) < 0 && Ordinat(P) > 0) {
        return 2;
    } else if (Absis(P) < 0 && Ordinat(P) < 0) {
        return 3;
    } else {
        return 4;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
Point NextX (Point P) {
/* Mengirim salinan P dengan absis ditambah satu */   
    /* KAMUS */
    Point PNew;
    /* ALGORITMA */
    PNew =  MakePoint(Absis(P)+1, Ordinat(P));
    return(PNew);
}
Point NextY (Point P) {
/* Mengirim salinan P dengan ordinat ditambah satu */
    /* KAMUS */
    Point PNew;
    /* ALGORITMA */
    PNew =  MakePoint(Absis(P), Ordinat(P)+1);
    return(PNew);
}
Point PlusDelta (Point P, float deltaX, float deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    /* KAMUS */
    Point PNew;
    /* ALGORITMA */
    PNew =  MakePoint(Absis(P)+deltaX, Ordinat(P)+deltaY);
    return(PNew);
}
Point MirrorOf (Point P, boolean SbX) {
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    /* KAMUS */
    Point PNew;
    /* ALGORITMA */
    if (SbX == true) {
        PNew =  MakePoint(Absis(P), Ordinat(P) * (-1));
    } else {
        PNew =  MakePoint(Absis(P) * (-1), Ordinat(P));
    }
    return(PNew);
}
float Jarak0 (Point P) {
/* Menghitung jarak P ke (0,0) */
    /* KAMUS */
    float jarak;
    /* ALGORITMA */
    jarak = sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
    return (jarak);
}
float Panjang (Point P1, Point P2) {
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
    /* KAMUS */
    float jarak;
    /* ALGORITMA */
    jarak = sqrt(pow((Absis(P1) - Absis(P2)), 2) + pow((Ordinat(P1) - Ordinat(P2)), 2));
    return (jarak);
}
void Geser (Point *P, float deltaX, float deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    /* KAMUS */
    /* ALGORITMA */
    *P =  MakePoint(Absis(*P) + deltaX, Ordinat(*P) + deltaY);
}
void GeserKeSbX (Point *P) {
/* Proses : P digeser ke sumbu X. */
    /* KAMUS */
    /* ALGORITMA */
    *P =  MakePoint(Absis(*P), 0);
}
void GeserKeSbY (Point *P) {
/* Proses : P digeser ke sumbu Y. */
    /* KAMUS */
    /* ALGORITMA */
    *P =  MakePoint(0, Ordinat(*P));
}
void Mirror (Point *P, boolean SbX) {
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    /* KAMUS */
    /* ALGORITMA */
    if (SbX == true) {
        *P =  MakePoint(Absis(*P), Ordinat(*P) * (-1));
    } else {
        *P =  MakePoint(Absis(*P) * (-1), Ordinat(*P));
    }
}
void Putar (Point *P, float Sudut) {
/* P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
    /* KAMUS */
    float radians;
    float XNew, YNew;
    const float PI = 3.14159;
    /* ALGORITMA */
    radians = Sudut * PI / 180;
    XNew = cos(radians) * Absis(*P) - sin(radians) * Ordinat(*P);
    YNew = sin(radians) * Absis(*P) + cos(radians) * Ordinat(*P);
    *P =  MakePoint(XNew, YNew);
}