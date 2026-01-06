#include <iostream>
#include "Soal2.h"
using namespace std;

int main() {
    int pilihan, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete Last\n";
        cout << "3. View Depan\n";
        cout << "4. Reverse & View Depan\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> data;
                insertAkhir(data);
                break;
            case 2:
                deleteLast();
                break;
            case 3:
                viewDepan();
                break;
            case 4:
                reverseList();
                viewDepan();
                break;
            case 0:
                cout << "Program selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 0);

    return 0;
}
