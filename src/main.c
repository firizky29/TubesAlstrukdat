#include <stdio.h>
#include <stdlib.h>

#include "lib/state/init/initstate.h"
#include "lib/state/cur-state/command.h"
#include "lib/boolean.h"

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

		globalinit();
        while(true){
            printf("\n>> ");
            choice = inputWord();
            if(isMove(choice)){
                Move();
            }
            else if(isPickUp(choice)){
                Pickup();
            }
            else if(isDropOff(choice)){
                Dropoff();
            }
            else if(isInProgress(choice)){
                displayInProgress();
            }
            else if(isToDo(choice)){
                displayToDoList();
            }
            else if(isMap(choice)){
                displayMap();
            }
            else if(isInventory(choice)){
                displayInventory();
            }
            else if(isBuy(choice)){
                Buy();
            }
            else if(isHelp(choice)){
                displayHelp();
            }
            else if(isReturn(choice)){
                Retur();
            }
            else if(isExit(choice)){
                Exit();
            }
            else{
                printf("Your command is not recognized. Input one of these following command: \n");
                displayHelp();
            }
        }
	}
    // exit game
	else{
		printf("Exiting program...\nSee you later!");
		exit(0);
	}
}