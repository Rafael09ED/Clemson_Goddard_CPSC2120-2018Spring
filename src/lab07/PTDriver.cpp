// final PTDriver for propa-tree lab
#include <iostream>
#include "PropaTree.cpp"

using namespace std;

int main() {
    int numLeaves = 100;
    int sum = 0;
    cout << "numLeaves = " << numLeaves << endl;
    for (int i = 0; i < 10; ++i) {
        PropaTree T;
        for (int j = 1; j < numLeaves; ++j) {
            T.expandTreeRandom();
        }
        cout << T.inbalance() << ", ";
        sum += T.inbalance();
    }
    cout << "avg: " << (sum / 10.0) << endl;
}
