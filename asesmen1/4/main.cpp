#include "QueuePengiriman.cpp"

int main() {
    QueueEkspedisi Q;
    createQueue(Q); // [cite: 267]
    int choice;

    do {
        cout << "\nKomaniya Ekspress" << endl; // [cite: 269-273]
        cout << "1. Input Data Paket" << endl;
        cout << "2. Hapus Data Paket" << endl;
        cout << "3. Tampilkan Queue Paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl; // [cite: 298]
        cout << "0. Keluar" << endl;
        cout << "Pilihan anda: "; cin >> choice;

        if (choice == 1) { // [cite: 274-292]
            Paket P;
            cout << "Kode Resi: "; cin >> P.KodeResi;
            cout << "Pengirim: "; cin >> P.NamaPengirim;
            cout << "Berat (kg): "; cin >> P.BeratBarang;
            cout << "Tujuan: "; cin >> P.Tujuan;
            enQueue(Q, P);
        } else if (choice == 2) {
            deQueue(Q); // [cite: 294]
        } else if (choice == 3) {
            viewQueue(Q); // [cite: 293, 295]
        } else if (choice == 4) {
            cout << "Total Biaya: Rp. " << TotalBiayaPengiriman(Q) << endl; // [cite: 298]
        }
    } while (choice != 0);

    return 0;
}