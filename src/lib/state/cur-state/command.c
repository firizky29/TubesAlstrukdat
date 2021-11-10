#include "command.h"
#include "../../component/global.h"


/* CHECK COMMAND VALIDITY */
boolean isNewGame(Word kata){
/* return true if kata is NEW_GAME and false if not */
	Word cmd_newgame = {"NEW_GAME", 8};
	return isWordEqual(kata, cmd_newgame);
}

boolean isExit(Word kata){
/* return true if kata is EXIT and false if not */
	Word cmd_exit = {"EXIT", 4};
	return isWordEqual(kata, cmd_exit);
}

boolean isLoadGame(Word kata){
/* return true if kata is LOAD_GAME and false if not */
	Word cmd_loadgame = {"LOAD_GAME", 9};
	return isWordEqual(kata, cmd_loadgame);
}

boolean isMove(Word kata){
/* return true if kata is MOVE and false if not */
	Word cmd_move = {"MOVE", 4};
	return isWordEqual(kata, cmd_move);
}

boolean isPickUp(Word kata){
/* return true if kata is PICK_UP and false if not */
	Word cmd_pickup = {"PICK_UP", 7};
	return isWordEqual(kata, cmd_pickup);
}

boolean isDropOff(Word kata){
/* return true if kata is DROP_OFF and false if not */
	Word cmd_dropoff = {"DROP_OFF", 8};
	return isWordEqual(kata, cmd_dropoff);
}

boolean isMap(Word kata){
/* return true if kata is MAP and false if not */
	Word cmd_map = {"MAP", 3};
	return isWordEqual(kata, cmd_map);
}

boolean isToDo(Word kata){
/* return true if kata is TO_DO and false if not */
	Word cmd_todo = {"TO_DO", 5};
	return isWordEqual(kata, cmd_todo);
}

boolean isInProgress(Word kata){
/* return true if kata is IN_PROGRESS and false if not */
	Word cmd_inprogress = {"IN_PROGRESS", 11};
	return isWordEqual(kata, cmd_inprogress);
}

boolean isBuy(Word kata){
/* return true if kata is BUY and false if not */
	Word cmd_buy = {"BUY", 3};
	return isWordEqual(kata, cmd_buy);
}

boolean isInventory(Word kata){
/* return true if kata is INVENTORY and false if not */
	Word cmd_inventory = {"INVENTORY", 9};
	return isWordEqual(kata, cmd_inventory);
}

boolean isHelp(Word kata){
/* return true if kata is HELP and false if not */
	Word cmd_help = {"HELP", 4};
	return isWordEqual(kata, cmd_help);
}

boolean isSaveGame(Word kata){
/* return true if kata is SAVE_GAME and false if not */
	Word cmd_savegame = {"SAVE_GAME", 9};
	return isWordEqual(kata, cmd_savegame);
}

boolean isReturn(Word kata){
/* return true if kata is RETURN and false if not */
	Word cmd_return = {"RETURN", 6};
	return isWordEqual(kata, cmd_return);
}

/* Mengubah curPosition, curTime*/
void Move(){
	printf("Here are the nearest buildings:\n");
	// disini tambahin bagian ngecek adjacency dari curposition
	// disini display posisi yang dicapai + 0 to cancel
	printf("Where do you want to go next?\n(Type the number of desired position or type 0 to cancel)\nEnter number: ");
	int choice = wtoi(inputWord());
	if (choice != 0){
		// TIME HANDLING
		if (speedBoost && countHeavyItem == 0){ // ini kasus punya speedboost & gaada heavy item
			if (countMove < 10){
				if (countMove != 0 && (countMove % 2) == 0){
					curTime += 1;
				}
			}
			else{
				speedBoost = false;
				countMove = 0;
			}
		}
		else if (countHeavyItem > 0){ // ini kasus ada heavy item
			if (speedBoost){ // kalo sblmnya ada speedboost, dideactivate + reinitialize
				speedBoost = false;
				countMove = 0;
			}
			curTime += 1 + countHeavyItem;
		}
		else{ // ini kasus gaada speedboost dan gaada heavy item
			curTime += 1;
		}

		// POSITION HANDLING
		/* move player based on choice
		curPosition = [POSITION_CHOICE] */

		printf("You are now in point (%d, %d)", curPosition.X, curPosition.Y);
		printf("Time: %ld", curTime);
	}
}

void Pickup(){
	// CASE 1: ITEM IS AVAILABLE FOR PICKUP
	/*if ([ada item di cur position]){
		printf("Pickup of [isi type item] successful!\n");
		(isi bagian ini sama proses pengambilan pesanan)
		(Aktifkan efek-efeknya bila bukan Normal Item) -> punya Ghebyon
		printf("Item destination: [isi destinasi drop off] \n");
	}

	// CASE 2: NO AVAILABLE ITEM FOR PICKUP
	else{
		printf("There seems to be no items here... Pickup unsuccessful.\n");
	}*/
	printf("sori masih dalam bentuk komen kl mo edit+tes uncomment aja\n");
}

/* Mengubah curBag, curProgress, cur..*/
void Dropoff(){
	// CASE 1: ITEM IS AVAILABLE FOR DROP OFF
	/*if ([ada item yg sabi di drop off]){
		printf("[isi type item] successfully dropped off!\n");
		(isi bagian ini sama proses drop off)
		printf("You gained: %d Yen", [isi harga dari type item]\n");

		// AKTIVASI ABILITY
		if (type item == heavy item){
			speedBoost == true;
		}
		else if (type item == perishable item){
			increase capacity + 1 buat bawa item (max 100)
		}
	}

	// CASE 2: NO AVAILABLE ITEM FOR DROP OFF
	else{
		printf("There's nothing to drop off here.\n");
	}*/
	printf("sori masih dalam bentuk komen kl mo edit+tes uncomment aja\n");
}
void displayMap(){
	printf("Here's the Map:\n");
	DisplayMap(curMap);
	printf("(current position = yellow point)\n");
}
void displayToDoList(){
	printf("Here's your to-do list:\n");
	// isi bagian ini sama display to-do list
}
void displayInProgress(){
	printf("Order(s) in-progress:\n");
	// isi bagian ini sama display in progress
}
void Buy(){
	/*if (curPosition lagi di point hq){
		printf("Current money: %ld Yen\n", curMoney);
		printf("Check out these gadgets...!\n");
		printf("1. Kain Pembungkus Waktu (800 Yen)")
		printf("2. Senter Pembesar (1200 Yen)")
		printf("3. Pintu Kemana Saja (1500 Yen)")
		printf("4. Mesin Waktu (3000 Yen)")
		printf("Which gadget would you like to buy?\n(Type the number of desired gadget or type 0 to cancel)\nEnter number: ");
		int choice = wtoi(inputWord());
		if (curMoney >= harga gadgetnya){
			// isi bagian ini sama proses beli gadgetnya
			curMoney -= harga gadget
			printf("Gadget successfully bought!\n");
			printf("Current money: %ld Yen\n", curMoney);
		}
		else{
			printf("Oops... Seems like you don't have enough money!\n");
		}
	}
	else{
		printf("You can only buy when you're in HQ.\n");
	}*/
	printf("sori masih dalam bentuk komen kl mo edit+tes uncomment aja\n");
}
void displayInventory(){
	printf("Here's your inventory:\n");
	displayGadgetinInventory(curInventory);
	printf("Which gadget would you like to use?\n(Type the number of desired gadget or type 0 to cancel)\nEnter number: ");
	int choice = wtoi(inputWord());
	if (choice != 0){
		if (INVIDGADGET(&curInventory, choice-1) != IDGADGET_UNDEF){
			Gadget g;
			// isi bagian ini sama proses penghilangan gadget dari inventory
			deleteGadget(&curInventory,choice-1,g);
			// isi juga sama aktivasi efek dari gadget
			// Cek kalau masih salah
			if(IDGADGET(g) == 1){
				Stack tempBag;
				int i = 0
				flag = true;
				Pesanan val;
				
				while(i != IDX_UNDEF && flag){
					if(TIPEITEM(TOP(curBag)) == 'P'){
						PTIME(TOP(curBag)) = FIRSTPITEM(TIO(curBag));
					}else{
						pop(&curBag, &val);
						push(&tempBag, val);
					}
				}
				while(!isStackEmpty(tempBag)){
					Pesanan val2;
					pop(&tempBag, &val);
					push(&curBag, val);
				}
			}else if(IDGADGET(g) == 2){
				if(CURCAP(curBag)*2 >= STACK_CAP){
					CURCAP(curBag) = STACK_CAP;
				}else{
					CURCAP(curBag) *= 2;
				}
			}else if(IDGADGET(g) == 3){
				printf("Where do you want to go next? : ");
				//menampilkan map atau menampilkan posisi dalam bentuk point?
				char loc = wtoi(inputWord()); //eh ini gimana masukkan ke dalam "kata" nya?
				//curPosition = [POSITION_CHOICE];
			}else if(IDGADGET(g) == 4){
				if(curTime <= 50){
					curTime = 0;
				}else{
					curTime -= 50;
				}
			}
			}else if(IDGADGET(g) == 5){
				//Diskusi sama yang ngerjakan MOVE
			}
			printf("Gadget successfully used!\n");
		}
		else{
			printf("Unable to use gadget!");
		}
	}
}
void displayHelp(){
	printf("1. MOVE: move to next location\n");
	printf("2. PICK_UP: pickup item in current location\n");
	printf("3. DROP_OFF: deliver top-most item to current location\n");
	printf("4. MAP: display map\n");
	printf("5. TO_DO: display list of to-do order(s)\n");
	printf("6. IN_PROGRESS: display list of in-progress order(s)\n");
	printf("7. BUY: purchase gadgets (only available when in HQ)\n");
	printf("8. INVENTORY: display list of inventory\n");
	printf("9. HELP: display list of available command(s)\n");
}
void Retur(){
	printf("Retur\n");
}
