# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Bayu Adhi Nugroho</p>

## Dasar Teori

Bahasa C++ merupakan pengembangan dari bahasa C yang mendukung pemrograman prosedural maupun berorientasi objek. Penulisan program dilakukan menggunakan Code::Blocks dengan struktur dasar berupa header, fungsi main(), serta penggunaan cin dan cout untuk proses input dan output



## Guided 

### 1. MODUL PENGENALAN BAHASA C++ BAGIAN 2


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
Kode tersebut berfungsi untuk menampilkan data dari array satu, dua, hingga tiga dimensi. Proses penampilannya dilakukan dengan menggunakan perulangan for untuk mengakses setiap elemen, kemudian hasilnya dicetak ke layar melalui cout.


## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    int i, j, k;

    cout << "Masukkan elemen matriks A (3x3):\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Masukkan elemen matriks B (3x3):\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }

    cout << "\nPenjumlahan :\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPengurangan :\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPerkalian :\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = 0;
            for(k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
#### Output:

<img width="1031" height="531" alt="image" src="https://github.com/user-attachments/assets/0f7fd6de-61f8-46fd-be38-7bd763a05475" />
<img width="387" height="380" alt="image" src="https://github.com/user-attachments/assets/4764f49d-6055-4de7-8bff-f50c6d2944f8" />


Program tersebut digunakan untuk mengolah dua buah matriks berukuran 3×3. Pengguna diminta menginput elemen matriks A dan B serta menentukan jenis operasi yang diinginkan, yaitu penjumlahan, pengurangan, atau perkalian. Setelah proses perhitungan dilakukan, hasilnya ditampilkan ke layar menggunakan cout



#### Full code Screenshot:
<img width="1547" height="842" alt="image" src="https://github.com/user-attachments/assets/6dd6413e-24e9-4e54-ba50-cb6aedb19076" />
<img width="1227" height="718" alt="image" src="https://github.com/user-attachments/assets/01d49129-843f-40cd-b641-e187893f1873" />



### 2. [Soal]

```C++
#include <iostream>
using namespace std;

void tukar3(int &x, int &y, int &z) {
    int temp = x;  
    x = y;         
    y = z;          
    z = temp;      
}

int main() {
    int a = 20, b = 30, c = 40;
    int& ref = a; 

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat a (&a) : " << &a << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;

    ref = 50;
    cout << "\nSetelah ref = 50:" << endl;
    cout << "a = " << a << ", ref = " << ref << endl;

    tukar3(a, b, c);

    cout << "\nSetelah tukar3 dipanggil:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
```
#### Output:
<img width="1368" height="342" alt="image" src="https://github.com/user-attachments/assets/f034fa97-0abd-46da-888e-71b0c3201f28" />

Program ini melakukan pertukaran nilai pada tiga variabel secara bergantian dengan memanfaatkan konsep referensi. Nilai awal setiap variabel ditampilkan terlebih dahulu, kemudian fungsi tukarReference mengalihkan nilai dari x ke y, y ke z, dan z kembali ke x, setelah itu hasil akhirnya ditampilkan ke layar.

#### Full code Screenshot:
<img width="1366" height="846" alt="image" src="https://github.com/user-attachments/assets/4e7eb78b-11d1-42d9-a94d-fcc9ebb641c2" />


### 3. [Soal]

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

float hitungRataRata(int arr[], int n) {
    int jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += arr[i];
    }
    return (float)jumlah / n; 
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = 10;
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata - rata\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
             case 1:
                cout << "ARRAY = {";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i];
                    if (i < n - 1) cout << ", ";
                }
                cout << "}" << endl;
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                cout << "Nilai rata-rata: " << hitungRataRata(arrA, n) << endl;
                break;
            default:
                cout << "-";
        }
    } while (pilihan != 5);

    return 0;
}
```
#### Output:
<img width="971" height="823" alt="image" src="https://github.com/user-attachments/assets/8bb3fca9-a35a-4d59-bc55-9eb34a5e1bdb" />


Kode ini menyediakan menu interaktif untuk mengolah sebuah array: tampilkan isi, cari maksimum, minimum, atau hitung rata-rata.
Setiap operasi dikerjakan oleh fungsi terpisah, dan program berulang sampai pengguna memilih keluar.

#### Full code Screenshot:
<img width="1532" height="871" alt="image" src="https://github.com/user-attachments/assets/b19d65c4-cfea-4d83-8702-97821e9217f3" />
<img width="1417" height="781" alt="image" src="https://github.com/user-attachments/assets/b743281d-8b6c-4c6a-adc0-a30fda139340" />
<img width="1369" height="537" alt="image" src="https://github.com/user-attachments/assets/ed5aad0a-9585-483c-acb3-de8a27756e67" />



## Kesimpulan
Program ini menampilkan menu interaktif yang memungkinkan pengguna mengelola sebuah array, seperti menampilkan data, menentukan nilai maksimum dan minimum, serta menghitung nilai rata-ratanya. Setiap pilihan diproses melalui fungsi yang berbeda, dan program akan terus berjalan hingga pengguna memilih opsi keluar.

## Referensi
https://www.academia.edu/35362129/Pemograman_C_Bab_12_Array_pdf













