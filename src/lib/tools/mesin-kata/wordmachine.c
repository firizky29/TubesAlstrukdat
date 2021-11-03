#include <stdio.h>
#include <stdlib.h>

#include "wordmachine.h"

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


