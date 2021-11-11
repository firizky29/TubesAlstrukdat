#include<stdio.h>
#include"pesanan.h"

Pesanan CreatePesanan(int T, char PU, char DO, char TP, int FPI, int PT){
/* Membentuk Pesanan */
/* Mereturn pesanan yang akan dimasukkan ke dalam queue/linkedlist */
    Pesanan P;
    TIMEPESANAN(P) = T;
    PICKUPPESANAN(P) = PU;
    DROPOFFPESANAN(P) = DO;
    TIPEITEM(P) = TP;
    FIRSTPITEM(P) = FPI;
    PTIME(P) = PT;

    return P;
}
void displayPesanan(Pesanan P){
/* Menulis Pesanan dengan format time pickup dropoff type ptime */
    printf("%d %c %c %c %d %d",TIMEPESANAN(P),PICKUPPESANAN(P),DROPOFFPESANAN(P),TIPEITEM(P),FIRSTPITEM(P), PTIME(P));
}

void subtractPtime(Pesanan *P){
/* Mengurangi waktu dari perishable item sebanyak 1, jika waktu >= 0 */
    if (PTIME(*P)>=0){
        PTIME(*P) -= 1;
    }
}

boolean isXItem(Pesanan P, char itemChar){
/* Mereturn true jika Pesanan P berisi item bertipe itemChar */
    return (TIPEITEM(P) == itemChar);
}

boolean isEqualPesanan(Pesanan P1, Pesanan P2){
/* Mereturn true jika Pesanan P1 sama dengan Pesanan P2 */
/* Perishable time tidak diperhitungkan karena dapat berubah-ubah */
    return (TIMEPESANAN(P1) == TIMEPESANAN(P2)) && (PICKUPPESANAN(P1) == PICKUPPESANAN(P2)) && (DROPOFFPESANAN(P1) == DROPOFFPESANAN(P2)) && (TIPEITEM(P1) == TIPEITEM(P2)) && (FIRSTPITEM(P1)==FIRSTPITEM(P2));
}