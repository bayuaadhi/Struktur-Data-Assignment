# <h1 align="center">Modul 8 QUEUE</h1>
<p align="center">Bayu Adhi Nugroho</p>

## Dasar Teori
Queue adalah struktur data yang meniru sistem antrean dengan aturan FIFO, sehingga data yang pertama kali dimasukkan akan dikeluarkan lebih dulu. Dalam praktikum ini, queue direalisasikan menggunakan linked list, di mana proses enqueue dilakukan di bagian belakang dan dequeue dilakukan di bagian depan.

## Guided 

### 1. [Nama Topik]

```C++
// guided 1 queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#n

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.hemad; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}

// guided 1 main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}

// guided2 queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1 
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif

// guided2 queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

// //isFull implmenetasi 1 & 2
// bool isFull(queue Q){
//     if(Q.tail == MAKSIMAL - 1){
//         return true;
//     } else {
//         return false;
//     }
// }

//isFull implementasi 3
bool isFull(queue Q){
    if((Q.tail + 1) % MAKSIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 
// //enqueue implementasi 1 & 2
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail++;
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//enQueue implementasi 3
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //dequeue implementasi 1
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         for(int i = 0; i < Q.tail; i++){
//             Q.nama[i] =  Q.nama[i+1];
//         }
//         Q.tail--;
//         if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

//deQueue implementasi 3
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
        }
    }
}

// //viewQueue implementasi 1 & 2
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         for(int i = Q.head; i <= Q.tail; i++){
//             cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
//         }
//     }
//     cout << endl;
// }

//viewQueue implementasi 3
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << count << ". " << Q.nama[i] << endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAKSIMAL;
            count++;
        }   
    }
}

// guided2 main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
//
```
Program ini memperlihatkan mekanisme kerja struktur data antrian (queue), yaitu data yang pertama kali dimasukkan akan dikeluarkan terlebih dahulu. Contoh yang digunakan berupa data nama, yang dimasukkan ke dalam antrian, dikeluarkan, kemudian ditampilkan kembali isi antrian yang tersisa.

## Unguided 

### 1. [Soal]

**queue.h**
```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;   // kapasitas queue

typedef int infotype;

struct Queue {
    infotype info[MAX]; 
    int head;
    int tail;
};

// PROTOTYPE
void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
**queue.cpp**
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return Q.tail < Q.head;
}

bool isFullQueue(Queue Q){
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh, tidak bisa enqueue!\n";
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong, tidak bisa dequeue!\n";
        return -999; 
    } else {
        infotype x = Q.info[Q.head];

        // geser semua elemen ke kiri
        for(int i = Q.head; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }

        Q.tail--;  
        return x;
    }
}

void printInfo(Queue Q){
    cout << "H = " << Q.head << " | T = " << Q.tail << "\t | Queue: ";
    if(isEmptyQueue(Q)){
        cout << " (kosong)\n";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```
**main.cpp**
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {

    Queue Q;
    createQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    dequeue(Q);  printInfo(Q);

    return 0;
}
```
#### Output:
<img width="623" height="313" alt="image" src="https://github.com/user-attachments/assets/2a080545-64a4-4869-957d-74587e3f3ece" />

#### Full code Screenshot:
<img width="698" height="687" alt="image" src="https://github.com/user-attachments/assets/2afa7912-4bfe-4d72-9f3b-569d6b114e8a" />
<img width="816" height="835" alt="image" src="https://github.com/user-attachments/assets/a768dc5b-d456-4c02-9aec-0952c5f3ff01" />
<img width="522" height="487" alt="image" src="https://github.com/user-attachments/assets/2f99c4b4-2d10-4716-949b-76acf3727b8b" />

### 2. [Soal]

**queue.h**
```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
**queue.cpp**
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return Q.head == -1;
}

bool isFullQueue(Queue Q){
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh (penuh semu mungkin terjadi)!\n";
        return;
    }

    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong!\n";
        return -999;
    }

    infotype x = Q.info[Q.head];

    if(Q.head == Q.tail){
        // queue menjadi kosong
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }

    return x;
}

void printInfo(Queue Q){
    cout << "H = " << Q.head << " | T = " << Q.tail << "\t | Queue: ";

    if(isEmptyQueue(Q)){
        cout << "(kosong)\n";
        return;
    }

    for(int i = Q.head; i <= Q.tail; i++){
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
```
**main.cpp**
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    dequeue(Q);  printInfo(Q);

    return 0;
}
```
#### Output:
<img width="530" height="308" alt="image" src="https://github.com/user-attachments/assets/72bf2dd5-14ae-45f7-b8f7-764354dc5202" />


#### Full code Screenshot:

<img width="603" height="868" alt="image" src="https://github.com/user-attachments/assets/8469c59c-4c77-4b8c-ab12-e904ab42ef1d" />

<img width="513" height="349" alt="image" src="https://github.com/user-attachments/assets/4cd394a8-d13a-4982-b4a8-ae1dba474417" />

<img width="488" height="510" alt="image" src="https://github.com/user-attachments/assets/b6f4a754-64a3-4428-b793-1f9cc191f9ce" />

### 3. [Soal]

**queue.h**
```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```
**queue.cpp**
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return Q.head == -1;
}

bool isFullQueue(Queue Q){
    return ( (Q.tail + 1) % MAX ) == Q.head;
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh!\n";
        return;
    }

    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong!\n";
        return -999;
    }

    infotype x = Q.info[Q.head];

    if(Q.head == Q.tail){
        // queue menjadi kosong
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(Queue Q){
    cout << "H = " << Q.head << " | T = " << Q.tail << "\t | Queue: ";

    if(isEmptyQueue(Q)){
        cout << "(kosong)\n";
        return;
    }

    int i = Q.head;
    while(true){
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

```
**main.cpp**
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    dequeue(Q);  printInfo(Q);

    return 0;
}

```
#### Output:

<img width="492" height="195" alt="image" src="https://github.com/user-attachments/assets/dfaa216c-b463-47d9-bfd2-b0697002ecef" />


#### Full code Screenshot:

<img width="335" height="358" alt="image" src="https://github.com/user-attachments/assets/dfc47018-c7da-4a1a-b63b-87bb7da3e9ca" />

<img width="551" height="866" alt="image" src="https://github.com/user-attachments/assets/52a48b93-a6bb-4f36-8700-4612b5a5e62d" />

<img width="408" height="419" alt="image" src="https://github.com/user-attachments/assets/06ecabf7-c2aa-4a5c-a852-ae4e6ac473f2" />




## Kesimpulan
Queue dapat diterapkan dengan mempertahankan head pada indeks 0, sementara tail bergerak ke posisi belakang. Setiap proses dequeue akan menggeser elemen ke kiri, sehingga susunan data tetap teratur dan selalu mengikuti prinsip First In First Out (FIFO)..

## Referensi
[1] Dicoding Team. (2024, 15 Maret). Mengenal Struktur Data Queue: Konsep FIFO dan Implementasinya. Dicoding. https://www.dicoding.com/blog/struktur-data-queue/
[2] Trihandoyo, D. (2013). APLIKASI SIMULASI PEMBELAJARAN STRUKTUR DATA MATERI QUEUE (Doctoral dissertation, Universitas Mercu Buana).

