#ifndef PESANAN_H
#define PESANAN_H

#include <stdlib.h>

typedef struct pesanan {
    int time;
    char pickup;
    char dropoff;
    char type;
    int ptime;
} Pesanan;

#define TIMEPESANAN(p) (p).time
#define PICKUPPESANAN(p) (p).pickup
#define DROPOFFPESANAN(p) (p).dropoff
#define TIPEITEM(p) (p).type
#define PTIME(p) (p).ptime

#endif