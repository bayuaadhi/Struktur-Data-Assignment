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
