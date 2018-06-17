/* Rafael Dejesus (rdejesu)
 * 2120
 * 2/11/2018
 * Assignment 1
 */

#include "MySentence.h"
#include <bits/stdc++.h>

MySentence::MySentence(string _value) : value(move(_value)) {}

char MySentence::rotationOf(char character) {
    return rotationOf(character, 1);
}

char MySentence::rotationOf(char character, int times) {
    int offset;
    times = times % ALPHABET_SIZE;
    if (isupper(character))
        offset = ASCII_A;
    else if (islower(character))
        offset = ASCII_a;
    else
        return character;
    return ((character - offset + times) % ALPHABET_SIZE) + offset;
}

void MySentence::rotate() {
    for (auto &c :value) c = rotationOf(c);
}

void MySentence::rotate(int times) {
    for (auto &c :value) c = rotationOf(c, times);
}

void MySentence::reverse() {
    std::reverse(value.begin(), value.end());
}

bool MySentence::operator==(const MySentence &rhs) const {
    return !rhs.value.compare(value);
}

bool MySentence::operator!=(const MySentence &rhs) const {
    return rhs.value.compare(value);
}

ostream &operator<<(ostream &os, const MySentence &sentence) {
    os << sentence.value;
    return os;
}

void MySentence::decode(Corpus &corpus) {
    double maxScore = scoreWith(corpus);
    int maxScoreIndex = 0;
    for (int i = 1; i <= ALPHABET_SIZE; ++i) {
        rotate();
        double newScore = scoreWith(corpus);
        if (newScore > maxScore) {
            maxScore = newScore;
            maxScoreIndex = i;
        }
    }
    rotate(maxScoreIndex);
}

double MySentence::scoreWith(Corpus &corpus) {
    double sum = 0;
    for (char &letter : value)
        if (isalpha(letter))
            sum += corpus.proportion(tolower(letter));
    return sum;
}

