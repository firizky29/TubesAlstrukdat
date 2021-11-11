#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include <charmachine.h>
#include <boolean.h>

#define MAXWORD 50
#define BLANK ' '

typedef struct {
   char contents[MAXWORD]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Word;

/* Word Engine State */
extern boolean endWord;
extern Word currentWord;

/* PRIMITIVE FUNCTIONS: From File & Command */
void ignoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = MARK */
void copyWord_file();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
void copyWord_command();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
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
void advWord_file();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
void advWord_command();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
boolean isWordEqual(Word kata1, Word kata2);
/* membandingkan dua kata dan return true kalo sama, return false kalo beda */


/* READ INPUT & PRINT OUTPUT (File & CMD) */
Word inputWord();
/* menerima input dari command line dan dijadikan output berupa Word */
void readFile(Word filename);
/* membaca file dengan nama filename */
void printWordFile(Word kata);
/* print kata dari suatu file */
void printWord(Word kata);
/* print kata */

/* CONVERT WORD */
int wtoi(Word kata);
/* convert word to integer */





#endif