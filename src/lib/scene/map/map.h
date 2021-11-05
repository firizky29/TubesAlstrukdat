#ifndef MAP_H
#define MAP_H

#include "../../data-structure/list-dinamis/listdin.h"
#include "../../data-structure/matriks/matrix.h"

extern int N, M, L;
// N: rows, M: cols, L: location

typedef struct  map{
    Matrix Adj;
    Matrix Peta;
    ListDin Building;
} Map;
extern Map curMap;

/* Setter dan getter */
#define ADJ(m) (m).Adj
#define MAP(m) (m).Peta
#define BUILDING(m) (m).Building

void setAdj(Map *m, Matrix Adj);
void setPeta(Map *m, Matrix Peta);
void setBuilding(Map *m, ListDin Building);

/* Display Map */
void DisplayMap(Map m);


#endif