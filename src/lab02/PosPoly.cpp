//
// Created by Rafael Dejesus on 1/29/2018.
//

#include "PosPoly.h"

PosPoly::PosPoly() : powerCount(0) {
}

void PosPoly::incrementBy(int cof, int pow) {
    for (auto &polynomial : polynomials)
        if (polynomial.power == pow) {
            polynomial.coeff += cof;
            return;
        }

    polynomials.push_back({cof, pow});
    powerCount++;
}

std::ostream &operator<<(std::ostream &out, PosPoly &ob) {
    for (auto const &value: ob.polynomials)
        out << "+" << value.coeff << "x^" << value.power << " ";
    return out;
}

bool PosPoly::operator==(const PosPoly &other) const {
    if (other.powerCount != powerCount)
        return false;
    for (auto const &thisVal: polynomials) {
        bool hasFound = false;
        for (auto const &otherVal: other.polynomials) {
            if (thisVal.coeff == otherVal.coeff &&
                thisVal.power == otherVal.power) {
                hasFound = true;
                break;
            }
        }
        if (!hasFound) return false;
    }
    return true;
}
