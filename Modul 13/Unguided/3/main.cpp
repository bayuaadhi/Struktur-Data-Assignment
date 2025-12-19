#include "circularlist.h"

address createData(string nama, string nim, char jenis_kelamin, float ipk)
{
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}

int main() {
    List L;
    address P1, P2;
    infotype x;

    CreateList(L);

    cout << "coba insert first, last, dan after\n";

    insertFirst(L, createData("Danu", "04", 'l', 4.0));
    insertLast(L, createData("Fahmi", "06", 'l', 3.45));
    insertFirst(L, createData("Bobi", "02", 'l', 3.71));
    insertFirst(L, createData("Ali", "01", 'l', 3.3));
    insertLast(L, createData("Gita", "07", 'p', 3.75));

    x.nim = "07";
    P1 = findElm(L, x);
    insertAfter(L, P1, createData("Cindi", "03", 'p', 3.5));

    x.nim = "02";
    P1 = findElm(L, x);
    insertAfter(L, P1, createData("Hilmi", "08", 'p', 3.3));

    x.nim = "04";
    P1 = findElm(L, x);
    insertAfter(L, P1, createData("Eli", "05", 'p', 3.4));

    printInfo(L);
    return 0;
}
