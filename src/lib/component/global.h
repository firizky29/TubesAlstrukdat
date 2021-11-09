#ifndef GLOBAL_H
#define GLOBAL_H
#define ll long long

#include "../data-structure/stack/stack.h"
#include "../data-structure/point/point.h"
#include "../data-structure/list-dinamis/listdin.h"


// kapasitas stack

// kapasitas matrix
#define ROW_CAP 100
#define COL_CAP 100



// P: Jumlah pesanan
extern int P;
extern ll curTime;
extern Point curPosition;
extern ll curMoney;
extern int curSpeed;
extern Stack curBag;
// extern List curInventory;
// extern LinkedList curProgress;
// extern Queue curUsedGadget;
extern boolean speedBoost;
extern int countHeavyItem;
extern int countMove;

#endif