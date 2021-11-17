#include <stdio.h>
#include <boolean.h>
#include <listdin.h>

int main(){
    /* KAMUS */
    ListDin listDin;
    int CAP, i;
    char charLoc;
    int absisLoc, ordinatLoc;
    int idx;

    /* ALGORITMA */

    /* Input kapasitas listDin */
    printf("Masukkan kapasitas List: ");
    scanf("%d", &CAP);
    while(CAP < 0){
        printf("\nMasukkan tidak valid\n");
        printf("Masukkan kapasitas List: ");
        scanf("%d", &CAP);
    }

    /* Membuat List Dinamis */
    CreateListDin(&listDin, CAP);

    /* Test list kosong */
    printf("\n/* *** Tes Kosong/Tidaknya List Dinamis *** */\n");
    if(isListEmpty(listDin)){
        printf("List Dinamis kosong\n");
    } else {
        printf("List Dinamis tidak kosong");
    }

    /* Menginput elemen listDin yang bertipe Location */
    if(CAPACITY(listDin) != 0){
        printf("\n/* *** Tes Pengisian List Dinamis *** */\n");
        for (i = 0; i < CAP; i++) {
            printf("Location ke-%d (charLoc, absisLoc, ordinatLoc): ", i+1);
            scanf(" %c %d %d", &charLoc, &absisLoc, &ordinatLoc);
            insertLast(&listDin, charLoc, absisLoc, ordinatLoc);
        }
    }

    /* Mencetak panjang listDin */
    printf("\n/* *** Tes Pencetakan Panjang List Dinamis *** */\n");
    printf("Panjang List Dinamis: %d\n", length(listDin));

    /* Display */
    printf("\nIsi List Dinamis:\n");
    displayList(listDin);

    /* Test list penuh */
    printf("\n\n/* *** Tes Penuh/Tidaknya List Dinamis *** */\n");
    if(isListFull(listDin)){
        printf("List Dinamis penuh\n");

        /* Memperbesar kapasitas */
        printf("Perbesar kapasitas List sebesar: ");
        scanf(" %d", &CAP);
        while(CAP < 0){
            printf("\nMasukkan tidak valid\n");
            printf("Perbesar kapasitas List sebesar: ");
            scanf(" %d", &CAP);
        }
        growList(&listDin, CAP);
        printf("Kapasitas list bertambah sebanyak %d sehingga menjadi: %d\n", CAP, CAPACITY(listDin));
    }

    /* Menambahkan bangunan di akhir listDin */
    if (!isListFull(listDin)) {
        printf("\n/* *** Tes Penambahan bangunan di akhir listDin. *** */\n");
        printf("Location (charLoc, absisLoc, ordinatLoc): ");
        scanf(" %c %d %d", &charLoc, &absisLoc, &ordinatLoc);
        insertLast(&listDin, charLoc, absisLoc, ordinatLoc);

        printf("\nIsi List Dinamis:\n");
        displayList(listDin);
    }

    /* Pencarian bangunan berdasarkan nama bangunan */
    printf("\n\n/* *** Tes Pencarian Elemen List Dinamis *** */\n");
    printf("Masukkan nama bangunan yang ingin dicari: "); scanf(" %c", &charLoc);
    idx = indexOfCharLoc(listDin, charLoc);
    if (idx == IDX_UNDEF) {
        printf("Bangunan tidak ditemukan!\n");
    } else {
        printf("Bangunan ditemukan pertama kali di indeks ke-%d di dalam list.\n", idx);
    }

    /* Menghapus bangunan di akhir listDin */
    printf("\n/* *** Tes Penghapusan Elemen Terakhir List Dinamis *** */\n");
    deleteLast(&listDin, &charLoc, &absisLoc, &ordinatLoc);
    printf("Bangunan dengan nama %c yang berlokasi di koordinat (%d,%d) berhasil dihapus.\n", charLoc, absisLoc, ordinatLoc);
    printf("\nIsi List Dinamis:\n");
    displayList(listDin);
    printf("\n");

    return 0;
}