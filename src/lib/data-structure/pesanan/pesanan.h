/* File : pesanan.h */

#ifndef PESANAN_H
#define PESANAN_H

#include <stdlib.h>
#include <boolean.h>

typedef struct pesanan {
    int time; /*waktu pesanan muncul*/
    char pickup; /* bangun pick up item */
    char dropoff; /* bangun drop off item */
    char type; /* tipe item : N = Normal item; H = Heavy item; P = Perishable item; V = VIP item*/
    int weight; /* non Heavy : besarnya 0, Heavy item: 1 */
    int ptime; /* waktu hangus jika perishable item */
    /* ptime hanya akan berubah di inprogress list, di tas ptime tidak berubah */
} Pesanan;

/* Selektor */
#define TIMEPESANAN(p) (p).time
#define PICKUPPESANAN(p) (p).pickup
#define DROPOFFPESANAN(p) (p).dropoff
#define TIPEITEM(p) (p).type
#define PTIME(p) (p).ptime
#define WEIGHT(p) (p).weight

#define TIME_UNDEF (-1)

/* Konstruktor */
Pesanan CreatePesanan(int T, char PU, char DO, char TP, int PT, int W);
/* Membentuk Pesanan */
/* Mereturn pesanan yang akan dimasukkan ke dalam queue/linkedlist */

void displayPesanan(Pesanan P);
/* Menulis Pesanan dengan format time pickup dropoff type ptime */

void subtractPtime(Pesanan *P, int decr);
/* Mengurangi waktu dari perishable item sebanyak decr, jika waktu >= 0 */

boolean isXItem(Pesanan P, char itemChar);
/* Mereturn true jika Pesanan P berisi item bertipe itemChar */

boolean isEqualPesanan(Pesanan P1, Pesanan P2);
/* Mereturn true jika Pesanan P1 sama dengan Pesanan P2 */
/* Perishable time tidak diperhitungkan karena dapat berubah-ubah */

#endif