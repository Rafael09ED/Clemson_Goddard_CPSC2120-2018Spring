//
// Created by Rafael Dejesus on 2/26/2018.
//

#ifndef CPSC2120_PROPATREE_H
#define CPSC2120_PROPATREE_H

struct Node {
    char value;
    int descendantLeaves = 1;
    Node *left = nullptr, *right = nullptr;
public:
    Node(char val);

    void printPreorder(unsigned int depth);

    void expandTree(int leafIndex, char lVal, char rVal);
};

class PropaTree {
public:
    PropaTree();

    void addAtLeaf(int leafIndex);

    void dump();

private:
    char nextVal = 'A';
    Node *head = nullptr;
};


#endif //CPSC2120_PROPATREE_H
