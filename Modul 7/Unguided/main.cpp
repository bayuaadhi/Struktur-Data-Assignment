#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    push(S, 10);
    push(S, 20);
    push(S, 30);

    cout << "Setelah push 3 data:" << endl;
    printStack(S);

    cout << "Pop: " << pop(S) << endl;

    cout << "Setelah pop 1 data:" << endl;
    printStack(S);

    return 0;
}
