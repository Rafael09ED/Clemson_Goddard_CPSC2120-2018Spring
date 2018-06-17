//
// Created by Rafael Dejesus on 3/13/2018.
//

#ifndef CPSC2120_RANGESET_H
#define CPSC2120_RANGESET_H


#include "RNode.h"

class RangeSet {
public:
    RangeSet();

    void addLonelyRange(int min, int max);

    bool isInSet(int val);

    bool deleteValue(int val);

    void dump();

    void addRange(int min, int max);

    bool deleteRange(int min, int max);

    bool const operator==(const RangeSet &r);

private:
    RNode *head;

    bool isInputValid(int min, int max);

    RNode *getContainingNode(int val);

    RNode *getFirstNodeInRange(int min, int max);

    bool handleValidation(int min, int max);
};

//bool operator==(const RangeSet &l, const RangeSet &r);

#endif //CPSC2120_RANGESET_H
