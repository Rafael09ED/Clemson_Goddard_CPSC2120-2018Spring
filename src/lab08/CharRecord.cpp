//
// Created by Rafael Dejesus on 3/26/2018.
//

#include "CharRecord.h"


bool operator>(const CharRecord &lhs, const CharRecord &rhs) {
    return lhs.getCount() > rhs.getCount();
}

bool operator<(const CharRecord &lhs, const CharRecord &rhs) {
    return lhs.getCount() < rhs.getCount();
}

int CharRecord::getCount() const {
    return count;
}

string CharRecord::getCharString() {
    return value;
}

CharRecord::CharRecord(string _value, int _count) : value(std::move(_value)), count(_count) {
}

CharRecord::CharRecord() {}
