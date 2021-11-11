#ifndef INITSTATE_H
#define INITSTATE_H

#include <wordmachine.h>
#include <global.h>
#include <peta.h>
#include <dirent.h>


/* GET INFO FROM CONFIG FILE */
void getMap();
/* get n x m from config and return n x m matrix */
Point getPoint();
/* get and return point from config */
void getAdjacency(Matrix *m, int n);
/* get and return adjacency matrix from config */
void getLoc(Point pointhq);
/* get char and coord of loc and return list dinamis */

/* global init */
void globalinit();
/* Menginisialisasi segala hal */

void interface();

#endif