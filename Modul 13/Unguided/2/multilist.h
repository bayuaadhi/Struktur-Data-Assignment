#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL
typedef bool boolean;

/* ====== TYPE ====== */
typedef int infotypeinduk;
typedef int infotypeanak;

typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

/* ====== LIST ANAK (DOUBLY) ====== */
struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak {
    address_anak first;
    address_anak last;
};

/* ====== LIST INDUK (DOUBLY) ====== */
struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak;
    address next;
    address prev;
};

struct listinduk {
    address first;
    address last;
};

/* ====== PRIMITIF ====== */
boolean ListEmpty(listinduk L);
boolean ListEmptyAnak(listanak L);

void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

/* ====== ALOKASI ====== */
address alokasi(infotypeinduk x);
address_anak alokasiAnak(infotypeanak x);
void dealokasi(address P);
void dealokasiAnak(address_anak P);

/* ====== FIND ====== */
address findElm(listinduk L, infotypeinduk x);
address_anak findElm(listanak L, infotypeanak x);

/* ====== INSERT ====== */
void insertFirst(listinduk &L, address P);
void insertLast(listinduk &L, address P);
void insertLastAnak(listanak &L, address_anak P);

/* ====== DELETE ====== */
void delPAnak(listanak &L, infotypeanak x);
void delP(listinduk &L, infotypeinduk x);

/* ====== PRINT ====== */
void printInfo(listinduk L);

#endif
