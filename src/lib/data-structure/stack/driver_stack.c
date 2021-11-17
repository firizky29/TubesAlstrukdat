#include <stack.h>
#include <stdio.h>

int main(){
    Stack S;
    // buat stack kosong dengan kapasitas awal 3
    CreateStack(&S);
    // Pengecekan apakah stack kosong/nggak
    int N;
    printf("Masukkan banyaknya elemen: ");
    scanf("%d", &N);
    while(N > CURCAP(S)||N<0){
        printf("\nMasukkan tidak valid\n");
        printf("Masukkan banyaknya elemen: ");
        scanf("%d", &N);
    }
    Pesanan P;
    for(int i=0; i<N; i++){
        printf("Pesanan ke-%d (time, pickup, dropoff, tipe, perish, heavy): ", i+1);
        scanf("%d %c %c %c %d %d",&TIMEPESANAN(P),&PICKUPPESANAN(P),&DROPOFFPESANAN(P),&TIPEITEM(P), &PTIME(P), &WEIGHT(P));
        push(&S, P);
    }
    if(isStackEmpty(S)){
        printf("Stack kosong\n");
    }
    else{
        if(isStackFull(S)){
            printf("Stack penuh\n");
        }
        capMultiplier(&S, 2);
        printf("Kapasitas tas bertambah dua kali lipat menjadi: %d\n", CURCAP(S));
        capInc(&S, 1);
        printf("Kapasitas tas bertambah 1 unit menjadi: %d\n", CURCAP(S));
        while(!isStackEmpty(S)){
            pop(&S, &P);
            displayPesanan(P);
            printf("\n");
        }
    }
}