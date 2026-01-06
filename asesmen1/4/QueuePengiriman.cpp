#include "QueuePengiriman.h"

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1; // [cite: 261]
}

bool isEmpty(QueueEkspedisi Q) {
    return Q.Head == -1;
}

bool isFull(QueueEkspedisi Q) {
    return Q.Tail == MAX_Q - 1;
}

void enQueue(QueueEkspedisi &Q, Paket P) {
    if (!isFull(Q)) {
        if (isEmpty(Q)) Q.Head = 0;
        Q.Tail++;
        Q.dataPaket[Q.Tail] = P;
    } else {
        cout << "Queue Penuh!" << endl;
    }
}

void deQueue(QueueEkspedisi &Q) { // Implementasi 1: Head diam 
    if (!isEmpty(Q)) {
        for (int i = 0; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        Q.Tail--;
        if (Q.Tail == -1) Q.Head = -1;
    } else {
        cout << "Queue Kosong!" << endl;
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Antrian Kosong" << endl;
        return;
    }
    for (int i = Q.Head; i <= Q.Tail; i++) { // [cite: 263]
        cout << i + 1 << ". [" << Q.dataPaket[i].KodeResi << "] " << Q.dataPaket[i].NamaPengirim << " - " << Q.dataPaket[i].Tujuan << endl;
    }
}

float TotalBiayaPengiriman(QueueEkspedisi Q) {
    float total = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        total += Q.dataPaket[i].BeratBarang * 8250; // [cite: 297]
    }
    return total;
}