# <h1 align="center">ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Bayu Adhi Nugroho</p>

## Dasar Teori
ADT merupakan suatu tipe data yang disertai dengan sekumpulan operasi dasar (primitif) yang dapat diterapkan pada tipe tersebut. Pada ADT yang lengkap, juga terdapat penjelasan mengenai invarian tipe serta aksioma yang mengatur perilakunya. ADT sendiri bersifat sebagai definisi statik.

## Guided 

### 1. ABSTRACT DATA TYPE (ADT) 

```C++
#include <iostream>
using namespace std;

struct mahasiswa{ 
char nim[10]; 
int nilai1,nilai2;
};
void inputMhs(mahasiswa &m); 
float rata2(mahasiswa m);

int main() 
{ 
mahasiswa mhs; 
inputMhs(mhs); 
cout << “rata-rata = “ << rata2(mhs); 
return 0; 
}


void inputMhs(mahasiswa &m){ 
cout << “input nama = “; 
cin >> m.nim; 
cout << “input nilai = “; 
cin >> m.nilai1; 
cout << “input nilai2 = “;
cin >> m.nilai2; 
} 
float rata2(mahasiswa m){ 
return float(m.nilai1+m.nilai2)/2; 
}

mahasiswa.h
#ifndef MAHASISWA_H_INCLUDED 
#define MAHASISWA_H_INCLUDED 
struct mahasiswa{ 
char nim[10]; 
int nilai1, nilai2; 
};
void inputMhs(mahasiswa &m); 
float rata2(mahasiswa m); 
#endif // MAHASISWA_H_INCLUDED

mahasiswa.cpp
#include “mahasiswa.h” 
void inputMhs(mahasiswa &m){ 
cout << “input nama = “; 
cin >> (m).nim; 
cout << “input nilai = “; 
cin >> (m).nilai1; 
cout << “input nilai2 = “; 
cin >> (m).nilai2;
} 
 
float rata2(mahasiswa m){ 
  return float(m.nilai1+m.nilai2)/2; 
}
}
```
Kode tersebut berfungsi untuk menerima data mahasiswa serta menghitung nilai rata-rata dari dua nilai yang dimasukkan oleh pengguna.

## Unguided 

### 1. [Soal]
```C++
#include <iostream>
using namespace std;

struct mhs{
    string nama,nim;
    float uts,uas,tugas,nilaiAkhir;
};

float hitung(float u,float a,float t){
    return (0.3*u)+(0.4*a)+(0.3*t);
}

int main(){
    mhs M[10];
    int n;
    cout<<"Masukkan jumlah mahasiswa (max 10): ";
    cin>>n;
    if(n>10){
        cout<<"Kebanyakan, max 10 aja\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        cout<<"\nMahasiswa ke-"<<i+1<<endl;
        cout<<"Nama : ";
        cin.ignore();
        getline(cin,M[i].nama);
        cout<<"NIM  : ";
        cin>>M[i].nim;
        cout<<"UTS  : ";
        cin>>M[i].uts;
        cout<<"UAS  : ";
        cin>>M[i].uas;
        cout<<"Tugas: ";
        cin>>M[i].tugas;
        M[i].nilaiAkhir=hitung(M[i].uts,M[i].uas,M[i].tugas);
    }
    cout<<"\nDaftar Nilai Mahasiswa\n";
    cout<<"-----------------------------\n";
    cout<<"No\tNIM\t\tNama\t\tNilAkhir\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<M[i].nim<<"\t\t"<<M[i].nama<<"\t\t"<<M[i].nilaiAkhir<<endl;
    }
    return 0;
}
```
#### Output:
<img width="514" height="625" alt="image" src="https://github.com/user-attachments/assets/7e429509-8a13-4b5d-b542-7aeb36bece1d" />


Kode di atas digunakan untuk menyimpan dan menampilkan data mahasiswa sebanyak maksimal 10 orang.
Program ini menggunakan struct Mahasiswa untuk menyimpan data seperti nama, NIM, nilai UTS, UAS, dan tugas.

#### Full code Screenshot:
<img width="574" height="642" alt="image" src="https://github.com/user-attachments/assets/c9fd079b-5733-4439-ab70-4793f0d4291b" />

 


### 2. [Soal]

**pelajaran.h**
```
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```

**pelajaran.cpp**
```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "=== Data Pelajaran ===" << endl;
    cout << "Nama Mata Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran : " << pel.kodeMapel << endl;
}
```

**main.cpp**
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```
#### Output:
<img width="1496" height="132" alt="image" src="https://github.com/user-attachments/assets/d0b6d4fc-bff4-42ee-b83c-97880d11d38e" />

Kode tersebut berfungsi untuk membuat serta menampilkan data mata pelajaran. Informasi berupa nama dan kode mata pelajaran disimpan menggunakan struktur Pelajaran, kemudian hasilnya ditampilkan ke layar melalui fungsi tampilPelajaran().

#### Full code Screenshot:
<img width="536" height="231" alt="image" src="https://github.com/user-attachments/assets/ead1211b-6369-4637-a03e-5c5b687cd3b4" />
<img width="780" height="307" alt="image" src="https://github.com/user-attachments/assets/cf651c77-1f16-4921-a19c-993408ef9a14" />
<img width="574" height="299" alt="image" src="https://github.com/user-attachments/assets/9a343744-def1-42de-9aa9-80ea3d09f3b0" />





### 3. [Soal]

```C++
#include <iostream>
using namespace std;

struct mhs{
    string nama,nim;
    float uts,uas,tugas,nilaiAkhir;
};

float hitung(float u,float a,float t){
    return (0.3*u)+(0.4*a)+(0.3*t);
}

int main(){
    mhs M[10];
    int n;
    cout<<"Masukkan jumlah mahasiswa (max 10): ";
    cin>>n;
    if(n>10){
        cout<<"Kebanyakan, max 10 aja\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        cout<<"\nMahasiswa ke-"<<i+1<<endl;
        cout<<"Nama : ";
        cin.ignore();
        getline(cin,M[i].nama);
        cout<<"NIM  : ";
        cin>>M[i].nim;
        cout<<"UTS  : ";
        cin>>M[i].uts;
        cout<<"UAS  : ";
        cin>>M[i].uas;
        cout<<"Tugas: ";
        cin>>M[i].tugas;
        M[i].nilaiAkhir=hitung(M[i].uts,M[i].uas,M[i].tugas);
    }
    cout<<"\nDaftar Nilai Mahasiswa\n";
    cout<<"-----------------------------\n";
    cout<<"No\tNIM\t\tNama\t\tNilAkhir\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<M[i].nim<<"\t\t"<<M[i].nama<<"\t\t"<<M[i].nilaiAkhir<<endl;
    }
    return 0;
}

```
#### Output:
<img width="648" height="364" alt="image" src="https://github.com/user-attachments/assets/59af1a7c-a79b-4063-8f8f-b7f1593bf4dc" />


Kode di atas berfungsi untuk menampilkan dua array 2 dimensi (A dan B), kemudian menukar seluruh isi dari kedua array tersebut. Setelah proses pertukaran, program menampilkan hasil akhir dari masing-masing array untuk memperlihatkan perubahan nilainya.

#### Full code Screenshot:
<img width="791" height="780" alt="image" src="https://github.com/user-attachments/assets/eda9206e-5426-4437-93be-92bfb0a45f52" />



## Kesimpulan
Sebagai kesimpulan, praktikum ini membuktikan bahwa bahasa C++ mampu digunakan untuk mengelola data secara terstruktur melalui pemanfaatan variabel, fungsi, struct, array, dan pointer, sekaligus membantu memisahkan bagian program sehingga kode menjadi lebih terorganisir dan mudah dipahami.

## Referensi
Susilo, D., Nistrina, K., & Hartati, S. (2025). Buku Ajar Struktur Data. PT. Sonpedia Publishing Indonesia
