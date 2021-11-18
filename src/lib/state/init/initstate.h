#ifndef INITSTATE_H
#define INITSTATE_H

#include <wordmachine.h>
#include <global.h>
#include <peta.h>
#include <dirent.h>
#include <queue.h>

extern Word configName;


void getMap();
/* initialize matrix (n x m) from config */

Point getPoint();
/* get and return point from config */

void getAdjacency(Matrix *m, int n);
/* initialize adjacency matrix from config */

void getLoc(Point pointhq);
/* get char and coord of loc from config */

void getPesananList();
/* initialize daftar pesanan & to-do list from config */

void interface();
/* display start game interface */

void initConfig();
/* initialize global variables from config */

void globalinit();
/* global initialization */

#endif