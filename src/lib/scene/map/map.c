#include "map.h"
#include "../../tools/pcolor/pcolor.h"

void setAdj(Map *m, Matrix Adj){
    ADJ(*m) = Adj;
}
void setPeta(Map *m, Matrix Peta){
    MAP(*m) = Peta;
}
void setBuilding(Map *m, ListDin Building){
    BUILDING(*m) = Building;
}

/* Display Map */
void DisplayMap(Map m){
    /* Print map pake pcolor */
}