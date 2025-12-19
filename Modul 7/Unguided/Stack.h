#ifndef STACK_H
#define STACK_H

#define MAX 50

struct Stack {
    int top;
    int data[MAX];
};

// Membuat stack kosong
void createStack(Stack &S);

// Mengecek apakah stack kosong
bool isEmpty(Stack S);

// Mengecek apakah stack penuh
bool isFull(Stack S);

// Menambah elemen (push)
void push(Stack &S, int x);

// Menghapus elemen (pop)
int pop(Stack &S);

// Mencetak isi stack
void printStack(Stack S);

#endif
