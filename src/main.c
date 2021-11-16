#include <stdio.h>
#include <stdlib.h>
#include <initstate.h>
#include <savestate.h>
#include <loadstate.h>
#include <command.h>
#include <boolean.h>

/* SIMULASI MAIN MENU + BACA CONFIG
dari tahap main menu sampe get info dari config 
baru sampe get map matrix, matrix adjacency, sama point lokasi2 */

int main(){
    // main menu
    Word state, choice;
	printf("Type one of the following:\n- NEW_GAME\n- LOAD_GAME\n- EXIT\nEnter your choice: ");
	state = inputWord();
	while ((!isNewGame(state) && !isExit(state) && !isLoadGame(state)) || (isLoadGame(state) && !isLoadAvailable())){
        if (isLoadGame(state) && !isLoadAvailable()){
            printf("No saved files. Couldn't load anything.\nTry again: ");
        }
        else{
		    printf("Stop joking around, that's an invalid command. \nTry again: ");
        }
		state = inputWord();
	}
    if (isExit(state)){
    	printf("Exiting program...\nSee you later!");
		exit(0);
    }
	else{
        if (isNewGame(state)){
            globalinit();
        }
        else{
            load();
        }
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
            else if(isSaveGame(choice)){
                save();
            }
            else{
                printf("Your command is not recognized. Input one of these following command: \n");
                displayHelp();
            }
            if(isEmptyQueue(daftarPesanan)&&isEmpty(curToDoList)&&isEmpty(curProgress)){
                printf("Selamat Anda berhasil menyelesaikan game ini!");
            }
        }
	}
}