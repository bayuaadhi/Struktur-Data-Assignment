#include "StackMahasiswa.cpp"

int main() {
    StackMahasiswa S;
    createStack(S); // [cite: 191]

    // Push data [cite: 192-223]
    Push(S, {"Venti", "11111", 75.7, 82.1, 65.5});
    Push(S, {"Xiao", "22222", 87.4, 88.9, 81.9});
    Push(S, {"Kazuha", "33333", 92.3, 88.8, 82.4});
    Push(S, {"Wanderer", "44444", 95.5, 85.5, 90.5});
    Push(S, {"Lynette", "55555", 77.7, 65.4, 79.9});
    Push(S, {"Chasca", "66666", 99.9, 93.6, 87.3});

    cout << "--- Tampilan Awal Stack ---" << endl;
    View(S); // [cite: 224]

    Pop(S); // [cite: 225]
    cout << "\n--- Setelah Pop ---" << endl;
    View(S); // [cite: 226]

    Update(S, 3); // [cite: 227-232]
    cout << "\n--- Setelah Update Posisi 3 ---" << endl;
    View(S);

    SearchNilaiAkhir(S, 85.5, 95.5); // [cite: 234]
    MaxNilaiAkhir(S); // [cite: 239]

    return 0;
}