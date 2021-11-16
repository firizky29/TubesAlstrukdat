#include <peta.h>
#include <pcolor.h>
#include <stdio.h>

void CreateMap(Map* m, int rows, int cols){
    int i, j;
    for(i=0; i<rows+2; i++){
        for(j=0; j<cols+2; j++){
            if(i==0||i==rows+1||j==0||j==cols+1){
                TILE(*m, i, j) = '#';
            }
            else{
                TILE(*m, i, j) = ' ';
            }
        }
    }
    REFF(*m) = rows+2;
    CEFF(*m) = cols+2;
}

void BuildingToMap(Map* m, ListDin L){
    /* m sudah terdefinisi dan koordinat L tidak overflow */
    int i;
    for(i=0; i<NEFF(L); i++){
        TILE(*m, Absis(COORELMT(L,i)), Ordinat(COORELMT(L, i))) = CHARELMT(L, i);
    }
}
/* Display Map */
void DisplayMap(Map m){
    /* Print map pake pcolor */
    int i, j, k;
    for(i = 0; i<REFF(m); i++){
        for(j=0; j<CEFF(m); j++){
            k = indexOfCoorLoc(LocList, i,j);
            if(k == IDX_UNDEF){
                printf("%c", TILE(m, i, j));
            }
            else if(isMobitaPoint(ELMT(LocList, k))){
                print_yellow(TILE(m, i, j));
            }
            else if(isDropOffPoint(ELMT(LocList, k))){
                print_blue(TILE(m, i, j));
            }
            else if(isPickUpPoint(ELMT(LocList, k))&&!countVIP){
                print_red(TILE(m, i, j));
            }
            else if(countVIP && HasVIPItem(ELMT(LocList, k))){
                print_red(TILE(m, i, j));
            }
            else if(isAdjacent(curPosition, ELMT(LocList, k))){
                print_green(TILE(m, i, j));
            }
            else{
                printf("%c", TILE(m, i, j));
            }
            if(j==CEFF(m)-1){
                printf("\n");
            }
        }
    }
}