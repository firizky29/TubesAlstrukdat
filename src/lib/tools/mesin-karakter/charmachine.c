#include <charmachine.h>
#include <string.h>
#include <stdio.h>

FILE * tape;
int retval;
boolean endFile;
char currentChar;

void start_file(char *filename){
/* (For Files) Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

       endFile = false;
       tape = fopen(filename, "r");
       adv();
}

void start_command(){
/* Mfesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	tape = stdin;
	adv_command();
}

void adv(){
/* (For Files) Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	retval = fscanf(tape, "%c", &currentChar);
       if (retval == EOF){
              fclose(tape);
              endFile = true;
 	}
       else if (currentChar == '\n'){
              currentChar = ' ';
       }
}

void adv_command(){
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	retval = fscanf(tape, "%c", &currentChar);
}