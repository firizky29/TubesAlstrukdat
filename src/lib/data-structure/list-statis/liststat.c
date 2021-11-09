#include <stdio.h>
#include <liststat.h>

void CreateInventory(Inventory *inv){
    for(int i=0 ; i < INVENTORY_CAP; i++ ){
        IDGADGET(*inv, i) = IDGADGET_UNDEF;
        HARGAGADGET(*inv, i) = HARGAGADGET_UNDEF;
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
            i += 1;
            }
        }
    }
}

void displayGadget(Inventory *inv){
    for(int i=0 ; i < INVENTORY_CAP; i++ ){
        printf("%d ",i+1);
        if(INVIDGADGET(*inv) == 1){
            printf("Kain Pembungkus Waktu\n");
        }else if(INVIDGADGET(*inv) == 2){
            printf("Senter Pembesar\n");
        }else if(INVIDGADGET(*inv) == 3){
            printf("Pintu Kemana Saja\n");
        }else if(INVIDGADGET(*inv) == 4){
            printf("Mesin Waktu\n");
        }else{
            printf("-\n");
        }
    }
}

boolean isInventoryEmpty(Inventory inv){
    flag = true;
    int i = 0;
    while(i < INVENTORY_CAP){
        if(IDGADGET(inv, i) != IDGADGET_UNDEF){
            flag = false;
        }
        i += 1;
    }
    return flag;
}

boolean isInventoryFull(Inventory inv){
    flag = true;
    int i = 0;
    while(i < INVENTORY_CAP){
        if(IDGADGET(inv, i) == IDGADGET_UNDEF){
            flag = false;
        }
        i += 1;
    }
    return flag;
}

void deleteGadget(Inventory *inv, int i, Gadget *val){
    IDGADGET(*val) = INVIDGADGET(*inv, i);
    HARGAGADGET(*val) = INVHARGAGADGET(*inv, i);
    IDGADGET(*val) = IDGADGET_UNDEF;
    HARGAGADGET(*val) = HARGAGADGET_UNDEF;
}