#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
#include <string>
using namespace std;

const int MAX = 6; // 

struct Mahasiswa { // [cite: 175]
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa { // [cite: 179-182]
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

void createStack(StackMahasiswa &StackMHS); // [cite: 184]
bool isEmpty(StackMahasiswa StackMHS); // [cite: 183]
bool isFull(StackMahasiswa StackMHS); // [cite: 183]
void Push(StackMahasiswa &StackMHS, Mahasiswa M); // [cite: 185]
void Pop(StackMahasiswa &StackMHS); // [cite: 186]
void Update(StackMahasiswa &StackMHS, int posisi); // [cite: 187]
void View(StackMahasiswa StackMHS); // [cite: 188]
void SearchNilaiAkhir(StackMahasiswa StackMHS, float min, float max); // [cite: 188]
void MaxNilaiAkhir(StackMahasiswa StackMHS); // [cite: 238]

#endif