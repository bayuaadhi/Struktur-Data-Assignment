#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    createList(L);

    // insert data
    insertLast(L, alokasi({"D001", "Hitam", 2010}));
    insertLast(L, alokasi({"D002", "Merah", 2015}));
    insertLast(L, alokasi({"D003", "Putih", 2012}));
    insertLast(L, alokasi({"D004", "Biru", 2018}));

    cout << "Data Kendaraan:" << endl;
    printInfo(L);

    cout << "\nCari Nopol D001:" << endl;
    address P = findElm(L, "D001");
    if (P != Nil) {
        cout << "Ditemukan: " << P->info.nopol << ", " << P->info.warna 
             << ", " << P->info.thnBuat << endl;
    } else {
        cout << "Tidak ditemukan" << endl;
    }

    cout << "\nHapus D003:" << endl;
    address del;
    address Prec = L.first;
    while (Prec != Nil && Prec->next != Nil && Prec->next->info.nopol != "D003")
        Prec = Prec->next;

    if (Prec != Nil && Prec->next->info.nopol == "D003") {
        deleteAfter(Prec, del);
        dealokasi(del);
    }

    printInfo(L);

    return 0;
}
