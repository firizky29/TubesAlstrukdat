#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

int main(){
    // check is kata equal
    Word kata;
    kata.length = 3;
    kata.contents[0] = 'a';
    kata.contents[1] = 'b';
    kata.contents[2] = 'c';
    startWord();
    boolean found = isWordEqual(currentWord, kata);
    if (found){
        printf("yoi\n");
    }

    // check print word
    printWord(currentWord);
    printf("\n");

    // word input (mark masih . )
    int i;
    while (!endWord){
        for (i=0; i < currentWord.length; i++){ 
            printf("%c", currentWord.contents[i]); 
        } 
        if (currentChar == MARK){
            printf("%c\n", MARK);
        }
        else {
            printf("%c", BLANK);
        }
        advWord();
    }

    // file input (mark masih . )
    startWord_file("tes_config.txt");
    while (!endWord){
        for (i = 0; i < currentWord.length; i++){
            printf("%c", currentWord.contents[i]);
        }
        if (currentChar == MARK){
            printf("%c\n", MARK);
        }
        else{
            printf("%c", BLANK);
        }
        advWord();
    }
    printf("YOI \n NEXT \n \n");
    printf("Udah sampe sini\n");
}