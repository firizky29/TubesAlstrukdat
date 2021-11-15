#ifndef GLOBAL_H
#define GLOBAL_H
#define ll long long

#include <stack.h>
#include <point.h>
#include <liststat.h>
#include <list_linked.h>
#include <queue.h>

// P: Jumlah pesanan
extern int P;
extern long curTime;
extern long curMoney;
extern int curSpeed;
extern Stack curBag;
extern Inventory curInventory;
extern LinkedList curProgress;
extern LinkedList curToDoList;
extern Queue daftarPesanan;

// extern Queue curUsedGadget; {maaf kayaknya ini ga perlu, karna gadget langsung dipakai di saat itu juga biar ga susah}
extern boolean speedBoost;
extern int countHeavyItem ;
extern int countMove;

#endif