#include <iostream>
#include "Soal1.h"
using namespace std;

Node* head = NULL;

// Insert nama di akhir list
void insertAkhir(string nama) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Nama berhasil ditambahkan\n";
}

// Delete nama pertama ditemukan (case-sensitive)
void deleteNama(string nama) {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }

    if (head->nama == nama) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Nama berhasil dihapus\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->nama != nama) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Nama tidak ditemukan\n";
    } else {
        Node* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
        cout << "Nama berhasil dihapus\n";
    }
}

// View seluruh list
void viewList() {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Hitung nama dengan jumlah huruf genap
void hitungGenap() {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node* temp = head;
    bool ada = false;

    cout << "Nama dengan jumlah huruf genap:\n";
    while (temp != NULL) {
        if (temp->nama.length() % 2 == 0) {
            cout << "- " << temp->nama << endl;
            ada = true;
        }
        temp = temp->next;
    }

    if (!ada) {
        cout << "Tidak ada\n";
    }
}
