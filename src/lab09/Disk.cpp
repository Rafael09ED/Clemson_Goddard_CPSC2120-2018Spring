//
// Created by Rafael Dejesus on 4/4/2018.
//

#include "Disk.h"

Disk::Disk(int width) : width(width) {}

//Disk::Disk(const Disk &orig) : width(orig.width) {}

bool operator>(const Disk &lhs, const Disk &rhs) {
    return lhs.width > rhs.width;
}

bool operator<(const Disk &lhs, const Disk &rhs) {
    return lhs.width < rhs.width;
}
