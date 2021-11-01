#include "filecharmachine.h"
#include <stdio.h>

char currentCharFile;
boolean endFile;

static FILE * tapeFile;
static int retvalFile;

void startFile(char *filename){
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
       tapeFile = fopen(filename, "r");
       advFile();
}


void advFile() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retvalFile = fscanf(tapeFile,"%c",&currentCharFile);
	endFile = (currentCharFile == MARKFILE);
    if(endFile){
        fclose(tapeFile);
    }
}

