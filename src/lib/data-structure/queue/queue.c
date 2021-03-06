/* File : queue.c */
/* Implementasi Queue */

#include <stdio.h>
#include <queue.h>

/* *** Kreator *** */
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFullQueue(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai QUEUE_CAP-1 */
    return (IDX_HEAD(q) == 0) && (IDX_TAIL(q) == QUEUE_CAP-1);
}
int lengthQueue(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    int l=0;
    
    if (!(isEmptyQueue(q))){
        l = IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }

    return l;
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Pesanan val){
/* Proses: Menambahkan val pada q dengan aturan FIFO, dengan waktu pesanan terurut secara membesar */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    
    // priority Queue, dengan elemen time terurut membesar
    int j;
    if(isEmptyQueue(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    } 
    else{
        if(IDX_TAIL(*q)==(QUEUE_CAP-1)) {
            for(int i=IDX_HEAD(*q); i<=IDX_TAIL(*q); i++) {
                (*q).buffer[i-IDX_HEAD(*q)] = (*q).buffer[i];
            }
            IDX_TAIL(*q) -= IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }
        j = IDX_TAIL(*q);
        while (j >= 0 && (*q).buffer[j].time > val.time){ 
            (*q).buffer[j+1] = (*q).buffer[j];
            j = j - 1;
        }
        (*q).buffer[j + 1] = val;
        IDX_TAIL(*q)++;
    }
}
void dequeue(Queue *q, Pesanan *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
    *val = HEAD(*q);
    if (IDX_HEAD(*q)==IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
    IDX_HEAD(*q) += 1;        
    }
}
/* *** Display Queue *** */
void displayQueue(Queue q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    printf("[");
    if (lengthQueue(q)!=0){
        for (int i=IDX_HEAD(q); i<=IDX_TAIL(q);i++){
            /*printf("%d",(q).buffer[i]); */
            displayPesanan((q).buffer[i]);
            if (i<IDX_TAIL(q)){
                printf(",");
            }
        }
    }
    printf("]");
}