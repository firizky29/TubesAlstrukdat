#include <stdio.h>
#include <boolean.h>
#include <point.h>

int main(){
    /* KAMUS */
    Point P1, P2;
    int X,Y,geserX,geserY;

    /* ALGORITMA */
    /* Test Baca/Tulis */
    printf("Test Baca/Tulis\n");
    printf("Masukkan absis dan ordinat (P1): ");
    scanf("%d %d", &X, &Y);
    P1 = MakePoint(X,Y);
    printf("Point (P1) yang terbaca: ");
    TulisPoint(P1);
    printf("\n");
    printf("Masukkan absis dan ordinat (P2): ");
    scanf("%d %d", &X, &Y);
    P2 = MakePoint(X,Y);
    printf("Point (P2) yang terbaca: ");
    TulisPoint(P2);
    printf("\n\n");

    /* Test Operasi Relasional */
    printf("Test Operasi Relasional\n");
    if (EQ(P1,P2)) {
        printf("P1 sama dengan P2\n");
    }
    else {
        printf("P1 tidak sama dengan P2\n");
    }
    printf("\n");

    /* TES MENGGESER POINT */
    printf("TES MENGGESER POINT\n");
    printf("P1 digeser sejajar sumbu X sejauh: ");
    scanf("%d", &geserX);
    printf("P1 digeser sejajar sumbu Y sejauh: ");
    scanf("%d", &geserY);
    printf("P1 setelah digeser: ");
    PlusDelta(&P1, geserX, geserY);
    TulisPoint(P1);
    printf("\n");

    return 0;
}