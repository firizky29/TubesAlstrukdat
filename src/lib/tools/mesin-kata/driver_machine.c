#include <stdio.h>
#include <stdlib.h>

#include <listdin.h>
#include <matrix.h>
#include <point.h>
#include <charmachine.h>
#include <boolean.h>
#include <wordmachine.h>

int main(){
    Word tes = {"START", 5};
    printf("Type 'START' to start: ");
    Word choice = inputWord();
    if (!isWordEqual(choice, tes)){
        printf("You typed ");
        printWord(choice);
        printf(". That's not 'START'.");
    }
    else{
        printf("Enter number of buildings: ");
        int buildings = atoi(inputWord().contents);
        ListDin l;
        CreateListDin(&l, buildings);
        int i, x, y;
        char c;
        for (i = 0; i < buildings; i++){
            printf("Enter the coordinates of Building Number %d\n", i+1);
            printf("Enter x coordinate: ");
            x = atoi(inputWord().contents);
            printf("Enter y coordinate: ");
            y = atoi(inputWord().contents);
            printf("Enter the character of the building: ");
            c = inputWord().contents[0];
            insertLast(&l, c, x, y);
        }
        printf("Here are your buildings!\n");
        displayList(l);
    }
}