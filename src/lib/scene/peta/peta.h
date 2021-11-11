#ifndef MAP_H
#define MAP_H

#include <listdin.h>
#include <matrix.h>
extern int N, M, L;
// N: rows, M: cols, L: location

typedef struct{
    char Tile[ROW_CAP+2][COL_CAP+2];
    int REff;
    int CEff;
} Map;
extern Map curMap;


/* Setter dan getter */
#define TILE(M, i, j) (M).Tile[i][j] 
#define REFF(M) (M).REff
#define CEFF(M) (M).CEff
void CreateMap(Map* m, int rows, int cols);
void BuildingToMap(Map* m, ListDin L);
void DisplayMap(Map m);

#endif