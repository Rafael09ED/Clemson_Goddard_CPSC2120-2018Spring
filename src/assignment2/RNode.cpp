//
// Created by Rafael Dejesus on 3/13/2018.
//

#include "RNode.h"

RNode::RNode(int s, int e) : RNode(s, e, nullptr, nullptr) {
}

RNode::RNode(int s, int e, RNode *_prev, RNode *_next)
        : min(s), max(e), prev(_prev), next(_next) {
}

RNode::~RNode() {
    if (prev)
        prev->next = next;
    if (next)
        next->prev = prev;
}

void RNode::insertAfter(RNode *other) {
    other->next = next;
    other->prev = this;

    if (next)
        next->prev = other;
    next = other;
}

void RNode::insertBefore(RNode *other) {
    other->prev = prev;
    other->next = this;

    prev->next = other;
    prev = other;
}

bool RNode::isInSet(int val) {
    return min <= val && val <= max;
}

void RNode::deleteValue(int val) {
    if (val == max && val == min) {
        max = min - 1;
    } else if (val == max) {
        max--;
    } else if (val == min) {
        min++;
    } else {
        RNode *temp = new RNode(val + 1, max);
        max = val - 1;
        insertAfter(temp);
    }
}

bool RNode::isInRange(int rMin, int rMax) {
    return (rMin <= max && max <= rMax) || (rMin <= min && min <= rMax);
}

void RNode::expandRight(int rangeMax) {
    RNode *index = next;
    while (index && index->min - 1 <= rangeMax) {
        RNode *temp = index;
        max = temp->max;

        index = index->next;
        delete temp;
    }
    if (max < rangeMax) max = rangeMax;
}

void RNode::expandLeft(int rangeMin) {
    RNode *index = prev;
    while (index && index->max + 1 >= rangeMin) {
        RNode *temp = index;
        min = temp->min;

        index = index->prev;
        delete temp;
    }
    if (min > rangeMin) min = rangeMin;
}

bool RNode::isValid() {
    return max >= min;
}

ostream &operator<<(ostream &out, const RNode &rn) {
    if (rn.min == rn.max) return out << rn.min;
    return out << rn.min << "-" << rn.max;
}

bool RNode::operator!=(const RNode &r) {
    return max != r.max || min != r.min;
}

bool RNode::operator==(const RNode &r) {
    return min == r.min && max == r.max;
}

bool operator<(const RNode &l, const RNode &r) {
    return l.max < r.min;
}

bool operator>(const RNode &l, const RNode &r) {
    return l.min > r.max;
}
