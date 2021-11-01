#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include "../../data-structure/list-dinamis/listdin.h"
#include "../../data-structure/matriks/matrix.h"
#include "../../data-structure/point/point.h"
#include "../mesin-karakter/charmachine.h"
#include "../../boolean.h"

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
void advWord();
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

/* GET INFO FROM CONFIG FILE */
Matrix getMap();
/* get n x m from config and return n x m matrix */
POINT getPoint();
/* get and return point from config */
Matrix getAdjacency(int n);
/* get and return adjacency matrix from config */
ListDin getLoc(POINT pointhq);
/* get char and coord of loc and return list dinamis */

/* CHECK COMMAND VALIDITY */
boolean isNewGame(Word kata);
/* return true if kata is NEW_GAME and false if not */
boolean isExit(Word kata);
/* return true if kata is EXIT and false if not */
boolean isLoadGame(Word kata);
/* return true if kata is LOAD_GAME and false if not */
boolean isMove(Word kata);
/* return true if kata is MOVE and false if not */
boolean isPickUp(Word kata);
/* return true if kata is PICK_UP and false if not */
boolean isDropOff(Word kata);
/* return true if kata is DROP_OFF and false if not */
boolean isMap(Word kata);
/* return true if kata is MAP and false if not */
boolean isToDo(Word kata);
/* return true if kata is TO_DO and false if not */
boolean isInProgress(Word kata);
/* return true if kata is IN_PROGRESS and false if not */
boolean isBuy(Word kata);
/* return true if kata is BUY and false if not */
boolean isInventory(Word kata);
/* return true if kata is INVENTORY and false if not */
boolean isHelp(Word kata);
/* return true if kata is HELP and false if not */
boolean isSaveGame(Word kata);
/* return true if kata is SAVE_GAME and false if not */
boolean isReturn(Word kata);
/* return true if kata is RETURN and false if not */

#endif