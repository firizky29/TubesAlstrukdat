#include <savestate.h>
#include <initstate.h>
#include <loadstate.h>
#include <stdio.h>
#include <stdlib.h>

void save(){
    char* saveDir = "data/saved-file/";
	printf("Save file as (filename): \n");
	Word file = inputWord();
    Word path;
    strcpy(path.contents, saveDir);
    strcat(path.contents, file.contents);
    strcat(path.contents, ".txt");
    path.length = 31+file.length;
	FILE *f = fopen(path.contents, "w");
	if (f == NULL)
	{
		printf("Oops! Error saving file\n");
		exit(1);
	}
    // ini nanti kalo bisa diapus
	emptyWord();
    char* newGameDir = "data/original-config-file/";
    //printf("Enter configuration file level ([filename]): ");
    //Word filename = inputWord();

    // write config file --> extract map, matrix adj, loc list, pesanan
    printf("Saving ");
    printWord(file);
    printf("....\n");

    fprintf(f, "%s\n", configName.contents);
    // write current progress --> extract non-adt progress
    fprintf(f, "%ld\n", curMoney);
    fprintf(f, "%ld\n", curTime);
    fprintf(f, "%d\n", curSpeed);
    fprintf(f, "%d\n", countHeavyItem);
    fprintf(f, "%d\n", countMove);
    // speedboost (1 atau 0 --> on atau off)

    // write current progress --> extract adt progress
    fprintf(f, "%c %d %d\n", CHARLOC(curPosition), Absis(COORLOC(curPosition)), Ordinat(COORLOC(curPosition)));
    fclose(f);

    printf("...\nYour progress has been saved!\n");

/*
Stack curBag;
Inventory curInventory;
LinkedList curProgress;
LinkedList curToDoList;
ListDin LocList;

    fclose(tape);
*/
}

void saveLoad(){

}