#include <stdio.h>
#include "liststat.h"

int main(){
    Gadget G1,G2,G3,G4,G5;
    Inventory I;
    //Konstruksi Gadget
    CreateGadget(&G1);
    CreateGadget(&G2);
    CreateGadget(&G3);
    CreateGadget(&G4);
    CreateGadget(&G5);
    //Konstruksi Inventory
    CreateInventory(&I);

    //Inisialisasi nilai gadget
    setGadget(&G1, 1, 800);
    setGadget(&G2, 2, 1200);
    setGadget(&G3, 3, 1500);
    setGadget(&G4, 4, 3000);
    setGadget(&G5, 5, 800);

    //Memeriksa Inventory kosong
    if (isInventoryEmpty(I)){
        printf("Inventory is empty\n");
    }

    printf("Adding gadget to Inventory ..... \n");
    //Menambahkan gadget ke dalam Inventory
    addGadget(&I, G1);
    addGadget(&I, G2);
    addGadget(&I, G3);
    addGadget(&I, G4);
    addGadget(&I, G5);

    //Memeriksa Inventory penuh
    if (isInventoryFull(I)){
        printf("Inventory is full. This is your inventory :\n");
        //Menampilkan Inventory
        displayGadgetinInventory(I);
    }

    Gadget temp;
    printf("\nDeleting all gadget in Inventory\n");
    for(int i=0; i<5 ; i++){
        //Menghapus Gadget pada Inventory
        deleteGadget(&I, i, &temp);
        if (isInventoryEmpty(I)){
            printf("Okey. Now it's empty...");
        }
    }

}
