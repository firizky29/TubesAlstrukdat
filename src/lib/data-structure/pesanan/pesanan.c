#include<stdio.h>
#include"pesanan.h"

Pesanan CreatePesanan(int T, char PU, char DO, char TP, int PT){
/* Membentuk Pesanan */
/* Mereturn pesanan yang akan dimasukkan ke dalam queue/linkedlist */
    Pesanan P;
    TIMEPESANAN(P) = T;
    PICKUPPESANAN(P) = PU;
    DROPOFFPESANAN(P) = DO;
    TIPEITEM(P) = TP;
    PTIME(P) = PT;

    return P;
}
void displayPesanan(Pesanan P){
/* Menulis Pesanan dengan format time pickup dropoff type ptime */
    printf("%d %c %c %c %d",TIMEPESANAN(P),PICKUPPESANAN(P),DROPOFFPESANAN(P),TIPEITEM(P),PTIME(P));
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