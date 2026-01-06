#include "StackMahasiswa.h"

void createStack(StackMahasiswa &StackMHS) {
    StackMHS.Top = -1; // [cite: 184]
}

bool isEmpty(StackMahasiswa StackMHS) {
    return StackMHS.Top == -1;
}

bool isFull(StackMahasiswa StackMHS) {
    return StackMHS.Top == MAX - 1;
}

void Push(StackMahasiswa &StackMHS, Mahasiswa M) {
    if (!isFull(StackMHS)) {
        StackMHS.Top++;
        StackMHS.dataMahasiswa[StackMHS.Top] = M;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

void Pop(StackMahasiswa &StackMHS) {
    if (!isEmpty(StackMHS)) {
        StackMHS.Top--; // [cite: 186]
    } else {
        cout << "Stack Kosong!" << endl;
    }
}

void Update(StackMahasiswa &StackMHS, int posisi) {
    int idx = posisi - 1; // [cite: 187]
    if (idx >= 0 && idx <= StackMHS.Top) {
        cout << "Update Data ke-" << posisi << ":" << endl;
        cout << "Nama: "; cin >> StackMHS.dataMahasiswa[idx].Nama;
        cout << "NIM: "; cin >> StackMHS.dataMahasiswa[idx].NIM;
        cout << "Tugas: "; cin >> StackMHS.dataMahasiswa[idx].NilaiTugas;
        cout << "UTS: "; cin >> StackMHS.dataMahasiswa[idx].NilaiUTS;
        cout << "UAS: "; cin >> StackMHS.dataMahasiswa[idx].NilaiUAS;
    }
}

void View(StackMahasiswa S) {
    for (int i = S.Top; i >= 0; i--) { // LIFO [cite: 188]
        float NA = (0.2 * S.dataMahasiswa[i].NilaiTugas) + (0.4 * S.dataMahasiswa[i].NilaiUTS) + (0.4 * S.dataMahasiswa[i].NilaiUAS);
        cout << i + 1 << ". " << S.dataMahasiswa[i].Nama << " (NA: " << NA << ")" << endl;
    }
}

void SearchNilaiAkhir(StackMahasiswa S, float min, float max) {
    cout << "\nHasil Pencarian NA [" << min << " - " << max << "]:" << endl;
    for (int i = 0; i <= S.Top; i++) {
        float NA = (0.2 * S.dataMahasiswa[i].NilaiTugas) + (0.4 * S.dataMahasiswa[i].NilaiUTS) + (0.4 * S.dataMahasiswa[i].NilaiUAS); // [cite: 236]
        if (NA >= min && NA <= max) {
            cout << "Posisi " << i + 1 << ": " << S.dataMahasiswa[i].Nama << endl;
        }
    }
}

void MaxNilaiAkhir(StackMahasiswa S) {
    if (isEmpty(S)) return;
    float maxNA = -1;
    for (int i = 0; i <= S.Top; i++) {
        float NA = (0.2 * S.dataMahasiswa[i].NilaiTugas) + (0.4 * S.dataMahasiswa[i].NilaiUTS) + (0.4 * S.dataMahasiswa[i].NilaiUAS);
        if (NA > maxNA) maxNA = NA;
    }
    cout << "\nMahasiswa dengan NA Tertinggi (" << maxNA << "):" << endl; // [cite: 238]
    for (int i = 0; i <= S.Top; i++) {
        float NA = (0.2 * S.dataMahasiswa[i].NilaiTugas) + (0.4 * S.dataMahasiswa[i].NilaiUTS) + (0.4 * S.dataMahasiswa[i].NilaiUAS);
        if (NA == maxNA) cout << "Posisi " << i + 1 << ": " << S.dataMahasiswa[i].Nama << endl;
    }
}