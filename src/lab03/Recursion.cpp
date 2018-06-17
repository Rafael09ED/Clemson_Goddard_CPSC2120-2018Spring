/* Rafael Dejesus (rdejesu)
 * 2120
 * 2/11/2018
 * Assignment 1
 */

#include <iostream>
#include "Recursion.h"

Recursion::Recursion(std::string fileName) {
    ifstream infile(fileName);
    string line;
    for (unsigned short row = 0; row < ROW_SIZE; ++row) {
        getline(infile, line);
        for (unsigned short col = 0; col < COL_SIZE; ++col)
            if (line.at(col) == '.') grid[row][col] = GRID_NULL_FLAG;
            else grid[row][col] = GRID_NONNULL_FLAG;
    }
}


void Recursion::print() {
    short count = 1;
    for (short row = 0; row < COL_SIZE; ++row)
        for (short col = 0; col < ROW_SIZE; ++col) {
            if (grid[row][col] == GRID_NONNULL_FLAG) {
                cout << "Group " << count++ << ": ";
                printGroup(row, col);
                cout << endl;
            }
            if (grid[row][col] == GRID_GROUP_FLAG)
                grid[row][col] = GRID_NONNULL_FLAG;
        }
}


void Recursion::printGroup(short row, short col) {
    grid[row][col] = GRID_GROUP_FLAG;
    cout << " (" << row << "," << col << ")";
    for (short rowInc = -1; rowInc <= 1; ++rowInc)
        for (short colInc = -1; colInc <= 1; ++colInc)
            if ((rowInc != -colInc && rowInc != colInc) && isGoodCandidate(row + rowInc, col + colInc))
                printGroup(row + rowInc, col + colInc);
}


bool Recursion::isInBounds(short row, short col) {
    return !(row >= ROW_SIZE || row < 0 || col >= COL_SIZE || col < 0);
}


bool Recursion::isGoodCandidate(short row, short col) {
    return isInBounds(row, col) && grid[row][col] == GRID_NONNULL_FLAG;
}


int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    Recursion rec(argv[1]);
    rec.print();
    return 0;
}