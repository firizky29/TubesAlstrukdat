#include <peta.h>

// include library building
#include <listdin.h>
int main(){
    Map M;
    CreateMap(&M, 20, 20);
    DisplayMap(M);
    // Buat list of building
    ListDin L;
    CreateListDin(&L, 10);
    insertLast(&L, 'A', 1, 2);
    insertLast(&L, 'B', 2, 4);
    insertLast(&L, 'C', 1, 5);
    insertLast(&L, 'D', 10, 2);
    insertLast(&L, 'E', 1, 20);
    BuildingToMap(&M, L);
    DisplayMap(M);
}