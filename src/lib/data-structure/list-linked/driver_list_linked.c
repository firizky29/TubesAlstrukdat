#include <stdio.h>
#include <boolean.h>
#include <pesanan.h>
#include <list_linked.h>

int main(){
    Pesanan P1, P2, P3;
    P1 = CreatePesanan(4,'M','B','P',3,0);
    P2 = CreatePesanan(3,'H','B','P',4,0);
    P3 = CreatePesanan(0,'M','C','P',5,0);

    LinkedList ToDoList;
    CreateList(&ToDoList);

    // insert Pesanan
    insertFirst(&ToDoList,P1);
    insertLastLL(&ToDoList,P3);
    insertAt(&ToDoList,P2,1);

    // banyak pesanan seharusnya 3
    printf("Banyak pesanan: %d\n",lengthLL(ToDoList));

    printf("Indeks dari pesanan dengan pickup pointnya building H: %d\n",indexOfPesananBuilding(ToDoList,'H'));
    DecrementAllPerishableItem(&ToDoList,1);
    setBackWeight(&ToDoList);

    printf("Berat total: %d\n",countWeight(ToDoList));

    Pesanan val;

    // delete semua pesanan
    deleteFirst(&ToDoList,&val);
    deleteLastLL(&ToDoList,&val);
    deleteAt(&ToDoList,0,&val);

    // pesanan seharusnya kosong karena sudah didelete
    if (isEmpty(ToDoList)){
        printf("To Do List kosong\n");
    } 

}