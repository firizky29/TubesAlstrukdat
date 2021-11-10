#include "initstate.h"

int N, M, L, P;
ll curTime;
Location curPosition;
ll curMoney;
int curSpeed; // dalam persen
Stack curBag;
Map curMap;
Matrix adj;
// extern Inventory curInventory;
LinkedList curProgress;
LinkedList curToDoList;
boolean speedBoost;
int countHeavyItem ;
int countMove;
ListDin LocList;

// List curInventory;
// LinkedList curProgress;
// Queue curUsedGadget;

void getMap(){
/* get n x m from config and return n x m matrix */
	N = wtoi(currentWord);
	M = wtoi(currentWord);
	CreateMap(&curMap, N, M);
}

Point getPoint(){
/* get and return point from config */
	int x, y;
	x = wtoi(currentWord);
	y = wtoi(currentWord);
	Point hq = MakePoint(x, y);
	return hq;
}

void getAdjacency(Matrix *m, int n){
/* get and return adjacency matrix from config */
	int temp, i, j;
	CreateMatrix(n, n, m);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			temp = wtoi(currentWord);
			MAT(*m, i, j) = temp;
		}
	}
}

void getLoc(Point pointhq){
/* get char and coord of loc and return list dinamis */
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

void globalinit(){
	struct dirent *de;  // Pointer for directory entry

    DIR *dr = opendir("data/original-config-file");
    if (dr == NULL){
        printf("Could not open current directory" );
		return;
    }
    while ((de = readdir(dr)) != NULL)
            printf("%s\n", de->d_name);
  
    closedir(dr);
    printf("Enter configuration file level ([filename].txt): ");
    Word filename = inputWord();
	printWord(filename);
    while (!fopen(filename.contents, "r")){
        printf("File not found, enter filename again: ");
        filename = inputWord();
    }
    printf("Opening ");
    printWord(filename);
    printf("\n");
    
    // reading file config + get info
    readFile(filename);
    getMap();
    Point hq = getPoint();
    getLoc(hq);
    BuildingToMap(&curMap, LocList);
    getAdjacency(&adj, NEFF(LocList));
// display info2"\nHQ berada pada (x,y): (%f, %f)\n\n", hq.X, hq.Y);
    printf("Map: %d x %d\n", REFF(curMap), CEFF(curMap));
    DisplayMap(curMap);
    printf("\n\n");
    displayMatrix(adj);
    printf("\n\n");
    displayList(LocList);
    printf("\n\n");
    // sisanya di print dulu aja karena nunggu ADTnya ada dulu
    while(!endFile){
        printWordFile(currentWord);
    }
	printf("Selamat\n");
    curMoney = 0;
    curTime = 0;
    curSpeed = 100;
    curPosition = ELMT(LocList, 0);
    fclose(tape);

}