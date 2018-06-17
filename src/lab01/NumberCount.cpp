//

// Created by starm on 1/22/2018.
//

#include <iostream>
#include "NumberCount.h"

using namespace std;

NumberCount::NumberCount(int _min, int _max) :
        min(_min), max(_max), size(max - min + 1), array(new int[size]) {
    for (int i = 0; i < size; ++i)
        array[i] = 0;

}

void NumberCount::addElement(int elementToAdd) {
    int index = elementToAdd - min;
    if (!indexInBound(index)) {
        printOutOfRange(elementToAdd);
        return;
    }
    array[index]++;
}

void NumberCount::removeElement(int elementToRemove) {
    int index = elementToRemove - min;
    if (!indexInBound(index)) {
        printOutOfRange(elementToRemove);
        return;
    }
    if (array[index] <= 0) {
        printNotPresent(elementToRemove);
        return;
    }
    array[index]--;

}

void NumberCount::display() {
    int size = max - min + 1;
    for (int i = 0; i < size; ++i) {
        cout << (min + i) << ":";
        for (int j = 0; j < array[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

bool NumberCount::indexInBound(int index) {
    return !(index > max - min || index < 0);
}

int main() {
    NumberCount N(1, 10);
    N.addElement(12);
    N.addElement(2);
    N.removeElement(2);
    N.addElement(2);
    N.addElement(2);
    N.addElement(8);
    N.addElement(2227);
    N.addElement(3);
    N.removeElement(1);
    N.display();
}

std::ostream &operator<<(std::ostream &out, const NumberCount &ob) {
    out << "range: " << ob.min << " - " << ob.max;
    return out;
}

void NumberCount::printOutOfRange(int value) {
    cout << value << " Out of Range; " << endl;
}

void NumberCount::printNotPresent(int value) {
    cout << value << " not present; " << endl;
}

