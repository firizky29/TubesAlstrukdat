#include <command.h>
#include <global.h>
#include <pesanan.h>
#include <list_linked.h>


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
	ListDin Neighbor;
	printf("Time: %ld\n", curTime);
	if(CHARLOC(curPosition)=='8'){
		printf("You are now in building HQ at point (%d, %d)\n", Absis(COORLOC(curPosition)), Ordinat(COORLOC(curPosition)));
	}
	else{
		printf("You are now in building %c at point (%d, %d)\n", CHARLOC(curPosition), Absis(COORLOC(curPosition)), Ordinat(COORLOC(curPosition)));
	}
	printf("Here are the nearest buildings:\n");
	// disini tambahin bagian ngecek adjacency dari curposition
	// disini display posisi yang dicapai + 0 to cancel
	Neighbor = getNeighbor(curPosition);
	displayBuilding(Neighbor);
	printf("Where do you want to go next?\n(Type the number of desired position or type 0 to cancel)\nEnter number: ");
	int choice = wtoi(inputWord());
	while(choice<0 || choice > length(Neighbor)){
		system("cls");
		system("clear");
		printf("That's an invalid option. Let's retry, shall we?\n");
		if(CHARLOC(curPosition)=='8'){
			printf("You are now in building HQ at point (%d, %d)\n", Absis(COORLOC(curPosition)), Ordinat(COORLOC(curPosition)));
		}
		else{
			printf("You are now in building %c at point (%d, %d)\n", CHARLOC(curPosition), Absis(COORLOC(curPosition)), Ordinat(COORLOC(curPosition)));
		}
		printf("Here are the nearest buildings:\n");
		displayBuilding(Neighbor);
		printf("Where do you want to go next?\n(Type the number of desired position or type 0 to cancel)\nEnter number: ");
		choice = wtoi(inputWord());
	}
	if (choice != 0){
		// TIME HANDLING
		if (speedBoost && countHeavyItem == 0){ // ini kasus punya speedboost & gaada heavy item
			if (countMove < 10){
				if (countMove != 0 && (countMove % 2) == 0){
					curTime += 1;
					DecrementAllPerishableItem(&curProgress, 1);
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
			DecrementAllPerishableItem(&curProgress, 1+countHeavyItem);
		}
		else{ // ini kasus gaada speedboost dan gaada heavy item
			curTime += 1;
			DecrementAllPerishableItem(&curProgress, 1);
		}
		Pesanan val;
		while(!isEmptyQueue(daftarPesanan)&&TIMEPESANAN(HEAD(daftarPesanan))==curTime){
			dequeue(&daftarPesanan, &val);
			insertLastLL(&curToDoList, val);
			if(TIPEITEM(val)=='V'){
				countVIP+=1;
			}
		}
		// Handling perishable item
		Address AdrP = FIRST(curProgress);
		int idx = 0;
		Stack tempBag;
		CreateStack(&tempBag);
		CURCAP(tempBag) = CURCAP(curBag);
		while(AdrP!=NULL){
			pop(&curBag, &val);
			if(TIPEITEM(INFO(AdrP))=='P'&&PTIME(INFO(AdrP))==0){
				deleteAt(&curProgress, idx, &val);
			}
			else{
				push(&tempBag, val);
			}
			idx++;
			AdrP = NEXT(AdrP);
		}
		while(!isStackEmpty(tempBag)){
			pop(&tempBag, &val);
			push(&curBag, val);
		}
		// POSITION HANDLING
		/* move player based on choice
		curPosition = [POSITION_CHOICE] */
		setLoc(&curPosition, ELMT(Neighbor, choice-1));
		printf("You are now in building %c at point (%d, %d)\n", CHARLOC(curPosition), Absis(COORLOC(curPosition)), Ordinat(COORLOC(curPosition)));
		printf("Time: %ld\n", curTime);
	}
}

void Pickup(){
	char curPositionBuilding = CHARLOC(curPosition);
	Pesanan pesanan;

	/* Jika tas tidak penuh */
    if ((!isStackFull(curBag))) { 
		/* Jika ada item di bangunan */
		int idx;
		if(countVIP){
			idx = indexOfVIP(curToDoList, curPositionBuilding);
			if(idx!=IDX_UNDEF){
				deleteAt(&curToDoList, idx, &pesanan);
				insertFirst(&curProgress, pesanan);
				push(&curBag, pesanan);
				printf("VIP Item successfully picked up!\n");
			}
			else{
				printf("Anda harus segera mem-pickup VIP item. Tidak ada VIP item di tempat ini!\n");
			}
		}
		else{
			idx = indexOfPesananBuilding(curToDoList, curPositionBuilding);
			if (idx != IDX_UNDEF){ 
            /* Menghapus item dari curToDoList */
				deleteAt(&curToDoList, idx, &pesanan);
				/* Menambahkan item ke curProgress dan curBag */
				insertFirst(&curProgress, pesanan);
				push(&curBag, pesanan);

				if (TIPEITEM(pesanan) == 'N'){
					printf("Normal Item successfully picked up!\n");
					// Efek item
					// None
				} else if (TIPEITEM(pesanan) == 'H'){
					printf("Heavy Item successfully picked up!\n");
					// Efek item
					countHeavyItem++;
					speedBoost = false;
				} else if (TIPEITEM(pesanan) == 'P'){
					printf("Perishable Item successfully picked up!\n");
					// Efek item
					// Sudah dihandle di MOVE
				}		
				printf("Order destination: %c\n", DROPOFFPESANAN(pesanan));
			}
            else{
				printf("There seems to be no items here... Pickup unsuccessful.\n");
			}
        } 
    } else {
        printf("Bag is full!\n");
    }
}

/* Mengubah curBag, curProgress, cur..*/
void Dropoff(){
	char curPositionBuilding = CHARLOC(curPosition);
	Pesanan pesanan;

	/* Jika tas tidak kosong */
	if (isStackEmpty(curBag) != IDX_UNDEF) {
		/* Jika lokasi dropoff barang paling atas sama dengan posisi Mobita sekarang */
		if (DROPOFFPESANAN(TOP(curBag)) == curPositionBuilding) {
			deleteFirst(&curProgress, &pesanan);
			pop(&curBag, &pesanan);

			if (TIPEITEM(pesanan) == 'N'){
                printf("Order in the form of Normal Item succesfully delivered!\n");
				curMoney += 200;
				printf("You got 200 Yen. Nice.\n");

                // Reward item
            } else if (TIPEITEM(pesanan) == 'H'){
                printf("Order in the form of Heavy Item succesfully delivered!\n");
				curMoney += 400;
				printf("You got 400 Yen. Great job.\n");

				countHeavyItem--;
				countMove = 0;
                // Reward item
				speedBoost = true;
            } else if (TIPEITEM(pesanan) == 'P'){
                printf("Order in the form of Perishable Item succesfully delivered!\n");
				curMoney += 400;
				printf("You got 400 Yen. Good work.\n");

                // Reward item
				capInc(&curBag, 1);
            } else if (TIPEITEM(pesanan) == 'V'){
				printf("Order in the form of VIP Item succesfully delivered!\n");
				curMoney += 600;
				printf("You got 600 Yen. Amazing!\n");

                // Reward item
			}
		} else {
			printf("This is not the drop-off location of the top-most item in your bag!\n");
		}
	} else {
		printf("There are no items to be dropped off from your bag!\n");
	}
}
void displayMap(){
	printf("Here's the Map:\n");
	DisplayMap(curMap);
	printf("(you're the yellow point)\n");
}
void displayToDoList(){
	if (isEmpty(curToDoList)){
		printf("Yay! There is nothing in your To-Do List");
	} else {
		printf("Here's your To-Do List:\n");
		Address p = FIRST(curToDoList);
		for (int i=1; i<=lengthLL(curToDoList); i++){
			printf("%d. %c -> %c ",i,INFO(p).pickup,INFO(p).dropoff);
			if (INFO(p).type == 'N'){
				printf("(Normal Item)\n");
			} else if (INFO(p).type == 'H'){
				printf("(Heavy Item)\n");
			} else if (INFO(p).type == 'P'){
				printf("(Perishable Item)\n");
			} else if (INFO(p).type == 'V'){
				printf("(VIP Item)\n");
			}
			p = NEXT(p);		
		}
	}
}
void displayInProgress(){
    // ngeprint dari awal-akhir
    // berarti kalo PICK_UP lebih gampang insertFirst ke LinkedList, 
    // trus kalo DROP_OFF deleteLast
	if (isEmpty(curProgress)){
		printf("Yay! There is no order in progress");
	} else {
		if (lengthLL(curProgress) == 1){
			printf("Here is the order that you're currently delivering:\n");
		} else {
			printf("Here are your on-going orders:\n");			
		}
		Address p = FIRST(curProgress);
		for (int i=1; i<=lengthLL(curProgress); i++){

			if (INFO(p).type == 'N'){
				printf("%d. Normal Item (Destination: %c)\n",i,INFO(p).dropoff);
			} else if (INFO(p).type == 'H'){
				printf("%d. Heavy Item (Destination: %c)\n",i,INFO(p).dropoff);
			} else if (INFO(p).type == 'P'){
				printf("%d. Perishable Item (Destination: %c)\n",i,INFO(p).dropoff);
			} else {
				printf("%d. VIP Item (Destination: %c)\n",i,INFO(p).dropoff);
			}
			p = NEXT(p);
		}    		
	}
}
void Buy(){
	if (IsHQ(curPosition)){
		printf("Current money: %ld Yen\n", curMoney);
		printf("Check out these gadgets...!\n");
		printf("1. Kain Pembungkus Waktu (800 Yen)\n");
		printf("2. Senter Pembesar (1200 Yen)\n");
		printf("3. Pintu Kemana Saja (1500 Yen)\n");
		printf("4. Mesin Waktu (3000 Yen)\n");
		printf("Which gadget would you like to buy?\n(Type the number of desired gadget or type 0 to cancel)\nEnter number: ");
		int choice = wtoi(inputWord());
		while(choice<0||choice>4){
			system("cls");
			system("clear");
			printf("The gadget you selected is not available.\n");
			printf("Current money: %ld Yen\n", curMoney);
			printf("Select one of these gadget...\n");
			printf("1. Kain Pembungkus Waktu (800 Yen)\n");
			printf("2. Senter Pembesar (1200 Yen)\n");
			printf("3. Pintu Kemana Saja (1500 Yen)\n");
			printf("4. Mesin Waktu (3000 Yen)\n");
			printf("Which gadget would you like to buy?\n(Type the number of desired gadget or type 0 to cancel)\nEnter number: ");
			choice = wtoi(inputWord());
		}
		if(choice == 1){
			if (curMoney >= 800){
				// isi bagian ini sama proses beli gadgetnya
				curMoney -= 800;
				printf("Gadget successfully bought!\n");
				printf("Current money: %ld Yen\n", curMoney);
			}
			else{
				printf("Oops... Seems like you don't have enough money!\n");
			}
		}
		else if(choice == 2){
			if (curMoney >= 1200){
				// isi bagian ini sama proses beli gadgetnya
				curMoney -= 1200;
				printf("Gadget successfully bought!\n");
				printf("Current money: %ld Yen\n", curMoney);
			}
			else{
				printf("Oops... Seems like you don't have enough money!\n");
			}
		}
		else if(choice == 3){
			if (curMoney >= 1500){
				// isi bagian ini sama proses beli gadgetnya
				curMoney -= 1500;
				printf("Gadget successfully bought!\n");
				printf("Current money: %ld Yen\n", curMoney);
			}
			else{
				printf("Oops... Seems like you don't have enough money!\n");
			}
		}
		else if(choice == 4){
			if (curMoney >= 3000){
				// isi bagian ini sama proses beli gadgetnya
				curMoney -= 3000;
				printf("Gadget successfully bought!\n");
				printf("Current money: %ld Yen\n", curMoney);
			}
			else{
				printf("Oops... Seems like you don't have enough money!\n");
			}
		}
		else{
			printf("\nCancelling...\n");
		}
	}
	else{
		printf("You can only buy when you're in HQ.\n");
	}
}
void displayInventory(){
	printf("Here's your inventory:\n");
	displayGadgetinInventory(curInventory);
	printf("Which gadget would you like to use?\n(Type the number of desired gadget or type 0 to cancel)\nEnter number: ");
	int choice = wtoi(inputWord());
	boolean flag = true;
	while (flag){
		if (choice >= 1 && choice <= INVENTORY_CAP){
			if (INVIDGADGET(curInventory, choice-1) != IDGADGET_UNDEF){
				Gadget g;
				deleteGadget(&curInventory,choice-1,&g);
				// isi juga sama aktivasi efek dari gadget
				if(IDGADGET(g) == 1){
					if (TIPEITEM(TOP(curBag)) == 'P'){
						PTIME(INFO(fSearch(curToDoList, TOP(curBag)))) = PTIME(TOP(curBag));
					}
				}else if(IDGADGET(g) == 2){
					capMultiplier(&curBag, 2);
				}else if(IDGADGET(g) == 3){
					displayMap();
					printf("Where do you want to go next? : ");
					// char loc = (inputWord()).contents;
					// setLoc(&curPosition, ELMT(LocList, indexOfCharLoc(LocList, loc)));
				}else if(IDGADGET(g) == 4){
					if(curTime <= 50){
						curTime = 0;
					}else{
						curTime -= 50;
					}
				}else if(IDGADGET(g) == 5){
					//Belum
					if (TIPEITEM(TOP(curBag)) == 'H'){
						countHeavyItem -= 1;
					}
				}else{
					printf("Gadget is unavailable\n");
					return;
				}
				printf("Gadget successfully used!\n");
			}
			else{
				printf("Unable to use gadget\n");
			}
			flag = false;
		}else if(choice == 0){
			flag = false;
		}else{
			int choice = wtoi(inputWord());
		}
	}
}
void displayHelp(){
	printf("-  MOVE: move to next location\n");
	printf("-  PICK_UP: pickup item in current location\n");
	printf("-  DROP_OFF: deliver top-most item to current location\n");
	printf("-  MAP: display map\n");
	printf("-  TO_DO: display list of to-do order(s)\n");
	printf("-  IN_PROGRESS: display list of in-progress order(s)\n");
	printf("-  BUY: purchase gadgets (only available when in HQ)\n");
	printf("-  INVENTORY: display list of inventory\n");
	printf("-  RETURN: return top-most item in bag to its pick-up location\n");
	printf("-  HELP: display list of available command(s)\n");
	printf("-  EXIT: exit game\n");
	printf("-  SAVE: save current progress\n");
}
void Retur(){
	printf("Retur\n");
}

void Exit(){
	// bisa save before exit atau nggak
	printf("Are you sure want to quit the game (yes/no)? : ");
	Word YayOrNay = inputWord();
	if(YayOrNay.contents[0]=='y'||YayOrNay.contents[0]=='Y'){
		// prosedur save kalau jadi ada
		system("clear");
		system("cls");
		printf("Quitting...\n\nSAYOOONARAAAAAAAAAA!");
		exit(0);
	}
	else if(YayOrNay.contents[0]=='n'||YayOrNay.contents[0]=='N'){
		printf("Continuing...\n");
	}
	else{
		printf("Assumed to continue...\n");
	}
}
