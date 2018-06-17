//
// Created by starm on 1/31/2018.
//

#ifndef CPSC2120_RECURSION_H
#define CPSC2120_RECURSION_H

#include <string>
#include <fstream>

using namespace std;

class Recursion {
public:
    explicit Recursion(string fileName);

    void print();

private:
    static short const
            GRID_NULL_FLAG = 0,
            GRID_NONNULL_FLAG = 1,
            GRID_GROUP_FLAG = 2;
    static short const
            COL_SIZE = 10,
            ROW_SIZE = 10;
    short int grid[ROW_SIZE][COL_SIZE];

    bool isInBounds(short row, short col);

    bool isGoodCandidate(short row, short col);

    void printGroup(short row, short col);
};


#endif //CPSC2120_RECURSION_H
