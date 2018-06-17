// SyntaxChecker for rangeset asg - wdg
#include <iostream>
#include <assert.h>
#include "RangeSet.h"

using namespace std;

void testBasic(){}


int main() {
    RangeSet S, T;
    S.addLonelyRange(1, 1);
    S.addLonelyRange(22, 33);
    S.addLonelyRange(77, 78);
    S.dump();
    cout << endl;

    cout << boolalpha << S.isInSet(10) << ":" << S.isInSet(30) << " , expected: false:true" << endl;

    T.dump();  // should print "Empty"
    cout << "^expected: empty^" << endl;
    cout << boolalpha << (S == T) << " , expected: false" << endl; // should be false
    T.addLonelyRange(22, 33);
    T.addLonelyRange(77, 78);
    T.addLonelyRange(1, 1);
    T.dump();
    cout << boolalpha << (S == T) << " , expected: true" << endl;  // should be true

    T.deleteValue(1);
    T.dump();
    T.deleteValue(22);
    T.dump();
    T.deleteValue(33);
    T.dump();
    T.deleteValue(30);
    T.dump();
    T.deleteValue(78);
    T.dump();

    T.addRange(10, 23);
    T.dump();

    T.addRange(30,77);
    T.dump();

    T.addRange(99,99);
    T.dump();

    T.addRange(79,79);
    T.dump();

    T.addLonelyRange(80,80);
    T.dump();

    T.deleteRange(79,90);
    T.dump();

    T.deleteRange(10,14);
    T.dump();

    T.deleteRange(80,90);
    T.dump();

    T.addRange(100, 200);
    T.dump();
    T.addRange(80,82);
    T.dump();
}


