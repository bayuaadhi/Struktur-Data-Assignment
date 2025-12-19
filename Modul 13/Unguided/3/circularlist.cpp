#include "circularlist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        P->next = P;
    } else {
        address Q = L.First;
        while (Q->next != L.First)
            Q = Q->next;
        P->next = L.First;
        Q->next = P;
        L.First = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    P->next = Prec->next;
    Prec->next = P;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        insertFirst(L, P);
    } else {
        address Q = L.First;
        while (Q->next != L.First)
            Q = Q->next;
        Q->next = P;
        P->next = L.First;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        address Q = L.First;
        while (Q->next != L.First)
            Q = Q->next;

        P = L.First;
        if (P->next == P) {
            L.First = Nil;
        } else {
            L.First = P->next;
            Q->next = L.First;
        }
        P->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.First != Nil) {
        address Q = L.First;
        address Prec = Nil;
        while (Q->next != L.First) {
            Prec = Q;
            Q = Q->next;
        }
        P = Q;
        if (Prec == Nil) {
            L.First = Nil;
        } else {
            Prec->next = L.First;
        }
        P->next = Nil;
    }
}

address findElm(List L, infotype x) {
    if (L.First == Nil) return Nil;

    address P = L.First;
    do {
        if (P->info.nim == x.nim)
            return P;
        P = P->next;
    } while (P != L.First);

    return Nil;
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong\n";
        return;
    }

    address P = L.First;
    do {
        cout << P->info.nama << " | "
             << P->info.nim << " | "
             << P->info.jenis_kelamin << " | "
             << P->info.ipk << endl;
        P = P->next;
    } while (P != L.First);
}
