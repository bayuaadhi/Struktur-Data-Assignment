#include "Doublylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
        return;
    }

    while (P != Nil) {
        cout << P->info.nopol << " | "
             << P->info.warna << " | "
             << P->info.thnBuat << endl;
        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }
    P = L.first;
    if (L.first == L.last) { // satu elemen
        L.first = L.last = Nil;
    } else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }
    P = L.last;
    if (L.first == L.last) {
        L.first = L.last = Nil;
    } else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}

void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }

    P = Prec->next;
    Prec->next = P->next;

    if (P->next != Nil)
        P->next->prev = Prec;

    P->next = Nil;
    P->prev = Nil;
}
