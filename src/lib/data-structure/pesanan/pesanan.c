#include <stdio.h>
#include <pesanan.h>
Pesanan CreatePesanan(int T, char PU, char DO, char TP, int PT, int W){
/* Membentuk Pesanan */
/* Mereturn pesanan yang akan dimasukkan ke dalam queue/linkedlist */
    Pesanan P;
    TIMEPESANAN(P) = T;
    PICKUPPESANAN(P) = PU;
    DROPOFFPESANAN(P) = DO;
    TIPEITEM(P) = TP;
    PTIME(P) = PT;
    WEIGHT(P) = W;

    return P;
}
void displayPesanan(Pesanan P){
/* Menulis Pesanan dengan format time pickup dropoff type ptime */
    printf("%d %c %c %c %d %d",TIMEPESANAN(P),PICKUPPESANAN(P),DROPOFFPESANAN(P),TIPEITEM(P), PTIME(P), WEIGHT(P));
}

void subtractPtime(Pesanan *P, int decr){
/* Mengurangi waktu dari perishable item sebanyak decr, jika waktu >= 0 */
    if (PTIME(*P)>=0){
        if(PTIME(*P)>=decr){
            PTIME(*P) -= decr;
        }
        else{
            PTIME(*P) = 0;
        }
    }
}

boolean isXItem(Pesanan P, char itemChar){
/* Mereturn true jika Pesanan P berisi item bertipe itemChar */
    return (TIPEITEM(P) == itemChar);
}

boolean isEqualPesanan(Pesanan P1, Pesanan P2){
/* Mereturn true jika Pesanan P1 sama dengan Pesanan P2 */
/* Perishable time dan weight tidak diperhitungkan karena dapat berubah-ubah */
    return (TIMEPESANAN(P1) == TIMEPESANAN(P2)) && (PICKUPPESANAN(P1) == PICKUPPESANAN(P2)) && (DROPOFFPESANAN(P1) == DROPOFFPESANAN(P2)) && (TIPEITEM(P1) == TIPEITEM(P2));
}