#include <initstate.h>
#include <loadstate.h>
#include <boolean.h>
#include <pcolor.h>

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
int countMove;
ListDin LocList;
Queue daftarPesanan;
Word configName;
int countDelivered;

/* check if saved files are available for load game */
boolean isLoadAvailable(){
    int n = 0;
	struct dirent *det;  // pointer for directory entry
    char* loadGameDirt = "data/saved-file/";
    DIR *drt = opendir(loadGameDirt);
    if (drt == NULL){
		return false;
    }
    while ((det = readdir(drt)) != NULL){
        n++;
    }
    closedir(drt);
    if (n <= 2){
        return false;
    }
    else{
        return true;
    }
}

/* load saved file */
void load(){
	struct dirent *de;  // pointer for directory entry
    char* loadGameDir = "data/saved-file/";
    DIR *dr = opendir(loadGameDir);
    if (dr == NULL){
        print_red("Could not open current directory" );
		return;
    }
    // print available saved files
    printf("These are all available files you can load: \n");
    while ((de = readdir(dr)) != NULL){
        if(de->d_name[0]!='.'){
            printf("- %s\n", de->d_name);
        }
    }
    // get selected saved file path
    closedir(dr);
    printf("Enter filename (filename): ");
    Word filename = inputWord();
    Word filepath;
    strcpy(filepath.contents, loadGameDir);
    strcat(filepath.contents, filename.contents);
    strcat(filepath.contents, ".txt");
    filepath.length = 21+filename.length;
    while (!fopen(filepath.contents, "r")){
        print_red("File not found, enter filename again: ");
        filename = inputWord();
        strcpy(filepath.contents, loadGameDir);
        strcat(filepath.contents, filename.contents);
        strcat(filepath.contents, ".txt");
        filepath.length = 21+filename.length;
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
    Queue tempdp;
    CreateList(&temp);
    CreateQueue(&tempdp);
    emptyWord();
    readFile(filepath);
    // get name of corresponding config file
    configName = currentWord;
    advWord_file();
    // get current position
    CHARLOC(curPosition) = currentWord.contents[0];
    advWord_file();
    COORLOC(curPosition) = getPoint();
    // get built-in progress
    curTime = (long)(wtoi(currentWord));
    curMoney = (long)(wtoi(currentWord));
    curSpeed = wtoi(currentWord);
    speedBoost = wtoi(currentWord);
    countMove = wtoi(currentWord);
    countVIP = wtoi(currentWord);
    countReturn = wtoi(currentWord);
    countDelivered = wtoi(currentWord);
    int i, par, t, pt, w;
    char pu, d, tp; 
    Pesanan pesanan;
    // get curbag progress (stack)
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
        w = wtoi(currentWord);
        pesanan = CreatePesanan(t, pu, d, tp, pt, w);
        push(&curBag, pesanan);
    }
    // get curinventory progress (inventory)
    par = wtoi(currentWord);
    for (i = 0; i < par; i++){
        INVIDGADGET(curInventory, i) = wtoi(currentWord);
        INVHARGAGADGET(curInventory, i) = wtoi(currentWord);
    }
    // get curprogress progress (linked list)
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
        w = wtoi(currentWord);
        pesanan = CreatePesanan(t, pu, d, tp, pt, w);
        insertLastLL(&curProgress, pesanan);
    }
    // temporarily store curtodolist progress (linked list)
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
        w = wtoi(currentWord);
        pesanan = CreatePesanan(t, pu, d, tp, pt, w);
        insertLastLL(&temp, pesanan);
    }
    // temporarily store daftar pesanan (queue)
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
        w = wtoi(currentWord);
        pesanan = CreatePesanan(t, pu, d, tp, pt, w);
        enqueue(&tempdp, pesanan);
    }
    // get config file path
    Word filepathconfig;
    char* newGameDir = "data/original-config-file/";
    strcpy(filepathconfig.contents, newGameDir);
    strcat(filepathconfig.contents, configName.contents);
    strcat(filepathconfig.contents, ".txt");
    filepathconfig.length = 31+configName.length;
    // initialize global variables from config
    initConfig(filepathconfig);
    // set curtodolist to saved file progress
    curToDoList = temp;
    // set daftarpesanan to saved file progress
    daftarPesanan = tempdp;
}