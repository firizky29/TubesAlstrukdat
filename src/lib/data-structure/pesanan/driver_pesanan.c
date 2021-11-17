#include <stdio.h>
#include <boolean.h>
#include <pesanan.h>
#include <queue.h>

int main(){

    // Membuat Pesanan Baru 
    printf("Membuat pesanan baru: ");
    Pesanan P;
    P = CreatePesanan(1,'M','B','P',3,0);
    // Display 
    displayPesanan(P);
    printf("\n");

    printf("Kurangi perishable time sebanyak 2: ");
    // Mengurangi perishable time 
    subtractPtime(&P,2);
    // Display 
    displayPesanan(P);
    printf("\n");

    // Cek jenis item pesanan 
    printf("Cek apakah perishable item atau bukan: ");
    if (isXItem(P,'P')){
        printf("Item adalah Perishable Item\n");
    } else {
        printf("Bukan Perishable Item\n");
    }

    Pesanan P2;
    P2 = CreatePesanan(1,'M','B','H',-1,1);
    Pesanan P3;
    P3 = CreatePesanan(3,'H','C','P',3,0);
    Pesanan P4;
    P4 = CreatePesanan(3,'H','C','P',4,0);

    if (isEqualPesanan(P2,P3)){
        printf("Pesanan sama\n");
    } else {
        printf("Pesanan beda\n");
    }

}
