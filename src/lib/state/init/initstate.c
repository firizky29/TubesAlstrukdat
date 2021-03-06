#include <initstate.h>
#include <pcolor.h>

int N, M, L, P;
long curTime;
Location curPosition;
long curMoney;
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
int countVIP;
int countReturn;
int countDelivered;

/* initialize matrix (n x m) from config */
void getMap(){
	N = wtoi(currentWord);
	M = wtoi(currentWord);
	CreateMap(&curMap, N, M);
}

/* get and return point from config */
Point getPoint(){
	int x, y;
	x = wtoi(currentWord);
	y = wtoi(currentWord);
	Point hq = MakePoint(x, y);
	return hq;
}

/* initialize adjacency matrix from config */
void getAdjacency(Matrix *m, int n){
	int temp, i, j;
	CreateMatrix(n, n, m);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			temp = wtoi(currentWord);
			MAT(*m, i, j) = temp;
		}
	}
}

/* get char and coord of loc from config */
void getLoc(Point pointhq){
	int i;
	int L = wtoi(currentWord);
	CreateListDin(&LocList, (L+1));
	CHARELMT(LocList, 0) = '8';
	COORELMT(LocList, 0) = pointhq;
	for (i = 1; i < (L + 1); i++){
		CHARELMT(LocList, i) = currentWord.contents[0];
		advWord_file();
		COORELMT(LocList, i) = getPoint();
	}
	NEFF(LocList) = L+1;
}

/* initialize daftar pesanan & to-do list from config */
void getPesananList(){
    int i;
    P = wtoi(currentWord);
    // create Queue pesanan
    Pesanan pesanan;
    int t, pt, w;
    char pu, d, tp;
    countVIP = 0;
    CreateQueue(&daftarPesanan);
    CreateList(&curToDoList);
    for (i=0; i < P; i++){    
        // insert item pesanan
        t = wtoi(currentWord);
        pu = currentWord.contents[0];
        advWord_file();
        d = currentWord.contents[0];
        advWord_file();
        tp = currentWord.contents[0];
        advWord_file();
        if (tp == 'P'){
            pt = wtoi(currentWord); // get time-limit of perishable item
            w = 0;
        }
        else{
            pt = -1; // set non-perishable item time-limit to -1
            if(tp=='H'){
                w = 1; // weight count for heavy item
            }
            else{
                w = 0; // weight count for non-heavy item
            }
        }
        pesanan = CreatePesanan(t, pu, d, tp, pt, w);
        if(t == 0){
            insertLastLL(&curToDoList, pesanan);
            if(TIPEITEM(pesanan)=='V'){
                countVIP += 1;
            }
        }
        else{
            enqueue(&daftarPesanan, pesanan);
        }
    }
}

/* display start game interface */
void interface(){
    Word interface = {"data/interface/grafitti.txt", 27};
    readFile(interface);
    while(!endFile){
        if(currentChar!='?'){
            printf("%c", currentChar);
        }
        else{
            printf("\n");
        }
        adv();
    }
}

/* initialize global variables from config */
void initConfig(Word filepath){
    readFile(filepath);
    getMap();
    Point hq = getPoint();
    getLoc(hq);
    BuildingToMap(&curMap, LocList);
    getAdjacency(&adj, NEFF(LocList));
    getPesananList();
}

/* global initialization */
void globalinit(){
	struct dirent *de;  // pointer for directory entry
    char* newGameDir = "data/original-config-file/";
    DIR *dr = opendir(newGameDir);
    if (dr == NULL){
        printf("Could not open current directory" );
		return;
    }
    // print available config files
    printf("These are all available files you can choose: \n");
    while ((de = readdir(dr)) != NULL){
        if(de->d_name[0]!='.'){
            printf("- %s\n", de->d_name);
        }
    }
    // get selected config file path
    closedir(dr);
    printf("Enter configuration file level (filename): ");
    configName = inputWord();
    Word filepath;
    strcpy(filepath.contents, newGameDir);
    strcat(filepath.contents, configName.contents);
    strcat(filepath.contents, ".txt");
    filepath.length = 31+configName.length;
    while (!fopen(filepath.contents, "r")){
        print_red("File not found, enter filename again: ");
        configName = inputWord();
        strcpy(filepath.contents, newGameDir);
        strcat(filepath.contents, configName.contents);
        strcat(filepath.contents, ".txt");
        filepath.length = 31+configName.length;
    }
    printf("Opening ");
    printWord(configName);
    printf("....\n");
    interface();
    // initialize global variables from config
    initConfig(filepath);
    // initialize built-in global variables
    curMoney = 0;
    curTime = 0;
    speedBoost = false;
    curPosition = ELMT(LocList, 0);  
    countMove = 0;
    countReturn = 0;
    countDelivered = 0;
    CreateStack(&curBag);
    CreateList(&curProgress);
    CreateInventory(&curInventory);
}