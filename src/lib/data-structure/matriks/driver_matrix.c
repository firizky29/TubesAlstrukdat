#include <stdio.h>
#include <boolean.h>
#include <matrix.h>

int main(){
    /* KAMUS LOKAL */
    Matrix m;
    int rowDim, colDim;

    /* ALGORITMA */
    /* Input row and column dimension */
    printf("Masukkan ukuran baris dan kolom: ");
    scanf("%d %d",&rowDim,&colDim);
    while ((rowDim < 0) || (colDim < 0)) {
        printf("Masukkan salah, ulangi!\n");
        printf("Masukkan ukuran baris dan kolom: ");
        scanf("%d %d",&rowDim,&colDim);
    } 

    /* Mengisi matrix */
    readMatrix(&m, rowDim,colDim);

    /* display */
    printf("\nIsi matrix: ");
    displayMatrix(m);

    return 0;
}