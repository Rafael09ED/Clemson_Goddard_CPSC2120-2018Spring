//
// Created by Rafael Dejesus on 2/19/2018
// Lab 5, 2070

#include "Blister.h"

using namespace std;

Blister::Blister(string init) {
    Bode **temp = &start;
    for (char c : init) {
        *temp = new Bode(c);
        temp = &(*temp)->next;
    }
}

Blister::~Blister() {
    while (start != nullptr) {
        Bode *temp = start;
        start = start->next;
        delete temp;
    }
}

ostream &operator<<(ostream &out, const Blister &BL) {
    Bode *temp = BL.start;
    while (temp != nullptr) {
        out << temp->base;
        temp = temp->next;
    }
    return out;
}

int Blister::length() const {
    int count = 0;
    Bode *temp = start;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool Blister::isSubstitutionOf(const Blister &other) const {
    if (length() != other.length()) return false;

    int differences = 0;
    Bode *thisTemp = start;
    Bode *otherTemp = other.start;
    while (differences <= 1 && thisTemp != nullptr) {
        if (thisTemp->base != otherTemp->base) differences++;
        thisTemp = thisTemp->next;
        otherTemp = otherTemp->next;
    }

    //if ((thisTemp != nullptr) ^ (otherTemp != nullptr)) return false;
    // an attempt at doing it without comparing length

    return differences <= 1;
}

bool Blister::isInsertionOf(const Blister &other) const {
    int differences = 0;
    Bode *longer = start;
    Bode *shorter = other.start;

    if (this->length() - other.length() != 1) return false;

    while (differences <= 1 && shorter != nullptr) {
        if (longer->base != shorter->base) differences++;
        else shorter = shorter->next;
        longer = longer->next;
    }
    return differences <= 1;
}
