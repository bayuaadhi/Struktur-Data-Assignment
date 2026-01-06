#include <iostream>
#include "Soal2.h"
using namespace std;

Node* head = NULL;
Node* tail = NULL;

// Insert di akhir list
void insertAkhir(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Data berhasil ditambahkan\n";
}

// Delete node terakhir
void deleteLast() {
    if (tail == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node* hapus = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete hapus;
    cout << "Data terakhir berhasil dihapus\n";
}

// View dari depan ke belakang
void viewDepan() {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Reverse list tanpa membuat node baru
void reverseList() {
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        temp = head;
        head = tail;
        tail = temp;
    }

    cout << "List berhasil di-reverse\n";
}
