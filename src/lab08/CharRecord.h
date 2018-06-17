//
// Created by Rafael Dejesus on 3/26/2018.
//

#ifndef CPSC2120_CHARRECORD_H
#define CPSC2120_CHARRECORD_H

#include <string>

using namespace std;

class CharRecord {

public:
    CharRecord(std::string value, int count);

    CharRecord();

    string getCharString();

    int getCount() const;

private:
    string value = "Error";
    int count = 0;
};


bool operator>(const CharRecord &lhs, const CharRecord &rhs);

bool operator<(const CharRecord &lhs, const CharRecord &rhs);

#endif //CPSC2120_CHARRECORD_H
