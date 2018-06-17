/* Rafael Dejesus (rdejesu)
 * 2120
 * 2/11/2018
 * Assignment 1
 */

#include <fstream>
#include <iostream>
#include "Corpus.h"

Corpus::Corpus() : proportions{0.09, 0.02, 0.02, 0.04, 0.12, 0.02, 0.03, 0.02, 0.09, 0.01, 0.01, 0.04, 0.02, 0.06, 0.08,
                               0.02, 0.01, 0.06, 0.04, 0.06, 0.04, 0.02, 0.02, 0.01, 0.02, 0.01} {
    print();
}

Corpus::Corpus(string filename) {
    for (float &proportion : proportions) proportion = 0;

    string line;
    int count = 0;
    ifstream in(filename);

    while (getline(in, line))
        for (char &character : line)
            if (isalpha(character)) {
                count++;
                proportions[tolower(character) - ASCII_a] += 1;
            }
    for (float &val : proportions)
        val = val / count;
    print();
}

double Corpus::proportion(char letter) {
    return proportions[letter - ASCII_a];
}

void Corpus::print() {
    cout << "Frequencies are: ";
    for (float &val : proportions) cout << val << ", ";
    cout << endl;
}
