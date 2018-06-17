//
// Created by Rafael Dejesus on 4/21/2018.
//

#include <iostream>
#include <utility>
#include "Position.h"

Position::Position(const Position &_source) : Position(_source.state, true, 0) {}

Position::Position(vector<int> _state) : Position(_state, false, 0) {}

Position::Position(vector<int> _state, int _bank) : Position(_state, false, _bank) {}

Position::Position(vector<int> _state, bool _includesBank) : Position(_state, _includesBank, 0) {}

Position::Position(vector<int> _state, bool _includesBank, int _bank) : state(_state) {
    if (!_includesBank)
        state.push_back(_bank);
}

bool Position::isDone() const {
    for (auto i = state.begin(); i + 1 != state.end(); ++i)
        if (*i != 0) return false;
    return true;
}

Position *Position::afterMove(int indexToMove) const {
    indexToMove--;
    if (indexToMove < 0 || indexToMove >= getBoardSize()) return nullptr;
    vector<int> newState = state;

    int beads = newState.at(indexToMove);
    if (!beads) return nullptr;

    newState.at(indexToMove) = 0;
    for (int i = indexToMove + 1; beads > 0; beads--, i++)
        newState.at(i % state.size())++;

    return new Position(newState, true);
}

int Position::getBoardSize() const {
    return state.size() - 1;
}

bool Position::operator==(const Position &rhs) const {
    if (getBoardSize() != rhs.getBoardSize())
        return false;

    for (int i = 0; i < getBoardSize(); i++)
        if (state.at(i) != rhs.state.at(i))
            return false;

    return true;
}

ostream &operator<<(ostream &stream, const Position &pos) {
    return stream << pos.toString();
}

string Position::toString() const {
    if (state.size() <= 1) return "[]";

    string values;
    for (auto i = state.begin(); i + 1 != state.end(); ++i)
        values += to_string(*i) + '.';

    return "[" + values.substr(0, values.length() - 1) + "]";
}



