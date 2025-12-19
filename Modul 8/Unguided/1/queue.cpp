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
