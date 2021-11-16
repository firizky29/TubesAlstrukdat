#include <savestate.h>
#include <initstate.h>
#include <loadstate.h>
#include <stdio.h>
#include <stdlib.h>

LinkedList reverseStack(Stack *s){
    LinkedList rStack;
    CreateList(&rStack);
    Pesanan p;
    while (!isStackEmpty(curBag)){
        pop(&curBag, &p);
        insertFirst(&rStack, p);
    }
    return rStack;
}

void save(){
    char* saveDir = "data/saved-file/";
	printf("Save file as (filename): \n");
	Word file = inputWord();
    Word path;
    strcpy(path.contents, saveDir);
    strcat(path.contents, file.contents);
    strcat(path.contents, ".txt");
    path.length = 21+file.length;
	FILE *f = fopen(path.contents, "w");
	if (f == NULL)
	{
		printf("Oops! Error saving file\n");
		exit(1);
	}
	emptyWord();
    printf("Saving ");
    printWord(file);
    printf("....\n");

    // save config (config name)
    fprintf(f, "%s\n", configName.contents);
    // save location (curposition)
    fprintf(f, "%c %d %d\n", CHARLOC(curPosition), Absis(COORLOC(curPosition)), Ordinat(COORLOC(curPosition)));
    // save non-adt progress
    fprintf(f, "%ld\n", curTime);
    fprintf(f, "%ld\n", curMoney);
    fprintf(f, "%d\n", curSpeed);
    fprintf(f, "%d\n", speedBoost);
    fprintf(f, "%d\n", countHeavyItem);
    fprintf(f, "%d\n", countMove);
    int i;
    Pesanan pesan;
    LinkedList rStack;
    // save stack (curbag)
    fprintf(f, "%d\n", CURCAP(curBag));
    rStack = reverseStack(&curBag);
    fprintf(f, "%d\n", lengthLL(rStack));
    for (i = 0; i < lengthLL(rStack); i++){
        pesan = getElmt(rStack, i);
        fprintf(f, "%d ", TIMEPESANAN(pesan));
        fprintf(f, "%c ", PICKUPPESANAN(pesan));
        fprintf(f, "%c ", DROPOFFPESANAN(pesan));
        fprintf(f, "%c ", TIPEITEM(pesan));
        fprintf(f, "%d\n", PTIME(pesan));
    }
    // save inventory (curInventory)
    fprintf(f, "%d\n", INVENTORY_CAP);
    for (i = 0; i < INVENTORY_CAP; i++){
        fprintf(f, "%d ", INVIDGADGET(curInventory, i));
        fprintf(f, "%d\n", INVHARGAGADGET(curInventory, i));
    }
    // save linked list (curprogress + curtodolist)
    fprintf(f, "%d\n", lengthLL(curProgress));
    for (i = 0; i < lengthLL(curProgress); i++){
        pesan = getElmt(curProgress, i);
        fprintf(f, "%d ", TIMEPESANAN(pesan));
        fprintf(f, "%c ", PICKUPPESANAN(pesan));
        fprintf(f, "%c ", DROPOFFPESANAN(pesan));
        fprintf(f, "%c ", TIPEITEM(pesan));
        fprintf(f, "%d\n", PTIME(pesan));
    }
    fprintf(f, "%d\n", lengthLL(curToDoList));
    for (i = 0; i < lengthLL(curToDoList); i++){
        pesan = getElmt(curToDoList, i);
        fprintf(f, "%d ", TIMEPESANAN(pesan));
        fprintf(f, "%c ", PICKUPPESANAN(pesan));
        fprintf(f, "%c ", DROPOFFPESANAN(pesan));
        fprintf(f, "%c ", TIPEITEM(pesan));
        fprintf(f, "%d\n", PTIME(pesan));
    }

    fclose(f);
    // done saving
    printf("...\nYour progress has been saved!\n");
}