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
    // initialize
    CreateInventory(&curInventory);
    CreateList(&curProgress);
    CreateStack(&curBag);
    LinkedList temp;
    CreateList(&temp);
    // get config name
    readFile(filepath);
    configName = currentWord;
    advWord_file();
    // load loc (curposition)
    CHARLOC(curPosition) = currentWord.contents[0];
    advWord_file();
    COORLOC(curPosition) = getPoint();
    // load non-adt progress
    curTime = (long)(wtoi(currentWord));
    curMoney = (long)(wtoi(currentWord));
    curSpeed = wtoi(currentWord);
    speedBoost = wtoi(currentWord);
    countHeavyItem = wtoi(currentWord);
    countMove = wtoi(currentWord);
    int i, par, t, pt;
    char pu, d, tp; 
    Pesanan pesanan;
    // load curbag (stack)
    CURCAP(curBag) = wtoi(currentWord);
    par = wtoi(currentWord);
    for (i = 0; i < par; i++){
        t = wtoi(currentWord);
        pu = currentWord.contents[0];
        advWord_file();
        d = currentWord.contents[0];
        advWord_file();
        tp = currentWord.contents[0];
        advWord_file();
        pt = wtoi(currentWord);
        pesanan = CreatePesanan(t, pu, d, tp, pt);
        push(&curBag, pesanan);
    }
    // load curinventory (inventory)
    par = wtoi(currentWord);
    for (i = 0; i < par; i++){
        INVIDGADGET(curInventory, i) = wtoi(currentWord);
        INVHARGAGADGET(curInventory, i) = wtoi(currentWord);
    }
    // load curprogress (linked list)
    par = wtoi(currentWord);
    for (i = 0; i < par; i++){
        t = wtoi(currentWord);
        pu = currentWord.contents[0];
        advWord_file();
        d = currentWord.contents[0];
        advWord_file();
        tp = currentWord.contents[0];
        advWord_file();
        pt = wtoi(currentWord);
        pesanan = CreatePesanan(t, pu, d, tp, pt);
        insertLastLL(&curProgress, pesanan);
    }
    // load curtodolist (linked list)
    par = wtoi(currentWord);
    for (i = 0; i < par; i++){
        // masukin item pesanan
        t = wtoi(currentWord);
        pu = currentWord.contents[0];
        advWord_file();
        d = currentWord.contents[0];
        advWord_file();
        tp = currentWord.contents[0];
        advWord_file();
        pt = wtoi(currentWord);
        pesanan = CreatePesanan(t, pu, d, tp, pt);
        insertLastLL(&temp, pesanan);
    }

    while(!endFile){
        printWordFile(currentWord);
    }
    fclose(tape);

    // initialize pconfig
    Word filepathconfig;
    char* newGameDir = "data/original-config-file/";
    strcpy(filepathconfig.contents, newGameDir);
    strcat(filepathconfig.contents, configName.contents);
    strcat(filepathconfig.contents, ".txt");
    filepathconfig.length = 31+configName.length;
    initConfig(filepathconfig);
    fclose(tape);
    curToDoList = temp;
}