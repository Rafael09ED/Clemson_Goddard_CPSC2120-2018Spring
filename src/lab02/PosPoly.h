//
// Created by starm on 1/29/2018.
//

#ifndef CPSC2120_POSPOLY_H
#define CPSC2120_POSPOLY_H

#include <vector>
#include <ostream>

using namespace std;

class PosPoly {
    typedef struct intPair_t {
        int coeff;
        int power;
    } intPair;

public:
    PosPoly();

    void incrementBy(int cof, int pow);

    friend std::ostream &operator<<(std::ostream &out, PosPoly &ob);
    bool operator==(const PosPoly &other) const;

private:
    vector<intPair> polynomials;
    int powerCount;
};

#endif //CPSC2120_POSPOLY_H
