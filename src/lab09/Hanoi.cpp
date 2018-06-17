//
// Created by Rafael Dejesus on 4/4/2018.
//

#include "Hanoi.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Invalid Params!\n" << "Usage: exec [number of disks]\n";
        return -1;
    }

    int disks = stoi(argv[1]);
    Hanoi hanoi(disks);

    cout << hanoi << endl;
    while (!hanoi.isSolved()) {
        hanoi.doRandomMove();
        cout << hanoi << "\n";
    }

    return 0;
}

const int Hanoi::towerCount;

Hanoi::Hanoi(int _disks) : totalDisks(_disks), towersMap(new Stack<Disk *> *[towerCount]) {
    for (int i = 0; i < towerCount; ++i)
        towersMap[i] = new Stack<Disk *>();
    auto startTower = towersMap[startTowerIndex];
    for (int i = 0; i < totalDisks; ++i) {
        startTower->push(new Disk(_disks - i));
    }

}

Hanoi::~Hanoi() {
    for (int i = 0; i < towerCount; ++i) {
        auto tower = towersMap[i];
        while (!tower->isEmpty())
            delete tower->pop();
        delete tower;
    }
    delete towersMap;
}

bool Hanoi::isSolved() {
    return towersMap[endTowerIndex]->getCount() == totalDisks;
}


void Hanoi::doRandomMove() {
    int start, end;
    do {
        start = rand() % towerCount;
        end = rand() % towerCount;
    } while (!isValidMove(start, end));

    doMove(start, end);
    printMove(start, end, towersMap[end]->peek()->width);
}

void Hanoi::doMove(int startIndex, int endIndex) {
    towersMap[endIndex]->push(towersMap[startIndex]->pop());
}

bool Hanoi::isValidMove(int startIndex, int endIndex) {
    if (startIndex == endIndex) return false;

    auto startTower = towersMap[startIndex];
    if (startTower->isEmpty()) return false;

    auto endTower = towersMap[endIndex];
    if (endTower->isEmpty()) return true;

    return startTower->peek() > endTower->peek();
}

void Hanoi::printMove(int startIndex, int endIndex, int movedValSize) {
    cout << "Move " << movedValSize << " from " << startIndex << " -> " << endIndex << endl;
}


string Hanoi::getTowerHeightVal(int towerIndex, int heightIndex) const {
    auto tower = towersMap[towerIndex];
    if (tower->getCount() <= heightIndex) return "";
    return to_string(tower->get(heightIndex)->width);
}

ostream &operator<<(ostream &lhs, const Hanoi &rhs) {
    for (int i = rhs.totalDisks; i >= 0; --i) {
        lhs << " ";
        for (int j = 0; j < rhs.towerCount; ++j) {
            lhs << setw(2) << left << rhs.getTowerHeightVal(j, i) << " ";
        }
        lhs << "\n";
    }

    return lhs;
}
