#ifndef CPSC2120_NUMBERCOUNT_H
#define CPSC2120_NUMBERCOUNT_H

#include <iostream>

class NumberCount {
public:
    NumberCount(int _min, int _max);

    void addElement(int elementToAdd);

    void removeElement(int elementToRemove);

    void display();

    friend std::ostream &operator<<(std::ostream &out, const NumberCount &ob);

private:
    int min;
    int max;
    int size;
    int *array;

    bool indexInBound(int index);

    void printOutOfRange(int value);

    void printNotPresent(int value);
};


#endif //CPSC2120_NUMBERCOUNT_H
