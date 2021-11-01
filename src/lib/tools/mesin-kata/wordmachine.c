#include <stdio.h>
#include <stdlib.h>

#include "../../data-structure/list-dinamis/listdin.h"
#include "../../data-structure/matriks/matrix.h"
#include "../../data-structure/point/point.h"
#include "../mesin-karakter/charmachine.h"
#include "../../boolean.h"

/* Word Engine State */
boolean endWord;
Word currentWord;

/* PRIMITIVE FUNCTIONS (File & CMD) */
void ignoreBlank(){
/* self describing function */
	while (currentChar == BLANK){
		adv();
	}
}

void copyWord_file(){
/* copy word buat input dari file */
	int i = 0;
	while (currentChar != BLANK && !endFile){
		currentWord.contents[i] = currentChar;
		i++;
		adv();
	}
	if (i > MAXWORD){
		currentWord.length = MAXWORD;
	}
	else{
		currentWord.length = i;
	}
}

void copyWord_command(){
/* copy word buat input dari command */
	int i = 0;
	while (currentChar != MARK && currentChar != BLANK){
		currentWord.contents[i] = currentChar;
		i++;
		adv_command();
	}
	if (i > MAXWORD){
		currentWord.length = MAXWORD;
	}
	else{
		currentWord.length = i;
	}
}

void startWord_file(char *filename){
/* start word buat input dari file, marknya EOF */
	endFile = false;
	start_file(filename);
	ignoreBlank();
	copyWord_file();
}

void startWord_command(){
/* start word buat input dari command, marknya newline */
	start_command();
	ignoreBlank();
	if (currentChar == MARK){
		endWord = true;
	}
	else{
		copyWord_command();
		endWord = false;
	}
}

void advWord_file(){
/* advance ke word berikutnya buat input file */
	if (currentWord.length != 0){
		memset (currentWord.contents, 0, strlen(currentWord.contents));
	}
	ignoreBlank();
	copyWord_file();
}

void advWord_command(){
/* advance ke word berikutnya buat input file */
	if (currentWord.length != 0){
		memset (currentWord.contents, 0, strlen(currentWord.contents));
	}
	ignoreBlank();
	if (currentChar == MARK){
		endWord = true;
	}
	else{
		copyWord_file();
		ignoreBlank();
	}
}

boolean isWordEqual(Word kata1, Word kata2){
/* bandingin dua kata */
	if (kata1.length != kata2.length){
		return false;
	}
	else{
		int i;
		for (i = 0; i < kata1.length; i++){
			if (kata1.contents[i] != kata2.contents[i]){
				return false;
			}
		}
		return true;
	}
}

/* READ INPUT & PRINT OUTPUT (File & CMD) */
Word inputWord(){
/* menerima input dan direturnd dalam bentuk word */
	startWord_command();
	Word input = currentWord;
	return input;
}

void readFile(Word filename){
/* membaca file dengan nama filename */
	startWord_file(filename.contents);
}

void printWordFile(Word kata){ 
/* print kata dari suatu file */
	printWord(kata);
	printf("%c", BLANK);
	advWord_file();
}

void printWord(Word kata){
/* print kata */
	int i;
	for (i=0; i < kata.length; i++){ 
		printf("%c", kata.contents[i]); 
	}
}

/* CONVERT WORD */
int wtoi(Word kata){
/* convert word to integer */
	int x = atoi(kata.contents);
    advWord_file();
	return x;
}

Matrix getMap(){
/* get n x m from config and return n x m matrix */
	int n, m;
	n = wtoi(currentWord);
	m = wtoi(currentWord);
	Matrix map;
	CreateMatrix(n, m, &map);
	return map;
}

POINT getPoint(){
/* get and return point from config */
	int x, y;
	x = wtoi(currentWord);
	y = wtoi(currentWord);
	POINT hq = MakePOINT(x, y);
	return hq;
}

Matrix getAdjacency(int n){
/* get and return adjacency matrix from config */
	int temp, i, j;
	Matrix adjacency;
	CreateMatrix(n, n, &adjacency);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			temp = wtoi(currentWord);
			ELMT(adjacency, i, j) = temp;
		}
	}
	return adjacency;
}

ListDin getLoc(POINT pointhq){
/* get char and coord of loc and return list dinamis */
	int i;
	ListDin loc;
	int num = wtoi(currentWord);
	CreateListDin(&loc, (num+1));
	CHARLOC(loc, 0) = '8';
	COORLOC(loc, 0) = pointhq;
	for (i = 1; i < (num + 1); i++){
		CHARLOC(loc, i) = currentWord.contents[0];
		advWord_file();
		COORLOC(loc, i) = getPoint();
	}
	NEFF(loc) = loc.capacity;
	return loc;
}


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