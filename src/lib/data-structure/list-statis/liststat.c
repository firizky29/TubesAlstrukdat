#include <stdio.h>
#include <liststat.h>

void CreateGadget(Gadget *g){
    IDGADGET(*g) = IDGADGET_UNDEF;
    HARGAGADGET(*g) = HARGAGADGET_UNDEF;
}
void setGadget(Gadget *g, int id, int harga){
    IDGADGET(*g) = id;
    HARGAGADGET(*g) = harga;
}
void CreateInventory(Inventory *inv){
    for(int i=0 ; i < INVENTORY_CAP; i++ ){
        INVIDGADGET(*inv, i) = IDGADGET_UNDEF;
        INVHARGAGADGET(*inv, i) = HARGAGADGET_UNDEF;
    }
}

void addGadget(Inventory *inv, Gadget g){
    if(isInventoryFull(*inv)){
        printf(" Inventory penuh!\n");
    }else{
        int i = 0;
        boolean flag = true;
        while(i < INVENTORY_CAP && flag){
            if (INVIDGADGET(*inv,i) == IDGADGET_UNDEF){
                INVIDGADGET(*inv,i) = IDGADGET(g); 
                INVHARGAGADGET(*inv,i) = HARGAGADGET(g); 
                flag = false;
            i += 1;
            }
        }
    }
}

void displayGadgetinInventory(Inventory inv){
    for(int i=0 ; i < INVENTORY_CAP; i++ ){
        printf("%d. ",i+1);
        if(INVIDGADGET(inv,i) == 1){
            printf("Kain Pembungkus Waktu\n");
        }else if(INVIDGADGET(inv,i) == 2){
            printf("Senter Pembesar\n");
        }else if(INVIDGADGET(inv,i) == 3){
            printf("Pintu Kemana Saja\n");
        }else if(INVIDGADGET(inv,i) == 4){
            printf("Mesin Waktu\n");
        }else if(INVIDGADGET(inv,i) == 5){
            printf("Senter Pengecil\n");
        }else{
            printf("-\n");
        }
    }
}

boolean isInventoryEmpty(Inventory inv){
    boolean flag = true;
    int i = 0;
    while(i < INVENTORY_CAP && flag){
        if(INVIDGADGET(inv, i) != IDGADGET_UNDEF){
            flag = false;
        }
        i += 1;
    }
    return flag;
}

boolean isInventoryFull(Inventory inv){
    boolean flag = true;
    int i = 0;
    while(i < INVENTORY_CAP && flag){
        if(INVIDGADGET(inv, i) == IDGADGET_UNDEF){
            flag = false;
        }
        i += 1;
    }
    return flag;
}

void deleteGadget(Inventory *inv, int i, Gadget *val){
    IDGADGET(*val) = INVIDGADGET(*inv, i);
    HARGAGADGET(*val) = INVHARGAGADGET(*inv, i);
    INVIDGADGET(*inv,i) = IDGADGET_UNDEF;
    INVHARGAGADGET(*inv,i) = HARGAGADGET_UNDEF;
}