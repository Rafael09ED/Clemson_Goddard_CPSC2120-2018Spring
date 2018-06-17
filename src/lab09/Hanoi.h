//
// Created by Rafael Dejesus on 4/4/2018.
//

#ifndef CPSC2120_HANOI_H
#define CPSC2120_HANOI_H

#include <map>
#include "Stack.h"
#include "Disk.h"

using namespace std;

class Hanoi {
public:

    Hanoi(int _disks);

    ~Hanoi();

    void start();

    bool isSolved();

    void doRandomMove();

    void doMove(int startIndex, int endIndex);

    friend std::ostream &operator<<(std::ostream &, const Hanoi &);
private:

    static const int towerCount = 3,
            startTowerIndex = 0,
            endTowerIndex = 2;
    Stack<Disk *> **towersMap;

    int totalDisks;


    bool isValidMove(int startIndex, int endIndex);

    void printMove(int startIndex, int endIndex, int movedValSize);

    string printTowers() const;

    string getTowerHeightVal(int towerIndex, int heightIndex) const;
};


#endif //CPSC2120_HANOI_H
