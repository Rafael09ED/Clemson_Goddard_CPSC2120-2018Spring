//
// Created by Rafael Dejesus on 4/22/2018.
//

#ifndef CPSC2120_POSITIONTREENODE_H
#define CPSC2120_POSITIONTREENODE_H


#include "Position.h"

struct PositionTreeNode {
    int positionPicked;
    PositionTreeNode *parent;
    Position *value;

    PositionTreeNode(Position *_val);

    PositionTreeNode(Position *_val, PositionTreeNode *_parent, int _index);

    ~PositionTreeNode();

};

#endif //CPSC2120_POSITIONTREENODE_H
