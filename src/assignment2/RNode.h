//
// Created by Rafael Dejesus on 3/13/2018.
//

#ifndef CPSC2120_RNODE_H
#define CPSC2120_RNODE_H

#include <iostream>

using namespace std;

struct RNode {
    int min, max;
    RNode *next;
    RNode *prev;


    // Constructors //

    RNode(int s, int e);

    RNode(int s, int e, RNode *_prev, RNode *_next);

    ~RNode();

    // Functions //

    void insertAfter(RNode *other);

    void insertBefore(RNode *other);

    void deleteValue(int val);

    bool isInSet(int val);

    bool isInRange(int rMin, int rMax);

    void expandRight(int rangeMax);

    void expandLeft(int rangeMin);

    bool isValid();

    // Operators //

    bool operator!=(const RNode &r);

    bool operator==(const RNode &r);
};

bool operator<(const RNode &l, const RNode &r);

bool operator>(const RNode &l, const RNode &r);

ostream &operator<<(ostream &out, const RNode &rn);


#endif //CPSC2120_RNODE_H
