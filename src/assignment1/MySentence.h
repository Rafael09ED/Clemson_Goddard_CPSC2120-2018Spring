/* Rafael Dejesus (rdejesu)
 * 2120
 * 2/11/2018
 * Assignment 1
 */

#ifndef CPSC2120_MYSENTENCE_H
#define CPSC2120_MYSENTENCE_H

#include <iostream>
#include "Corpus.h"

using namespace std;

class MySentence {
public:
    MySentence(string);

    static char rotationOf(char character);

    static char rotationOf(char character, int times);

    void rotate();

    void reverse();

    void rotate(int times);

    friend ostream &operator<<(ostream &os, const MySentence &sentence);

    bool operator==(const MySentence &rhs) const;

    bool operator!=(const MySentence &rhs) const;

    double scoreWith(Corpus &);

    void decode(Corpus &);


private:
    static const int ALPHABET_SIZE = 26;
    static const char
            ASCII_A = 'A',
            ASCII_Z = 'Z',
            ASCII_a = 'a',
            ASCII_z = 'z';
    string value;
};


#endif //CPSC2120_MYSENTENCE_H
