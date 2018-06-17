//
// Created by Rafael Dejesus on 4/4/2018.
//

#ifndef CPSC2120_DISC_H
#define CPSC2120_DISC_H

struct Disk {
    Disk(int width);

    //Disk(const Disk &orig);

    int width;
};

bool operator>(const Disk &lhs, const Disk &rhs);

bool operator<(const Disk &lhs, const Disk &rhs);

#endif //CPSC2120_DISC_H
