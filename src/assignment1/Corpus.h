/* Rafael Dejesus (rdejesu)
 * 2120
 * 2/11/2018
 * Assignment 1
 */

#ifndef CPSC2120_CORPUS_H
#define CPSC2120_CORPUS_H

#include <string>
#include <ostream>

using namespace std;

class Corpus {
public:
    Corpus();

    Corpus(string filename);

    double proportion(char letter);

private:
    void print();

    static const int ALPHABET_SIZE = 26;
    static const char ASCII_a = 'a';
    float proportions[ALPHABET_SIZE];
};


#endif //CPSC2120_CORPUS_H
