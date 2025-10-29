#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "=== OUTPUT LIST ===" << endl;
    printInfo(L);
    cout << endl;

    cout << "=== PENCARIAN ELEMEN 8 ===" << endl;
    address hasil = findElm(L, 8);
    if (hasil != Nil) {
        cout << "Elemen dengan info 8 ditemukan pada alamat: " << hasil << endl;
    } else {
        cout << "Elemen dengan info 8 tidak ditemukan!" << endl;
    }
    cout << endl;

    cout << "=== JUMLAH TOTAL INFO ===" << endl;
    cout << "Total = " << sumInfo(L) << endl;

    return 0;
}
