// final PTDriver for propa-tree lab
#include <iostream>
#include "PropaTree.cpp"

using namespace std;

int main() {
    PropaTree T;
    int leafCount = 0;
    int add;
    do {
        leafCount++;
        cout << "Enter leaf number [1--" << leafCount << "]: ";
        cin >> add;
        if (add > 0)
            T.addAtLeaf(add);
    } while (add > 0);
    T.dump();
}
