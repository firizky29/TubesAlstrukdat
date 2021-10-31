#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

/* Word Engine State */
boolean endWord;
Word currentWord;

void ignoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar != BLANK atau currentChar = MARK */
	while (currentChar == BLANK){
		adv();
	}
}

void startWord_file(char *filename){
/* start word tp input dr file, mark masih '.' */
	start_file(filename);
	ignoreBlank();
	if (currentChar == MARK){
		endWord = true;
	}
	else{
		copyWord();
		endWord = false;
	}
}

void startWord_command(){
/* start word tp input dr cmd, mark masih '.' 
   I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
	start_command();
	ignoreBlank();
	if (currentChar == MARK){
		endWord = true;
	}
	else{
		copyWord();
		endWord = false;
	}
}

void advWord(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
	ignoreBlank();
	if (currentChar == MARK){
		endWord = true;
	}
	else{
		copyWord();
		ignoreBlank();
	}
}

void copyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
	int i = 0;
	while (currentChar != MARK && currentChar != BLANK){
		currentWord.contents[i] = currentChar;
		i++;
		adv();
	}
	if (i > CAPACITY){
		currentWord.length = CAPACITY;
	}
	else{
		currentWord.length = i;
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

void printWord(Word kata){
/* print kata */
	int i;
	for (i = 0; i < kata.length; i++){
		printf("%c", kata.contents[i]);
	}
}

