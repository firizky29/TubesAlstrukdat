#ifndef GLOBAL_H
#define GLOBAL_H
#define ll long long

#include "../data-structure/stack/stack.h"
#include "../data-structure/point/point.h"
#include "../data-structure/list-dinamis/listdin.h"
#include "../data-structure/list-statis/liststat.h"
#include "../data-structure/list-linked/list_linked.h"


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
extern Inventory curInventory;
extern Inventory market; //dibentuk seperti curInventory tapi tidak bisa diubah
extern LinkedList curProgress;
extern LinkedList curToDoList;
// extern Queue curUsedGadget; {maaf kayaknya ini ga perlu, karna gadget langsung dipakai di saat itu juga biar ga susah}
extern boolean speedBoost;
extern int countHeavyItem ;
extern int countMove;

#endif