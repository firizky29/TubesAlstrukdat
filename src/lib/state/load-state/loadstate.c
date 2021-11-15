#include <initstate.h>
#include <loadstate.h>
#include <boolean.h>

int N, M, L, P;
long curTime;
Location curPosition;
long curMoney;
int curSpeed; // dalam persen
Stack curBag;
Map curMap;
Matrix adj;
Inventory curInventory;
LinkedList curProgress;
LinkedList curToDoList;
boolean speedBoost;
int countHeavyItem ;
int countMove;
ListDin LocList;
Queue daftarPesanan;
Word configName;

// List curInventory;
// LinkedList curProgress;
// Queue curUsedGadget;

boolean isLoadAvailable(){
    int n = 0;
	struct dirent *de;  // Pointer for directory entry
    char* loadGameDir = "data/saved-file/";
    DIR *dr = opendir(loadGameDir);
    if (dr == NULL){
		return false;
    }
    while ((de = readdir(dr)) != NULL){
        n++;
    }
    closedir(dr);
    if (n <= 2){
        return false;
    }
    else{
        return true;
    }
}

void load(){
	struct dirent *de;  // Pointer for directory entry
    char* loadGameDir = "data/saved-file/";
    DIR *dr = opendir(loadGameDir);
    if (dr == NULL){
        printf("Could not open current directory" );
		return;
    }
    printf("These are all available files you can load: \n");
    while ((de = readdir(dr)) != NULL){
        if(de->d_name[0]!='.'){
            printf("- %s\n", de->d_name);
        }
    }
    closedir(dr);
    printf("Enter filename (filename): ");
    Word filename = inputWord();
    Word filepath;
    strcpy(filepath.contents, loadGameDir);
    strcat(filepath.contents, filename.contents);
    strcat(filepath.contents, ".txt");
    filepath.length = 31+filename.length;
    while (!fopen(filepath.contents, "r")){
        printf("File not found, enter filename again: ");
        filename = inputWord();
        strcpy(filepath.contents, loadGameDir);
        strcat(filepath.contents, filename.contents);
        strcat(filepath.contents, ".txt");
        filepath.length = 31+filename.length;
    }
    printf("Loading ");
    printWord(filename);
    printf("....\n");
    interface();
    // reading file config + get info
    readFile(filepath);
    configName = currentWord;
    while(!endFile){
        printWordFile(currentWord);
    }
    fclose(tape);

    Word filepathconfig;
    char* newGameDir = "data/original-config-file/";
    strcpy(filepathconfig.contents, newGameDir);
    strcat(filepathconfig.contents, configName.contents);
    strcat(filepathconfig.contents, ".txt");
    filepathconfig.length = 31+configName.length;
    initConfig(filepathconfig);

    // isi pake lanjut ngeread filenya yang bukan dari file config
    //curPosition = ELMT(LocList, 0);    
    /* yang belom ada 
    Stack curBag;
    Inventory curInventory;
    LinkedList curProgress;
    LinkedList curToDoList;
    ListDin LocList;
    */
}