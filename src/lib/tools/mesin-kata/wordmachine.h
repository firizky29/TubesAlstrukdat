#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include "boolean.h"
#include "../mesin-karakter/charmachine.h"
#include "../file-reader/filecharmachine.h"

#define CAPACITY 50
#define BLANK ' '

typedef struct {
   char contents[CAPACITY]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Word;

/* Word Engine State */
extern boolean endWord;
extern Word currentWord;

void ignoreBlank_command();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = MARK */
   
void ignoreBlank_file();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = EOF */

void startWord_file(char *filename);
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void startWord_command();
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWord_command();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void advWord_file();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = EOF, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord_command();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

void copyWord_file();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = EOF; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

boolean isWordEqual(Word kata1, Word kata2);
/* bandingin dua kata */

void printWord(Word kata);
/* print kata */

#endif
