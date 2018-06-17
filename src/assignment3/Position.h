//
// Created by Rafael Dejesus on 4/21/2018.
//

#ifndef CPSC2120_POSITION_H
#define CPSC2120_POSITION_H

#include <vector>
#include <iosfwd>

using namespace std;

class Position {
public:
    Position(vector<int> _state);

    Position(vector<int> _state, int _bank);

    Position(vector<int> _state, bool _includesBank);

private:
    Position(vector<int> _state, bool _includesBank, int _bank);

public:
    Position(const Position &_source);

    bool isDone() const;

    Position *afterMove(int) const;

    // Does not print bank
    friend ostream &operator<<(ostream &, const Position &);

    // Does not compare bank
    bool operator==(const Position &rhs) const;

    // Does not include bank
    int getBoardSize() const;

    // Does not print bank
    string toString() const;

private:
    vector<int> state;
};


#endif //CPSC2120_POSITION_H
