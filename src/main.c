#include <stdio.h>
#include <stdlib.h>
#include <initstate.h>
#include <savestate.h>
#include <loadstate.h>
#include <command.h>
#include <boolean.h>
#include <pcolor.h>


int main(){
    // main menu
    Word state, choice;
	printf("Type one of the following:\n- NEW_GAME\n- LOAD_GAME\n- EXIT\nEnter your choice: ");
	state = inputWord();
	while ((!isNewGame(state) && !isExit(state) && !isLoadGame(state)) || (isLoadGame(state) && !isLoadAvailable())){
        if (isLoadGame(state) && !isLoadAvailable()){
            print_red("No saved files. Couldn't load anything.\nTry again: ");
        }
        else{
		    print_red("Stop joking around, that's an invalid command. \nTry again: ");
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
        boolean warn = false;
        while(true){
            if(isEmptyQueue(daftarPesanan)&&isEmpty(curToDoList)&&isEmpty(curProgress)){
                if(!warn){
                    system("cls");
                    printf("Seems like there are no orders left for you to deliver. Nice work today.\n\nHead back to");
                    print_yellow(" HQ ");
                    printf("immediately to end the day and get your reward!\n\n");
                    warn = true;
                }
                if(IsHQ(curPosition)){
                    system("cls");
                    print_green("Congratulations, You've finished the game!!!! YAYYYYYYY!!!!!!!!!!!!!\n");
                    printf("============================================================================\n");
                    print_magenta("ACHIEVEMENT\n");
                    print_yellow("Total Delivered Items\t: ");
                    printf("%d\n", countDelivered);
                    print_yellow("Time elapsed\t\t: ");
                    printf("%ld\n", curTime);
                    print_yellow("Earned money\t\t: ");
                    printf("%ld\n", curMoney);

                    break;
                }
            }
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
                print_red("Your command is not recognized. Input one of these following command: \n");
                displayHelp();
            }
        }
	}
}