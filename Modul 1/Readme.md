# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Bayu Adhi Nugroho</p>

## Dasar Teori

C++ adalah bahasa hasil pengembangan dari C dengan kemampuan prosedural dan berorientasi objek.



## Guided 

### 1. Modul Codeblocks IDE & Pengenalan Bahas C++ (1)


```C++
#include <iostream>

using namespace std;

int main () {
    // array 1 dimensi
    int arrID[5] = {10,20,30,40,50};
    cout << "Array 1 Dimensi" << endl;
    for (int i=0; i<5; i++) {
        cout << "arrID" << i << " = " << arrID[i] << endl; 
        
    }
    cout << endl;

    // array 2 dimensi baris & kolom
    int arr2D[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    cout << "Array 2 Dimensi" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            cout << "arr2D[" << i << "}[" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //array multi dimensi (3D)
    int arr3D[2][2][3] = {
    { { 1, 2, 3 }, {4, 5, 6} },
    { { 7, 8, 9} , {10, 11, 12} }   
    };
    cout << "array 3 dimensi" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
Kode di atas digunakan untuk menampilkan isi array 1 dimensi, 2 dimensi, dan 3 dimensi ke layar. Setiap elemen array dicetak menggunakan perulangan for dan ditampilkan dengan cout agar hasilnya muncul di layar.


## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian  : " << a * b << endl;
    if (b != 0)
        cout << "Pembagian  : " << a / b << endl;
    else
        cout << "Pembagian  : Error (pembagi nol)" << endl;

    return 0;
}
```
#### Output:
<img width="1297" height="215" alt="image" src="https://github.com/user-attachments/assets/362b4a46-ff8a-4a7f-925f-7070ed9de553" />



Kode di atas digunakan untuk menghitung dan menampilkan hasil operasi aritmatika dua angka yang dimasukkan pengguna. Nilai dimasukkan melalui cin, lalu hasil penjumlahan, pengurangan, perkalian, dan pembagian ditampilkan dengan cout.


#### Full code Screenshot:
<img width="929" height="671" alt="image" src="https://github.com/user-attachments/assets/5d98ed8f-4501-4c66-bf19-141dcaaa0d42" />



### 2. [Soal]

```C++
#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas",
                    "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh",
                    "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

string terjemah(int n) {
    if (n == 0) return "nol";
    if (n == 100) return "seratus";
    if (n < 10) return satuan[n];
    if (n < 20) return belasan[n - 10];
    if (n < 100) {
        int p = n / 10;
        int s = n % 10;
        if (s == 0) return puluhan[p];
        else return puluhan[p] + " " + satuan[s];
    }
    return "";
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else {
        cout << angka << " : " << terjemah(angka) << endl;
    }
    return 0;
}
```
#### Output:
<img width="1344" height="129" alt="image" src="https://github.com/user-attachments/assets/cc2c4ce6-6ff7-4c28-8486-538895f2f7ee" />


Kode di atas digunakan untuk mengubah angka yang dimasukkan pengguna menjadi tulisan dalam bahasa Indonesia menggunakan fungsi ubahTulisan(). Hasil konversinya kemudian ditampilkan ke layar dengan perintah cout.

#### Full code Screenshot:
<img width="1355" height="694" alt="image" src="https://github.com/user-attachments/assets/3b9790c2-5a36-4ff8-8503-824d0e562251" />
<img width="1161" height="465" alt="image" src="https://github.com/user-attachments/assets/8349b2e1-09ab-4e0a-b0cd-9d5c1a5f0bce" />



### 3. [Soal]

```C++
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
```
#### Output:
<img width="1352" height="254" alt="image" src="https://github.com/user-attachments/assets/18666b77-678c-425d-81db-81b30078d487" />


Kode ini membuat pola cermin angka dengan pusat bintang.
Bagian kiri menurun, bagian kanan menaik, dan bentuknya simetris secara vertikal.

#### Full code Screenshot:
<img width="1408" height="943" alt="image" src="https://github.com/user-attachments/assets/6b5e401d-61b6-40ac-9274-f2b7f7317099" />


## Kesimpulan
Program ini memperkuat pemahaman tentang perulangan bersarang, logika pengaturan posisi (spasi), dan pola output visual di layar.

## Referensi
https://elektro.um.ac.id/wp-content/uploads/2016/05/MODUL-6-ARRAY-DPK-2016.pdf
