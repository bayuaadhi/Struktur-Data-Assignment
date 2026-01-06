#ifndef SOAL2_H
#define SOAL2_H

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAkhir(int data);
void deleteLast();
void viewDepan();
void reverseList();

#endif
