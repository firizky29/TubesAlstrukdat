/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan List(Inventory) dengan elemen 
   (Gadget) */
/* Penempatan elemen(Gadget) tidak selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LISTSTAT_H
#define LISTSTAT_H

#include "../../boolean.h"

#define INVENTORY_CAP 5
#define IDGADGET_UNDEF -1
#define HARGAGADGET_UNDEF -1

typedef struct {
    int idGadget;
    int harga;
}Gadget;

typedef struct{
    Gadget contents[INVENTORY_CAP];
}Inventory;

#define IDGADGET(g) g.idGadget
#define HARGAGADGET(g) g.harga
#define INVIDGADGET(I,idx) (I).contents[(idx)].idGadget
#define INVHARGAGADGET(I,idx) (I).contents[(idx)].harga

void CreateInventory(Inventory *inv);
/* I.S. inv sembarang */
/* F.S. Terbentuk Inventory inv kosong dengan kapasitas INVENTORY_CAP */
/* Proses: Inisialisasi semua elemen Gadget pada Inventory dengan elemen UNDEF nya */

void addGadget(Inventory *inv, Gadget g);
/* I.S. inv sembarang, g terdefinisi dan tidak kosong*/
/* F.S. Apabila inv belum penuh, Gadget pada inventory inv bertambah dengan g*/
/*      Bila penuh tampilkan : Inventory penuh!!*/
/* Proses : Melakukan searching dengan traversal pada inventory, penambahan*/
/*          dilakukan pada bagian inv yang kosong dan pertama kali ketemu */

void displayGadget(Inventory *inv);
/* Proses : Menuliskan gadget pada Inventory dengan traversal, gadget ditulis berurutan*/
/*          berdasarkan idGadget pada Inventory.*/
/*          idGadget = 1 -> KainPembungkusWaktu */
/*          idGadget = 2 -> Senter Pembesar */
/*          idGadget = 3 -> Pintu Kemana Saja */
/*          idGadget = 4 -> Mesin Waktu */
/*          idGadget = -1 -> -*/
/* I.S. inv boleh kosong */
/* F.S. Tampilan Inventory tanpa harga*/
/* Contoh : jika ada lima gadget dengan idGadget 1,2,3,4,-1 akan dicetak */
/*          1. Kain Pembungkus Waktu*/
/*          2. Senter Pembesar*/
/*          3. Pintu Kemana Saja*/
/*          4. Mesin Waktu*/
/*          5. -*/

boolean isInventoryEmpty(Inventory inv);
/* Mengirimkan true jika Inventory inv kosong, mengirimkan false jika tidak */

boolean isInventoryFull(Inventory inv);
/* Mengirimkan true jika Inventory inv penuh, mengirimkan false jika tidak */

void deleteGadget(Inventory *inv, int i, Gadget *val);
/* Proses: Menghapus Gadget yang berada pada index i */
/* I.S. List tidak kosong */
/* F.S. val adalah Gadget pada index ke-i sebelum penghapusan, */
/*      Banyak Gadget pada Inventory berkurang */
/*      Inventory mungkin menjadi kosong */
#endif