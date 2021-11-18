#include <savestate.h>
#include <initstate.h>
#include <loadstate.h>
#include <stdio.h>
#include <stdlib.h>
#include <pcolor.h>
#include <unistd.h>

/* get reversed stack */
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

/* save current progress */
void save(){
    char* saveDir = "data/saved-file/";
	printf("Save file as (filename): \n");
	Word file = inputWord();
    Word path;
    strcpy(path.contents, saveDir);
    strcat(path.contents, file.contents);
    strcat(path.contents, ".txt");
    path.length = 21+file.length;
    // check if file already exists (overwrite or not)
    if (access(path.contents, F_OK) == 0){
        printf("File already exists.\nWould you like to overwrite changes (yes/no)? : ");
        Word overWrite = inputWord();
        if (overWrite.contents[0] != 'y' && overWrite.contents[0] != 'Y'){
            printf("Save cancelled.\n");
            return;
        }
    }
	FILE *f = fopen(path.contents, "w");
	if (f == NULL)
	{
		print_green("Oops! Error saving file\n");
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
    // save built-in progress
    fprintf(f, "%ld\n", curTime);
    fprintf(f, "%ld\n", curMoney);
    fprintf(f, "%d\n", curSpeed);
    fprintf(f, "%d\n", speedBoost);
    fprintf(f, "%d\n", countMove);
    fprintf(f, "%d\n", countVIP);
    fprintf(f, "%d\n",countReturn);
    fprintf(f, "%d\n", countDelivered);
    int i;
    Pesanan pesan;
    LinkedList rStack;
    // save stack progress (curbag)
    fprintf(f, "%d\n", CURCAP(curBag));
    rStack = reverseStack(&curBag);
    fprintf(f, "%d\n", lengthLL(rStack));
    for (i = 0; i < lengthLL(rStack); i++){
        pesan = getElmt(rStack, i);
        fprintf(f, "%d ", TIMEPESANAN(pesan));
        fprintf(f, "%c ", PICKUPPESANAN(pesan));
        fprintf(f, "%c ", DROPOFFPESANAN(pesan));
        fprintf(f, "%c ", TIPEITEM(pesan));
        fprintf(f, "%d ", PTIME(pesan));
        fprintf(f, "%d\n", WEIGHT(pesan));
    }
    // save inventory progress (curInventory)
    fprintf(f, "%d\n", INVENTORY_CAP);
    for (i = 0; i < INVENTORY_CAP; i++){
        fprintf(f, "%d ", INVIDGADGET(curInventory, i));
        fprintf(f, "%d\n", INVHARGAGADGET(curInventory, i));
    }
    // save curprogress progress (linked list)
    fprintf(f, "%d\n", lengthLL(curProgress));
    for (i = 0; i < lengthLL(curProgress); i++){
        pesan = getElmt(curProgress, i);
        fprintf(f, "%d ", TIMEPESANAN(pesan));
        fprintf(f, "%c ", PICKUPPESANAN(pesan));
        fprintf(f, "%c ", DROPOFFPESANAN(pesan));
        fprintf(f, "%c ", TIPEITEM(pesan));
        fprintf(f, "%d ", PTIME(pesan));
        fprintf(f, "%d\n", WEIGHT(pesan));
    }
    // save curtodolist progress (linked list)
    fprintf(f, "%d\n", lengthLL(curToDoList));
    for (i = 0; i < lengthLL(curToDoList); i++){
        pesan = getElmt(curToDoList, i);
        fprintf(f, "%d ", TIMEPESANAN(pesan));
        fprintf(f, "%c ", PICKUPPESANAN(pesan));
        fprintf(f, "%c ", DROPOFFPESANAN(pesan));
        fprintf(f, "%c ", TIPEITEM(pesan));
        fprintf(f, "%d ", PTIME(pesan));
        fprintf(f, "%d\n", WEIGHT(pesan));
    }
    // save daftar pesanan (queue)
    fprintf(f, "%d\n", lengthQueue(daftarPesanan));
    displayQueue(daftarPesanan);
    for (i = IDX_HEAD(daftarPesanan); i <= IDX_TAIL(daftarPesanan); i++){
        pesan = daftarPesanan.buffer[i];
        fprintf(f, "%d ", TIMEPESANAN(pesan));
        fprintf(f, "%c ", PICKUPPESANAN(pesan));
        fprintf(f, "%c ", DROPOFFPESANAN(pesan));
        fprintf(f, "%c ", TIPEITEM(pesan));
        fprintf(f, "%d ", PTIME(pesan));
        fprintf(f, "%d\n", WEIGHT(pesan));
    }
    fclose(f);
    print_green("...\nYour progress has been saved!\n");
}