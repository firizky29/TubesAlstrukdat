#include <stdio.h>
#include "wordmachine.h"

/* Word Engine State */
boolean endWord;
Word currentWord;

void ignoreBlank_file(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar != BLANK atau currentChar = EOF */
	while (currentChar == BLANK){
		adv_file();
	}
}

void ignoreBlank_command(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar != BLANK atau currentChar = MARK */
	while (currentChar == BLANK){
		adv_command();
	}
}

void startWord_file(char *filename){
/* 
   I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = EOF; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
	start_file(filename);
	ignoreBlank_file();
	if (currentChar == EOF){
		endWord = true;
	}
	else{
		copyWord_file();
		endWord = false;
	}
}

void startWord_command(){
/* 
   I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
	start_command();
	ignoreBlank_command();
	if (currentChar == MARK){
		endWord = true;
	}
	else{
		copyWord_command();
		endWord = false;
	}
}

void advWord_command(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
	ignoreBlank_command();
	if (currentChar == MARK){
		endWord = true;
	}
	else{
		copyWord_command();
		ignoreBlank_command();
	}
}

void advWord_file(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin EOF
          Jika currentChar = EOF, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
	ignoreBlank_file();
	if (currentChar == EOF){
		endWord = true;
	}
	else{
		copyWord_file();
		ignoreBlank_file();
	}
}


void copyWord_command(){
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
		adv_command();
	}
	if (i > CAPACITY){
		currentWord.length = CAPACITY;
	}
	else{
		currentWord.length = i;
	}
}

void copyWord_file(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = EOF; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
	int i = 0;
	while (currentChar != BLANK && currentChar != EOF){
		currentWord.contents[i] = currentChar;
		i++;
		adv_file();
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

