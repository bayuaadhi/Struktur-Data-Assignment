//header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct buah
struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias dataBuah untuk struct buah

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata; //disamakan dengan di list.cpp
    address next;
};

struct linkedlist { 
    address first;
};

//Semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);

// ✅ diperbaiki parameternya agar sesuai dengan struct buah
address alokasi(string nama, int jumlah, float harga);

void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address Prev);
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif