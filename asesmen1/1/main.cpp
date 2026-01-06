#include <iostream>
#include "Soal1.h"
using namespace std;

int main() {
    int pilihan;
    string nama;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Nama\n";
        cout << "2. Delete Nama\n";
        cout << "3. View List\n";
        cout << "4. Hitung Nama Huruf Genap\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, nama);
                insertAkhir(nama);
                break;
            case 2:
                cout << "Masukkan nama yang ingin dihapus: ";
                getline(cin, nama);
                deleteNama(nama);
                break;
            case 3:
                viewList();
                break;
            case 4:
                hitungGenap();
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
