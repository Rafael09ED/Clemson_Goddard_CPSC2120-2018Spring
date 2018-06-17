//
// Created by Rafael Dejesus on 2/26/2018.
//


#include <string>
#include <iostream>
#include "PropaTree.h"

using namespace std;

PropaTree::PropaTree() {
    head = new Node(nextVal++);
}

void PropaTree::addAtLeaf(int leafIndex) {
    char lVal = nextVal++;
    char rVal = nextVal++;
    head->expandTree(leafIndex, lVal, rVal);
}

void PropaTree::dump() {
    head->printPreorder(0);
}

Node::Node(char val) : value(val) {}

void Node::printPreorder(unsigned int depth) {
    string prefix(depth * 3, '.');
    cout << prefix << value << "[" << descendantLeaves << "]" << endl;
    if (descendantLeaves == 1) return;
    left->printPreorder(depth + 1);
    right->printPreorder(depth + 1);
}

void Node::expandTree(int leafIndex, char lVal, char rVal) {
    if (descendantLeaves++ == 1) {
        left = new Node(lVal);
        right = new Node(rVal);
        return;
    }
    if (left->descendantLeaves >= leafIndex)
        left->expandTree(leafIndex, lVal, rVal);
    else
        right->expandTree(leafIndex - left->descendantLeaves, lVal, rVal);
}
