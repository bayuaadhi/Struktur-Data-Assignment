# <h1 align="center">DOUBLYLINKEDLIST(BAGIANPERTAMA)</h1>
<p align="center">Bayu Adhi Nugroho</p>
 
## Dasar Teori
Doubly Linked List merupakan struktur data yang setiap elemennya memiliki dua buah pointer, yaitu satu pointer yang mengarah ke node sebelumnya (prev) dan satu pointer lain yang menunjuk ke node berikutnya (next).

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};

struct List { 
    address first; 
    address last; 
}; 

void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 

void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 

void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 

void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}

int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}
```
Program ini memperlihatkan proses pembuatan dan pengolahan struktur data doubly linked list dengan menambahkan tiga nilai (1, 2, dan 3) pada posisi tertentu, sehingga urutan akhir data yang dihasilkan adalah 1, 3, dan 2.

## Unguided 

### 1. [Soal]
**Doublylist.h**
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

#define Nil NULL

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef Kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

/* PROTOTIPE */
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
void printInfo(List L);

address findElm(List L, string nopol);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```

**Doublylist.cpp**
```C++
#include "Doublylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
        return;
    }

    while (P != Nil) {
        cout << P->info.nopol << " | "
             << P->info.warna << " | "
             << P->info.thnBuat << endl;
        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }
    P = L.first;
    if (L.first == L.last) { // satu elemen
        L.first = L.last = Nil;
    } else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }
    P = L.last;
    if (L.first == L.last) {
        L.first = L.last = Nil;
    } else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}

void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }

    P = Prec->next;
    Prec->next = P->next;

    if (P->next != Nil)
        P->next->prev = Prec;

    P->next = Nil;
    P->prev = Nil;
}
```

**main.c**
```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    createList(L);

    // insert data
    insertLast(L, alokasi({"D001", "Hitam", 2010}));
    insertLast(L, alokasi({"D002", "Merah", 2015}));
    insertLast(L, alokasi({"D003", "Putih", 2012}));
    insertLast(L, alokasi({"D004", "Biru", 2018}));

    cout << "Data Kendaraan:" << endl;
    printInfo(L);

    cout << "\nCari Nopol D001:" << endl;
    address P = findElm(L, "D001");
    if (P != Nil) {
        cout << "Ditemukan: " << P->info.nopol << ", " << P->info.warna 
             << ", " << P->info.thnBuat << endl;
    } else {
        cout << "Tidak ditemukan" << endl;
    }

    cout << "\nHapus D003:" << endl;
    address del;
    address Prec = L.first;
    while (Prec != Nil && Prec->next != Nil && Prec->next->info.nopol != "D003")
        Prec = Prec->next;

    if (Prec != Nil && Prec->next->info.nopol == "D003") {
        deleteAfter(Prec, del);
        dealokasi(del);
    }

    printInfo(L);

    return 0;
}
```
#### Output:
<img width="542" height="302" alt="image" src="https://github.com/user-attachments/assets/0a1bbab1-479e-422e-bbd3-59f22a17d5e7" />


Dibandingkan singly linked list, doubly linked list memiliki kelebihan karena memungkinkan penelusuran data dari dua arah. Kemampuan ini menjadikan proses penyisipan dan penghapusan data lebih efektif, terutama pada operasi yang memerlukan referensi ke elemen sebelumnya.

#### Full code Screenshot:
<img width="738" height="883" alt="image" src="https://github.com/user-attachments/assets/6874895e-afa4-4cc1-85b9-d9cf13944760" />
<img width="932" height="901" alt="image" src="https://github.com/user-attachments/assets/57b2da73-5417-4a63-a1b2-d678328f0118" />
<img width="638" height="795" alt="image" src="https://github.com/user-attachments/assets/c49e36d5-91ae-448d-9793-81face28931b" />
<img width="815" height="755" alt="image" src="https://github.com/user-attachments/assets/40ed8f64-f973-4270-90da-961c7c95c935" />




## Kesimpulan
Doubly Linked List menawarkan kemampuan yang lebih unggul dibandingkan Singly Linked List ketika diperlukan akses data dari dua arah, walaupun konsekuensinya adalah penggunaan memori yang lebih besar akibat adanya pointer tambahan. Struktur data ini sangat cocok digunakan pada aplikasi yang sering melakukan operasi penyisipan dan penghapusan elemen di berbagai posisi dalam list.

## Referensi
Mukharil Bachtiar, A. (2012). And 4-Dynamic Array And Linked List (pelengkap).
