#ifndef SOAL1_H
#define SOAL1_H

#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

void insertAkhir(string nama);
void deleteNama(string nama);
void viewList();
void hitungGenap();

#endif
