#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    listinduk L;
    CreateList(L);

    // ===== INSERT INDUK =====
    address p1 = alokasi(1);
    address p2 = alokasi(2);
    address p3 = alokasi(3);

    insertLast(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    // ===== INSERT ANAK =====
    insertLastAnak(p1->lanak, alokasiAnak(10));
    insertLastAnak(p1->lanak, alokasiAnak(11));
    insertLastAnak(p2->lanak, alokasiAnak(20));
    insertLastAnak(p2->lanak, alokasiAnak(21));
    insertLastAnak(p3->lanak, alokasiAnak(30));

    cout << "=== DATA AWAL ===\n";
    printInfo(L);

    // ===== DELETE ANAK =====
    cout << "\nHapus anak 11 dari induk 1\n";
    delPAnak(p1->lanak, 11);
    printInfo(L);

    // ===== DELETE INDUK =====
    cout << "\nHapus induk 2 (anak ikut terhapus)\n";
    delP(L, 2);
    printInfo(L);

    return 0;
}
