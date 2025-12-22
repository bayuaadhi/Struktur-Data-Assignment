# <h1 align="center">STACK</h1>
<p align="center">Bayu Adhi Nugroho</p>

## Dasar Teori
Stack adalah struktur data dengan konsep LIFO, yaitu elemen terakhir masuk akan keluar lebih dulu.
    
## Guided 

### 1. [Nama Topik]
**stack.h**
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong

};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```
**stak.cpp**
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX -1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack Penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " Berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    //index = top - (posisi -1)
    int idx = s.top - (posisi -1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " Tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
        return;
    }
    cout << "Mencari data" << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```
**main.cpp**
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    //Posisi dihitung dari TOP(1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
Stack diimplementasikan menggunakan array, mencakup operasi dasar push dan pop, serta fungsi tambahan untuk memperbarui dan mencari data.

## Unguided 

### 1. [Soal]
**stack.h**
```C++
#ifndef STACK_H
#define STACK_H

#define MAX 50

struct Stack {
    int top;
    int data[MAX];
};

// Membuat stack kosong
void createStack(Stack &S);

// Mengecek apakah stack kosong
bool isEmpty(Stack S);

// Mengecek apakah stack penuh
bool isFull(Stack S);

// Menambah elemen (push)
void push(Stack &S, int x);

// Menghapus elemen (pop)
int pop(Stack &S);

// Mencetak isi stack
void printStack(Stack S);

#endif
```
**stack.cpp**
```C++
#include "Stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, int x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = x;
    }
}

int pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int x = S.data[S.top];
        S.top--;
        return x;
    }
}

void printStack(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Isi stack: ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}
```
**main.cpp**
```C++
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    push(S, 10);
    push(S, 20);
    push(S, 30);

    cout << "Setelah push 3 data:" << endl;
    printStack(S);

    cout << "Pop: " << pop(S) << endl;

    cout << "Setelah pop 1 data:" << endl;
    printStack(S);

    return 0;
}
```
#### Output:
<img width="673" height="108" alt="image" src="https://github.com/user-attachments/assets/42b7b1ca-d70d-4bbe-896b-c8deac0e5b59" />



Program membuat sebuah stack berisi angka 4729601. Isi stack ditampilkan dari atas ke bawah, lalu dibalik dengan bantuan stack sementara, sehingga urutannya berubah dan hasil akhir ditampilkan kembali.

#### Full code Screenshot:
<img width="656" height="475" alt="image" src="https://github.com/user-attachments/assets/6a9caca8-0876-4dc8-95e5-611e1a8b580e" />
<img width="648" height="843" alt="image" src="https://github.com/user-attachments/assets/0bcfb047-6190-47a7-8024-f9dd30d6bd7f" />
<img width="527" height="573" alt="image" src="https://github.com/user-attachments/assets/cdf81fd3-1485-4801-a1a3-5cc6249c9ec7" />


## Kesimpulan
Stack menggunakan prinsip LIFO, elemen terakhir masuk keluar lebih dulu. Percobaan push, pop, tampilkan, dan balik urutan berhasil, sehingga saya lebih memahami cara kerja stack.

## Referensi
https://sisfo.itp.ac.id/bahanajar/BahanAjar/Anisya/Modul%203%20-%20Tumpukan.pdf
