#ifndef PESANAN_H
#define PESANAN_H

#include <stdlib.h>
#include "../../boolean.h"

typedef struct pesanan {
    int time; /*waktu pesanan muncul*/
    char pickup; /* bangun pick up item */
    char dropoff; /* bangun drop off item */
    char type; /* tipe item : N = Normal item; H = Heavy item; P = Perishable item; V = VIP item*/
    int firstptime;
    int ptime; /* waktu hangus jika perishable item */
} Pesanan;

#define TIMEPESANAN(p) (p).time
#define PICKUPPESANAN(p) (p).pickup
#define DROPOFFPESANAN(p) (p).dropoff
#define TIPEITEM(p) (p).type
#define FIRSTPITEM(p) (p).firstptime
#define PTIME(p) (p).ptime

#define TIME_UNDEF (-1)

Pesanan CreatePesanan(int T, char PU, char DO, char TP, int PT);
/* Membentuk Pesanan */
/* Mereturn pesanan yang akan dimasukkan ke dalam queue/linkedlist */

void displayPesanan(Pesanan P);
/* Menulis Pesanan dengan format time pickup dropoff type ptime */

void subtractPtime(Pesanan *P);
/* Mengurangi waktu dari perishable item sebanyak 1, jika waktu >= 0 */

boolean isXItem(Pesanan P, char itemChar);
/* Mereturn true jika Pesanan P berisi item bertipe itemChar */

boolean isEqualPesanan(Pesanan P1, Pesanan P2);
/* Mereturn true jika Pesanan P1 sama dengan Pesanan P2 */
/* Perishable time tidak diperhitungkan karena dapat berubah-ubah */

#endif