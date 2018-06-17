/* Rafael Dejesus (rdejesu)
 * 2120
 * 2/11/2018
 * Assignment 1
 */

#include <iostream>
#include "Corpus.h"
#include "MySentence.h"

using namespace std;

int main() {
    cout << "Enter file name for corpus: ";
    string input;
    getline(cin, input);
    Corpus corpus(input);
    cout << "Enter sentence terminated by <ENTER>: ";
    getline(cin, input);
    MySentence sentence(input);
    cout << "Decoded sentence is: ";
    sentence.decode(corpus);
    sentence.reverse();
    cout << sentence << endl;

}