//
// Created by starm on 2/21/2018.
//

#include <iostream>

using namespace std;

int main() {
    int *val;
    cout << "Initializing int pointer with value of 12" << endl;
    cout << "address: " << val << endl;

    while (*val != 12)
        val = new int;

    cout << "@ index " << val << " value of: " << *val << endl;
}