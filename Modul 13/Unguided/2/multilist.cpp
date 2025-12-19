#include "multilist.h"

/* ====== CEK KOSONG ====== */
boolean ListEmpty(listinduk L) {
    return L.first == Nil;
}

boolean ListEmptyAnak(listanak L) {
    return L.first == Nil;
}

/* ====== CREATE ====== */
void CreateList(listinduk &L) {
    L.first = Nil;
    L.last = Nil;
}

void CreateListAnak(listanak &L) {
    L.first = Nil;
    L.last = Nil;
}

/* ====== ALOKASI ====== */
address alokasi(infotypeinduk x) {
    address P = new elemen_list_induk;
    P->info = x;
    CreateListAnak(P->lanak);
    P->next = Nil;
    P->prev = Nil;
    return P;
}

address_anak alokasiAnak(infotypeanak x) {
    address_anak P = new elemen_list_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

/* ====== FIND ====== */
address findElm(listinduk L, infotypeinduk x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x)
            return P;
        P = P->next;
    }
    return Nil;
}

address_anak findElm(listanak L, infotypeanak x) {
    address_anak P = L.first;
    while (P != Nil) {
        if (P->info == x)
            return P;
        P = P->next;
    }
    return Nil;
}

/* ====== INSERT INDUK ====== */
void insertFirst(listinduk &L, address P) {
    if (ListEmpty(L)) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (ListEmpty(L)) {
        insertFirst(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

/* ====== INSERT ANAK ====== */
void insertLastAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

/* ====== DELETE ANAK ====== */
void delPAnak(listanak &L, infotypeanak x) {
    address_anak P = findElm(L, x);
    if (P != Nil) {
        if (P == L.first) {
            L.first = P->next;
            if (L.first != Nil)
                L.first->prev = Nil;
            else
                L.last = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            L.last->next = Nil;
        } else {
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }
        dealokasiAnak(P);
    }
}

/* ====== DELETE INDUK (HAPUS SEMUA ANAK) ====== */
void delP(listinduk &L, infotypeinduk x) {
    address P = findElm(L, x);
    if (P != Nil) {
        address_anak A = P->lanak.first;
        while (A != Nil) {
            address_anak tmp = A;
            A = A->next;
            dealokasiAnak(tmp);
        }

        if (P == L.first) {
            L.first = P->next;
            if (L.first != Nil)
                L.first->prev = Nil;
            else
                L.last = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            L.last->next = Nil;
        } else {
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }
        dealokasi(P);
    }
}

/* ====== PRINT ====== */
void printInfo(listinduk L) {
    address P = L.first;
    while (P != Nil) {
        cout << "Induk " << P->info << " : ";
        address_anak A = P->lanak.first;
        while (A != Nil) {
            cout << A->info << " ";
            A = A->next;
        }
        cout << endl;
        P = P->next;
    }
}
