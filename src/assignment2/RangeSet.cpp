//
// Created by Rafael Dejesus on 3/13/2018.
//

#include "RangeSet.h"

RangeSet::RangeSet() : head(new RNode(-1, -1)) {}

void RangeSet::addLonelyRange(int min, int max) {
    if (handleValidation(min, max)) return;

    RNode *nodeToInsert = new RNode(min, max);
    RNode *temp = head;

    while (temp->next != nullptr && *temp < *nodeToInsert)
        temp = temp->next;

    if (temp->next == nullptr && *temp < *nodeToInsert)
        temp->insertAfter(nodeToInsert);
    else
        temp->insertBefore(nodeToInsert);
}

void RangeSet::dump() {
    for (RNode *temp = head->next; temp != nullptr; temp = temp->next)
        cout << *temp << ", ";
    cout << endl;
}

bool RangeSet::isInSet(int val) {
    for (RNode *temp = head->next; temp != nullptr; temp = temp->next)
        if (temp->isInSet(val))
            return true;
    return false;
}

bool const RangeSet::operator==(const RangeSet &r) {
    RNode *left = head, *right = r.head;
    while (left != nullptr && right != nullptr) {
        if (*left != *right) return false;

        left = left->next;
        right = right->next;
    }
    return right == left;
}

bool RangeSet::deleteValue(int val) {
    RNode *temp = getContainingNode(val);
    if (temp == nullptr) return false;

    temp->deleteValue(val);
    if (!temp->isValid())      // if was a single value range
        delete temp;           // delete
    return true;
}

void RangeSet::addRange(int min, int max) {
    RNode *firstNode = getFirstNodeInRange(min - 1, max + 1);
    if (firstNode == nullptr)
        return addLonelyRange(min, max);

    firstNode->expandRight(max);
    firstNode->expandLeft(min);
}

bool RangeSet::deleteRange(int min, int max) {
    if(handleValidation(min, max)) return false;

    if (min == max)
        return deleteValue(min);
    if (min + 1 == max) {
        bool a = deleteValue(min);
        bool b = deleteValue(max);
        return a || b;
    };

    RNode *inRange = getFirstNodeInRange(min, max);
    if (!inRange) return false;
    addRange(min, max);
    deleteValue(min);
    deleteValue(max);
    delete getContainingNode(min + 1);
    return true;
}

RNode *RangeSet::getContainingNode(int val) {
    for (RNode *temp = head->next; temp != nullptr; temp = temp->next) {
        if (temp->isInSet(val)) return temp;
        if (val < temp->max) return nullptr;
    }
    return nullptr;
}

RNode *RangeSet::getFirstNodeInRange(int min, int max) {
    for (RNode *temp = head->next; temp != nullptr; temp = temp->next)
        if (temp->isInRange(min, max))
            return temp;
    return nullptr;
}

bool RangeSet::handleValidation(int min, int max) {
    if (isInputValid(min, max)) return false;
    cout << "Range Not Valid" << endl;
    return true;
}

bool RangeSet::isInputValid(int min, int max) {
    return max >= min && min >= 0;
}
