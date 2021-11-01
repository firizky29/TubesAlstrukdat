#include <stdio.h>
#include "boolean.h"
#include "lib/tools/mesin-karakter/charmachine.h"
#include "lib/tools/mesin-kata/wordmachine.h"

int main(){
    startWord_file("data/original-config-file/tes_config.txt");
    while (!endWord){
        for (int i = 0; i < currentWord.length; i++){
            printf("%c", currentWord.contents[i]);
        }
        if (currentCharFile == MARKFILE){
            printf("%c\n", MARKFILE);
        }
        else{
            printf("%c", BLANK);
        }
        advWord_file();
    }
    //printf("Hellow\n");
    
    return 0;
}