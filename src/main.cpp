#include <iostream>
#include "../inc/RationalNumber.h"

int main() {

    //if a string is passed, validate ((-)num/(-)num))

    RationalNumber rn1(-7,-4);
    cout << rn1 << endl;

    RationalNumber rn2("8/-10");
    cout << rn2 << endl;

    RationalNumber rn3(6);
    cout << rn3 << endl;

    RationalNumber rn4;
    cout << rn4 << endl;

    return 0;
}
