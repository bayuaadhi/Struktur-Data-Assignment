# <h1 align="center">TREE (1)</h1>
<p align="center">Bayu Adhi Nugroho</p>

## Dasar Teori
 Rekursi adalah proses ketika sebuah fungsi atau prosedur memanggil dirinya sendiri. Penggunaannya dalam subprogram membantu membuat kode lebih terstruktur, mudah dibagi ke dalam bagian-bagian kecil, serta dapat digunakan kembali tanpa harus menuliskan perintah yang sama secara berulang
## Guided 

### 1. [Nama Topik]
**bst.h**
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

address alokasi(infotype x);

void insertNode(address &root, infotype x);

address findNode(address root, infotype x);

void InOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root);

#endif
```
**bst.cpp**
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
**main.cpp**
```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```
Program tersebut dirancang untuk membangun serta menguji sebuah Binary Search Tree (BST) secara menyeluruh. Melalui menu yang tersedia pada main.cpp, pengguna dapat melakukan berbagai operasi seperti menambahkan, menghapus, dan mencari data, menampilkan traversal preorder, inorder, dan postorder, menghitung jumlah node dan tinggi pohon, serta mengetahui nilai paling kecil dan paling besar pada tree. Dengan adanya program ini, konsep BST dapat dipahami secara langsung melalui penerapan nyata, tidak hanya sebatas teori.

### 1. [Soal]

**bstree.h**
```C++
#ifndef BSTREE_H
#define BSTREE_H 

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);

void insertNode(address &root, infotype x);

void printInOrderStrip(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root);

#endif
}
```
**bstree.cpp**
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
    else {
        // duplikat: diabaikan
    }
}

address findNode(address root, infotype x) {
    if (root == Nil) return Nil;
    if (root->info == x) return root;
    if (x < root->info) return findNode(root->left, x);
    return findNode(root->right, x);
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == Nil) return 0;
    int L = hitungKedalaman(root->left);
    int R = hitungKedalaman(root->right);
    return 1 + max(L, R);
}
```
**main.cpp**
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6); // duplikat
    insertNode(root,7);

    cout << "Inorder : ";
    InOrder(root);

    cout << "\nKedalaman: " << hitungKedalaman(root) << endl;
    cout << "Jumlah Node: " << hitungJumlahNode(root) << endl;
    cout << "Total Info: " << hitungTotalInfo(root) << endl;

    return 0;
}
```
#### Output:
<img width="464" height="146" alt="image" src="https://github.com/user-attachments/assets/109e63af-c198-4dd8-842f-1f0b0d1f32fd" />

#### Full code Screenshot:
<img width="618" height="814" alt="image" src="https://github.com/user-attachments/assets/b41c8956-7779-455a-bd45-017d17830610" />
<img width="363" height="475" alt="image" src="https://github.com/user-attachments/assets/c09a2276-1c96-4498-acd4-8ef7149d27b8" />
<img width="450" height="442" alt="image" src="https://github.com/user-attachments/assets/a24c8e50-aee2-43d1-ad53-7ff438b2f2e4" />


### 2. [Soal]

**bstree.h**
```C++
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

}
```
**bstree.cpp**
```C++
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

```
**main.cpp**
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main(){
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

    cout << "IN-ORDER   : ";
    printInOrder(root);
    cout << endl;

    cout << "PRE-ORDER  : ";
    printPreOrder(root);
    cout << endl;

    cout << "POST-ORDER : ";
    printPostOrder(root);
    cout << endl;

    return 0;
}

```
#### Output:
<img width="439" height="124" alt="image" src="https://github.com/user-attachments/assets/10f8627b-e0e0-47ca-b977-252b03266e56" />

#### Full code Screenshot:
<img width="378" height="439" alt="image" src="https://github.com/user-attachments/assets/c0384633-471a-4734-8df7-662980169120" />
<img width="472" height="412" alt="image" src="https://github.com/user-attachments/assets/da9c4cee-7d1e-447e-a3b0-33ee0faaec35" />
<img width="638" height="769" alt="image" src="https://github.com/user-attachments/assets/471eac1a-eed8-45d3-a037-510faa9eb606" />


## Kesimpulan
Pendekatan rekursif digunakan untuk mengolah Binary Search Tree (BST). Struktur BST memungkinkan data tersimpan secara teratur dan dapat ditampilkan berurutan melalui traversal inorder. Dengan memanfaatkan beberapa fungsi rekursif, program juga dapat menghitung kedalaman pohon, jumlah node, serta total nilai yang ada. Selain itu, pemisahan program ke dalam beberapa file membuat kode lebih terstruktur dan mudah dikelola.

## Referensi
Sarno, R., & Rahutomo, F. (2008). Penerapan algoritma weighted tree similarity untuk pencarian semantik. JUTI: Jurnal Ilmiah Teknologi Informasi, 39-46.
