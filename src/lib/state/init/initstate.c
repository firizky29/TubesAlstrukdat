#include "initstate.h"

int N, M, L, P;
ll curTime;
Point curPosition;
ll curMoney;
int curSpeed; // dalam persen
Stack curBag;
Map curMap;
// List curInventory;
// LinkedList curProgress;
// Queue curUsedGadget;

Matrix getMap(){
/* get n x m from config and return n x m matrix */
	N = wtoi(currentWord);
	M = wtoi(currentWord);
	Matrix map;
	CreateMatrix(N, M, &map);
	return map;
}

Point getPoint(){
/* get and return point from config */
	int x, y;
	x = wtoi(currentWord);
	y = wtoi(currentWord);
	Point hq = MakePoint(x, y);
	return hq;
}

Matrix getAdjacency(int n){
/* get and return adjacency matrix from config */
	int temp, i, j;
	Matrix adjacency;
	CreateMatrix(n, n, &adjacency);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			temp = wtoi(currentWord);
			MAT(adjacency, i, j) = temp;
		}
	}
	return adjacency;
}

ListDin getLoc(Point pointhq){
/* get char and coord of loc and return list dinamis */
	int i;
	ListDin loc;
	int num;
	L = wtoi(currentWord);
	CreateListDin(&loc, (num+1));
	CHARLOC(loc, 0) = '8';
	COORLOC(loc, 0) = pointhq;
	for (i = 1; i < (L + 1); i++){
		CHARLOC(loc, i) = currentWord.contents[0];
		advWord_file();
		COORLOC(loc, i) = getPoint();
	}
	NEFF(loc) = loc.capacity;
	return loc;
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
	ListDin loc;
    readFile(filename);
    setPeta(&curMap, getMap());
    Point hq = getPoint();
    setBuilding(&curMap, getLoc(hq));
    setAdj(&curMap, getAdjacency(loc.capacity));
    // display info

    printf("\nHQ berada pada (x,y): (%f, %f)\n\n", hq.X, hq.Y);
    printf("Map: %d x %d\n", curMap.Peta.rowEff, curMap.Peta.colEff);
    displayMatrix(curMap.Peta);
    printf("\n\n");
    displayMatrix(curMap.Adj);
    printf("\n\n");
    displayList(loc);
    printf("\n\n");
    // sisanya di print dulu aja karena nunggu ADTnya ada dulu
    while(!endFile){
        printWordFile(currentWord);
    }
	printf("Selamat\n");
    curMoney = 0;
    curTime = 0;
    curSpeed = 100;
    fclose(tape);

}