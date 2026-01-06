#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_Q = 5; // [cite: 253]

struct Paket { // [cite: 248]
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

struct QueueEkspedisi { // [cite: 254]
    Paket dataPaket[MAX_Q];
    int Head;
    int Tail;
};

void createQueue(QueueEkspedisi &Q); // [cite: 261]
bool isEmpty(QueueEkspedisi Q); // [cite: 260]
bool isFull(QueueEkspedisi Q); // [cite: 260]
void enQueue(QueueEkspedisi &Q, Paket P); // [cite: 262]
void deQueue(QueueEkspedisi &Q); // [cite: 263]
void viewQueue(QueueEkspedisi Q); // [cite: 263]
float TotalBiayaPengiriman(QueueEkspedisi Q); // [cite: 297]

#endif