int main(){
    
}
/*
#include<stdio.h>
#include"../pesanan/pesanan.h"
#include"queue.h"

int main(){
    // Membuat pesanan 
    Pesanan P1, P2, P3, P4, P5, P6;
    P1 = CreatePesanan(4,'M','B','P',3);
    P2 = CreatePesanan(3,'H','B','P',4);
    P3 = CreatePesanan(0,'M','C','P',5);
    P4 = CreatePesanan(1,'K','B','P',5);
    P5 = CreatePesanan(3,'M','B','P',7); 
    P6 = CreatePesanan(3,'V','B','P',4); 

    // Memasukkan pesanan ke queue 
    Queue Q;
    CreateQueue(&Q);

    if (isEmptyQueue(Q)){
        printf("Queue kosong\n");
    }
    
    printf("Masukkan elemen queue dan tampilkan: ");

    enqueue(&Q,P1);
    enqueue(&Q,P2);
    enqueue(&Q,P3);
    enqueue(&Q,P4);
    enqueue(&Q,P5);
    enqueue(&Q,P6);

    printf("Perhatikan bahwa Queue terurut membesar berdasarkan elemen pertama\n");
    displayQueue(Q);
    printf("\n");
    printf("Banyak elemen queue: %d\n",lengthQueue(Q));

    // Melakukan dequeue 
    Pesanan val;
    dequeue(&Q,&val);
    dequeue(&Q,&val);

    printf("Banyak elemen queue setelah didequeue: %d\n",lengthQueue(Q));
    
    displayQueue(Q);
    printf("\n");

    if(isFullQueue(Q)){
        printf("Queue penuh\n");
    } else {
        printf("Queue belum penuh\n");
    }


}

*/
