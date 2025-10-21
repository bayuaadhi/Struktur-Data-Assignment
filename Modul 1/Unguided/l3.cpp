#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output:" << endl;

    for (int i = n; i >= 1; i--) {
        // spasi
        for (int s = n; s > i; s--) {
            cout << " ";
        }
        // angka
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << " ";
        // bintang
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
