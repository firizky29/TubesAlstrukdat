#ifndef INITSTATE_H
#define INITSTATE_H

#include "../../tools/mesin-kata/wordmachine.h"
#include "../../component/global.h"
#include "../../scene/map/map.h"
#include <dirent.h>

/* GET INFO FROM CONFIG FILE */
Matrix getMap();
/* get n x m from config and return n x m matrix */
Point getPoint();
/* get and return point from config */
Matrix getAdjacency(int n);
/* get and return adjacency matrix from config */
ListDin getLoc(Point pointhq);
/* get char and coord of loc and return list dinamis */

/* global init */
void globalinit();
/* Menginisialisasi segala hal */

#endif