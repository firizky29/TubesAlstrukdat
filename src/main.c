#include <stdio.h>
#include <stdlib.h>

#include "lib/data-structure/list-dinamis/listdin.h"
#include "lib/data-structure/matriks/matrix.h"
#include "lib/data-structure/point/point.h"
#include "lib/tools/mesin-karakter/charmachine.h"
#include "lib/boolean.h"
#include "lib/tools/mesin-kata/wordmachine.h"

/* SIMULASI MAIN MENU + BACA CONFIG
dari tahap main menu sampe get info dari config 
baru sampe get map matrix, matrix adjacency, sama point lokasi2 */

int main(){
    // main menu
	printf("Type one of the following:\n1. NEW_GAME\n2. EXIT\nEnter your choice: ");
	Word choice = inputWord();
	while (!isNewGame(choice) && !isExit(choice)){
		printf("Stop joking around, that's an invalid command. Try again: ");
		choice = inputWord();
	}
    // NEW_GAME (start new game)
	if (isNewGame(choice)){
		printf("Enter configuration file level ([filename].txt): ");
		Word filename = inputWord();
		while (!fopen(filename.contents, "r")){
			printf("File not found, enter filename again: ");
			filename = inputWord();
		}
		printf("Opening ");
		printWord(filename);
		printf("\n");
        
        // reading file config + get info
		readFile(filename);
        Matrix map = getMap();
        POINT hq = getPoint();
        ListDin loc = getLoc(hq);
        Matrix adj = getAdjacency(loc.capacity);
        // display info
        printf("\nHQ berada pada (x,y): (%f, %f)\n\n", hq.X, hq.Y);
        printf("Map: %d x %d\n", map.rowEff, map.colEff);
        displayMatrix(map);
        printf("\n\n");
        displayMatrix(adj);
        printf("\n\n");
        displayList(loc);
        printf("\n\n");
        // sisanya di print dulu aja karena nunggu ADTnya ada dulu
        while(!endFile){
            printWordFile(currentWord);
        }
        fclose(tape);
	}
    // exit game
	else{
		printf("Exiting program...\nSee you later!");
		exit(0);
	}
}