# Mobita Game

### 	IF2110 Algoritma & Struktur Data

*“Mobita menjadi seorang kurir demi mencari nafkah untuk keluarganya”*

Dengan adanya pandemi COVID-19, usaha orang tua Mobita mengalami penurunan pendapatan. Setelah diringankannya PPKM, Mobita ingin membantu orang tuanya mendapat penghasilan menjadi seorang kurir. Aplikasi ini akan membantu Mobita melacak pesanan, navigasi peta, mengambil, dan menurunkan barang.

Game ini adalah penerapan *abstract data type* dalam bahasa C. 



## Struktur Folder
Berikut ini adalah struktur folder dari project ini:
* Folder `test` berisi file eksekusi pengujian modul
* Folder `doc` berisi laporan dan notulensi rapat internal kelompok
* Folder `src` berisi source program. Pada folder ini terdiri atas:
  * file program utama `main.c`
  * Folder `lib` berisi pustaka, driver pustaka, dan file header ADT
* Folder `build` berisi file *object* hasil kompilasi semua pustaka dan program utama
* Folder `bin` berisi file eksekusi program utama


## Prosedur Penggunaan
> <b>Notes :</b> 
> Program ini dikompilasi menggunakan Makefile. Direkomendasikan untuk selalu mengompilasi ulang program sebelum menggunakan.


### **Windows**
Anda membutuhkan terminal Bash untuk bisa menjalankan perintah Make pada OS Windows. Anda bisa mengunjungi situs berikut untuk mengetahui prosedur instalasi salah satu Bash di Windows.
 https://medium.com/danielpadua/git-bash-with-vscode-593d5998f6be

Perhatikan bahwa sebagian besar interface pada program menggunakan modul *pcolor* yang (mungkin saja) tidak kompatibel dengan komputer Anda (Interface Text akan menjadi berantakan).

1. Untuk mengompilasi program jalankan
```
make all
```
2. Untuk menjalankan program melalui bash, jalankan
```
make run
```
3. Untuk menjalankan program pada terminal lain (pastikan sudah dikompilasi), jalankan
```
./bin/MobitaGame
```
4. Untuk mengompilasi sebuah modul ADT, jalankan
```
make ADT_BUILDER
```
5. Untuk mengompilasi seluruh modul ADT, jalankan
```
make <nama modul>
```
6. Untuk menjalankan modul ADT, jalankan
```
./test/<nama modul>
```

### **Linux**
1. Untuk bisa menggunakan perintah Make, buka terminal, lalu jalankan
```
sudo apt install build-essential
```
2. Lakukan kompilasi
```
make all
```
3. Untuk menjalankan program Anda bisa melakukannya dengan
```
make run   
```
4. Untuk mengompilasi modul driver tiap pustaka, Anda bisa melakukan perintah
```
make ADT_BUILDER
```
5. Lalu jalankan program tiap modul dengan
```
./test/<nama modul>
```

# Kontributor
Program ini dikembangkan dalam rangka memenuhi salah satu tugas besar mata kuliah Algoritma dan Struktur Data. Program ini dikembangkan oleh (K02 Kelompok Alstrukyey)
1. Eiffel Aqila Amarendra `(13520074)`<br>
ADT Point, ADT List Dinamis, ADT Matrix, command PICK_UP, command DROP_OFF, command RETURN, mekanisme ability, laporan
2. Claudia `(13520076)`<br>
ADT Queue, ADT Linked List, ADT Pesanan, command TO__DO, command IN_PROGRESS, laporan
3. Ghebyon Tohada Nainggolan `(13520079)`<br>
ADT List, Buy, Inventory, mekanisme penggunaan gadget, mekanisme jenis-jenis item, laporan
4. Sarah Azka Arief `(13520083)`<br>
ADT Mesin Karakter, ADT Mesin Kata, inisialisasi config, save/load game, ability speed boost, validasi command, laporan
5. Firizky Ardiansyah `(13520095)`<br>
ADT Stack, ADT Peta, program utama, command MOVE, command MAP, mekanisme waktu, VIP Item, gadget senter pengecil, mekanisme kompilasi, laporan

# Fitur/Command

<table>
<tr><td>No.</td><td>Command</td><td>Status</td></tr>
<tr><td>1.</td><td>MOVE</td><td>Selesai</td></tr>
<tr><td>2.</td><td>PICK_UP</td><td>Selesai</td></tr>
<tr><td>3.</td><td>DROP_OFF</td><td>Selesai</td></tr>
<tr><td>4.</td><td>MAP</td><td>Selesai</td></tr>
<tr><td>5.</td><td>TO_DO</td><td>Selesai</td></tr>
<tr><td>6.</td><td>IN_PROGRESS</td><td>Selesai</td></tr>
<tr><td>7.</td><td>BUY</td><td>Selesai</td></tr>
<tr><td>8.</td><td>INVENTORY</td><td>Selesai</td></tr>
<tr><td>9.</td><td>RETURN</td><td>Selesai</td></tr>
<tr><td>10.</td><td>HELP</td><td>Selesai</td></tr>
<tr><td>11.</td><td>EXIT</td><td>Selesai</td></tr>
<tr><td>12.</td><td>SAVE_GAME</td><td>Selesai</td></tr>
</table>
