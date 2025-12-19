#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);

void printInOrder(address root);
void printPreOrder(address root);   // ← Tambahan latihan 3
void printPostOrder(address root);  // ← Tambahan latihan 3

#endif
