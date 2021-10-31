#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y) {
/* Membentuk sebuah POINT dari komponen-komponennya */
    /* KAMUS */
    POINT P;
    /* ALGORITMA */
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
    /* KAMUS */
    float X, Y;
    /* ALGORITMA */
    scanf("%f %f", &X, &Y);
    *P =  MakePOINT(X, Y);
}
void TulisPOINT (POINT P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" tanpa spasi, enter, 
   atau karakter lain di depan, belakang, atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */
    /* KAMUS */
    /* ALGORITMA */
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    /* KAMUS */
    /* ALGORITMA */
    return (Absis(P1)== Absis(P2) && Ordinat(P1) == Ordinat(P2));
}
boolean NEQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return (!EQ(P1,P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
/* Menghasilkan true jika P adalah titik origin */
    /* KAMUS */
    /* ALGORITMA */
    return (Absis(P) == 0 && Ordinat(P) == 0);
}
boolean IsOnSbX (POINT P) {
/* Menghasilkan true jika P terletak Pada sumbu X */
    /* KAMUS */
    /* ALGORITMA */
    return (Absis(P) != 0 && Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P) {
/* Menghasilkan true jika P terletak pada sumbu Y */
    /* KAMUS */
    /* ALGORITMA */
    return (Absis(P) == 0 && Ordinat(P) != 0);
}
int Kuadran (POINT P) {
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
POINT NextX (POINT P) {
/* Mengirim salinan P dengan absis ditambah satu */   
    /* KAMUS */
    POINT PNew;
    /* ALGORITMA */
    PNew =  MakePOINT(Absis(P)+1, Ordinat(P));
    return(PNew);
}
POINT NextY (POINT P) {
/* Mengirim salinan P dengan ordinat ditambah satu */
    /* KAMUS */
    POINT PNew;
    /* ALGORITMA */
    PNew =  MakePOINT(Absis(P), Ordinat(P)+1);
    return(PNew);
}
POINT PlusDelta (POINT P, float deltaX, float deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    /* KAMUS */
    POINT PNew;
    /* ALGORITMA */
    PNew =  MakePOINT(Absis(P)+deltaX, Ordinat(P)+deltaY);
    return(PNew);
}
POINT MirrorOf (POINT P, boolean SbX) {
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    /* KAMUS */
    POINT PNew;
    /* ALGORITMA */
    if (SbX == true) {
        PNew =  MakePOINT(Absis(P), Ordinat(P) * (-1));
    } else {
        PNew =  MakePOINT(Absis(P) * (-1), Ordinat(P));
    }
    return(PNew);
}
float Jarak0 (POINT P) {
/* Menghitung jarak P ke (0,0) */
    /* KAMUS */
    float jarak;
    /* ALGORITMA */
    jarak = sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
    return (jarak);
}
float Panjang (POINT P1, POINT P2) {
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
    /* KAMUS */
    float jarak;
    /* ALGORITMA */
    jarak = sqrt(pow((Absis(P1) - Absis(P2)), 2) + pow((Ordinat(P1) - Ordinat(P2)), 2));
    return (jarak);
}
void Geser (POINT *P, float deltaX, float deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    /* KAMUS */
    /* ALGORITMA */
    *P =  MakePOINT(Absis(*P) + deltaX, Ordinat(*P) + deltaY);
}
void GeserKeSbX (POINT *P) {
/* Proses : P digeser ke sumbu X. */
    /* KAMUS */
    /* ALGORITMA */
    *P =  MakePOINT(Absis(*P), 0);
}
void GeserKeSbY (POINT *P) {
/* Proses : P digeser ke sumbu Y. */
    /* KAMUS */
    /* ALGORITMA */
    *P =  MakePOINT(0, Ordinat(*P));
}
void Mirror (POINT *P, boolean SbX) {
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    /* KAMUS */
    /* ALGORITMA */
    if (SbX == true) {
        *P =  MakePOINT(Absis(*P), Ordinat(*P) * (-1));
    } else {
        *P =  MakePOINT(Absis(*P) * (-1), Ordinat(*P));
    }
}
void Putar (POINT *P, float Sudut) {
/* P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
    /* KAMUS */
    float radians;
    float XNew, YNew;
    const float PI = 3.14159;
    /* ALGORITMA */
    radians = Sudut * PI / 180;
    XNew = cos(radians) * Absis(*P) - sin(radians) * Ordinat(*P);
    YNew = sin(radians) * Absis(*P) + cos(radians) * Ordinat(*P);
    *P =  MakePOINT(XNew, YNew);
}