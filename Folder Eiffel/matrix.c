/* 
NIM : 13520074
Nama : Eiffel Aqila Amarendra
Tanggal : 17 September 2021
Topik praktikum : ADT Matrix
Deskripsi : Pra Praktikum 5 (Program matrix.c)
*/

#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(((i >= 0) && (i <= ROW_CAP - 1)) && ((j >= 0) && (j <= COL_CAP - 1)));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (ROWS(m) - 1);
}
Index getLastIdxCol(Matrix m) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (COLS(m) - 1);
}
boolean isIdxEff(Matrix m, Index i, Index j) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(((i >= 0) && (i <= getLastIdxRow(m))) && ((j >= 0) && (j <= getLastIdxCol(m))));
}
ElType getElmtDiagonal(Matrix m, Index i) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(ELMT(m, i, i));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes) {
    /* KAMUS LOKAL */
    Index i, j;

    /* ALGORITMA */
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    for (i = 0; i <= getLastIdxRow(mIn); i++) {
        for (j = 0; j <= getLastIdxCol(mIn); j++) {
            ELMT(*mRes, i, j) = ELMT(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
    /* KAMUS LOKAL */
    int i, j;

    /* ALGORITMA */
    CreateMatrix(nRow, nCol, m);
    for (i = 0; i <= getLastIdxRow(*m); i++) {
        for (j = 0; j <= getLastIdxCol(*m); j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
    /* KAMUS LOKAL */
    Index i, j;

    /* ALGORITMA */
    for (i = 0; i <= getLastIdxRow(m); i++) {
        for (j = 0; j <= getLastIdxCol(m); j++) {
            if (j == getLastIdxCol(m)) {
                printf("%d", ELMT(m, i, j));
            } else {
                printf("%d ", ELMT(m, i, j));
            }
        }
        if (i != getLastIdxRow(m)) {
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE (TIDAK DAPAT ) ********** */
// Matrix addMatrix(Matrix m1, Matrix m2) {
//     /* KAMUS LOKAL */
//     Matrix m3;
//     Index i, j;

//     /* ALGORITMA */
//     CreateMatrix(ROWS(m1), COLS(m1), &m3);
//     for (i = 0; i <= getLastIdxRow(m1); i++) {
//         for (j = 0; j <= getLastIdxCol(m1); j++) {
//             ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
//         }
//     }
//     return m3;
// }
// Matrix subtractMatrix(Matrix m1, Matrix m2) {
//     /* KAMUS LOKAL */
//     Matrix m3;
//     Index i, j;

//     /* ALGORITMA */
//     CreateMatrix(ROWS(m1), COLS(m1), &m3);
//     for (i = 0; i <= getLastIdxRow(m1); i++) {
//         for (j = 0; j <= getLastIdxCol(m1); j++) {
//             ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
//         }
//     }
//     return m3;
// }
// Matrix multiplyMatrix(Matrix m1, Matrix m2) {
//     /* KAMUS LOKAL */
//     Matrix m3;
//     Index i, j, k;

//     /* ALGORITMA */
//     CreateMatrix(ROWS(m1), COLS(m2), &m3);
//     for (i = 0; i <= getLastIdxRow(m3); i++) {
//         for (j = 0; j <= getLastIdxCol(m3); j++) {
//             ELMT(m3, i, j) = 0;
//         }
//     }
//     for (i = 0; i <= getLastIdxRow(m3); i++) {
//         for (j = 0; j <= getLastIdxCol(m3); j++) {
//             for (k = 0; k <= getLastIdxCol(m1); k++) {
//                 ELMT(m3, i, j) = ELMT(m3, i, j) + (ELMT(m1, i, k)*ELMT(m2, k, j));
//             }
//         }
//     }
    
//     return m3;
// }
// Matrix multiplyConst(Matrix m, ElType x) {
//     /* KAMUS LOKAL */
//     Matrix m2;
//     Index i, j;

//     /* ALGORITMA */
//     CreateMatrix(ROWS(m), COLS(m), &m2);
//     for (i = 0; i <= getLastIdxRow(m); i++) {
//         for (j = 0; j <= getLastIdxCol(m); j++) {
//             ELMT(m2, i, j) = ELMT(m, i, j) * x;
//         }
//     }
//     return m2;
// }
// void pMultiplyConst(Matrix *m, ElType k) {
//     /* KAMUS LOKAL */
//     Index i, j;

//     /* ALGORITMA */
//     for (i = 0; i <= getLastIdxRow(*m); i++) {
//         for (j = 0; j <= getLastIdxCol(*m); j++) {
//             ELMT(*m, i, j) = ELMT(*m, i, j) * k;
//         }
//     }
// }

// /* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
// boolean isEqual(Matrix m1, Matrix m2) {
//     /* KAMUS LOKAL */
//     boolean flag;
//     int i, j;

//     /* ALGORITMA */
//     if (isSizeEqual(m1, m2)) {
//         flag = true;
//         for (i = 0; i <= getLastIdxRow(m1); i++) {
//             for (j = 0; j <= getLastIdxCol(m2); j++) {
//                 if(ELMT(m1, i, j) != ELMT(m2, i, j)) {
//                     flag = false;
//                 }
//             }
//         }
//     } else {
//         flag = false;
//     }
//     return flag;
// }
// boolean isNotEqual(Matrix m1, Matrix m2) {
//     /* KAMUS LOKAL */
//     /* ALGORITMA */
//     return(!(isEqual(m1, m2)));
// }
// boolean isSizeEqual(Matrix m1, Matrix m2) {
//     /* KAMUS LOKAL */
//     /* ALGORITMA */
//     return((ROWS(m1) == ROWS(m2)) && (COLS(m1) == COLS(m2)));
// }

// /* ********** Operasi lain ********** */
// int count(Matrix m) {
//     /* KAMUS LOKAL */
//     /* ALGORITMA */
//     return (ROWS(m) * COLS(m));
// }

// /* ********** KELOMPOK TEST TERHADAP Matrix ********** */
// boolean isSquare(Matrix m) {
//     /* KAMUS LOKAL */
//     /* ALGORITMA */
//     return (ROWS(m) == COLS(m));
// }
// boolean isSymmetric(Matrix m) {
//     /* KAMUS LOKAL */
//     boolean flag;
//     int i, j;

//     /* ALGORITMA */
//     if (isSquare(m)) {
//         flag = true;
//         for (i = 0; i <= getLastIdxRow(m); i++) {
//             for (j = 0; j <= getLastIdxCol(m); j++) {
//                 if(ELMT(m, i, j) != ELMT(m, j, i)) {
//                     flag = false;
//                 }
//             }
//         }
//     } else {
//         flag = false;
//     }
//     return flag;
// }
// boolean isIdentity(Matrix m) {
//     /* KAMUS LOKAL */
//     boolean flag;
//     int i, j;

//     /* ALGORITMA */
//     if (isSquare(m)) {
//         flag = true;
//         for (i = 0; i <= getLastIdxRow(m); i++) {
//             for (j = 0; j <= getLastIdxCol(m); j++) {
//                 if (i == j) {
//                     if(ELMT(m, i, j) != 1) {
//                         flag = false;
//                     }
//                 } else {
//                     if(ELMT(m, i, j) != 0) {
//                         flag = false;
//                     }
//                 }
//             }
//         }
//     } else {
//         flag = false;
//     }
//     return flag;
// }
// boolean isSparse(Matrix m) {
//     /* KAMUS LOKAL */
//     boolean flag;
//     int i, j;
//     float countNotZero;

//     /* ALGORITMA */
//     countNotZero = 0;
//     for (i = 0; i <= getLastIdxRow(m); i++) {
//         for (j = 0; j <= getLastIdxCol(m); j++) {
//             if(ELMT(m, i, j) != 0) {
//                 countNotZero += 1;
//             }
//         }
//     }
//     if (((countNotZero/count(m)) * 100) > 5) {
//         flag = false;
//     } else {
//         flag = true;
//     }
//     return flag;
// }
// Matrix inverse1(Matrix m) {
//     /* KAMUS LOKAL */
//     Matrix m2;

//     /* ALGORITMA */
//     m2 = multiplyConst(m, -1);
//     return m2;
// }
// void pInverse1(Matrix *m) {
//     /* KAMUS LOKAL */
//     /* ALGORITMA */
//     pMultiplyConst(m, -1);
// }
// float determinant(Matrix m) {
//     /* KAMUS LOKAL */
//     int i, rowM, colM, rowM2, colM2;
//     float det;
//     Matrix m2;

//     /* ALGORITMA */
//     det = 0;
//     if (count(m) == 1) {
//         det = ELMT(m, 0, 0);
//     } else if (count(m) == 4) {
//         det = (ELMT(m, 0, 0) * ELMT(m, 1, 1)) - (ELMT(m, 0, 1) * ELMT(m, 1, 0));
//     } else {
//         for (i = 0; i <= getLastIdxRow(m); i++) {
//             CreateMatrix((ROWS(m) - 1), (COLS(m) - 1), &m2);
//             rowM2 = colM2 = 0;
//             for (rowM = 0; rowM <= getLastIdxRow(m); rowM++) {   
//                 if (rowM != i) {
//                     colM2 = 0;
//                     for (colM = 1; colM <= getLastIdxCol(m); colM++) {
//                         ELMT(m2, rowM2, colM2) = ELMT(m, rowM, colM);
//                         colM2++;
//                     }
//                     rowM2++;
//                 }
//             }
//             if ((i + 1) % 2 == 1) {
//                 det += ELMT(m, i, 0) * determinant(m2);
//             } else {
//                 det -= ELMT(m, i, 0) * determinant(m2);
//             }
//         }
//     }
//     return det;
// }
// void transpose(Matrix *m) {
//     /* KAMUS LOKAL */
//     Index i, j;
//     ElType temp;

//     /* ALGORITMA */
//     for (i = 0; i <= getLastIdxRow(*m); i++) {
//         for (j = i; j <= getLastIdxCol(*m); j++) {
//             temp = ELMT(*m, i, j);
//             ELMT(*m, i, j) = ELMT(*m, j, i);
//             ELMT(*m, j, i) = temp;
//         }
//     }
// }