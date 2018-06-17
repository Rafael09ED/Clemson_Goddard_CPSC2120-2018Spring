//
// Created by Rafael Dejesus on 4/22/2018.
//

#include "PositionTreeNode.h"


PositionTreeNode::PositionTreeNode(Position *_val) : PositionTreeNode(_val, nullptr, -1) {}

PositionTreeNode::PositionTreeNode(Position *_val, PositionTreeNode *_parent, int _index)
        : parent(_parent), value(_val), positionPicked(_index) {}

PositionTreeNode::~PositionTreeNode() {
    delete value;
}