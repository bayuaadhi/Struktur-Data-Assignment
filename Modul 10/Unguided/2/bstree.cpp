#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x){
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else {
        if(x < root->info){
            insertNode(root->left, x);
        } else if(x > root->info){
            insertNode(root->right, x);
        }
        // jika sama, tidak dimasukkan (opsional)
    }
}

void printInOrder(address root){
    if(root != Nil){
        printInOrder(root->left);
        cout << root->info << " ";
        printInOrder(root->right);
    }
}

void printPreOrder(address root){
    if(root != Nil){
        cout << root->info << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root){
    if(root != Nil){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " ";
    }
}
