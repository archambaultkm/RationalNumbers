#include <iostream>
#include "../inc/RationalNumber.h"

int main() {

    //if a string is passed, validate ((-)num/(-)num))

    //to test that constructors work:
    RationalNumber rn1(2,3);
    cout << rn1 << endl;

    RationalNumber rn2(1,6);
    cout << rn2 << endl;

    RationalNumber rn3 = rn1 + rn2;
    cout << rn3 << endl;

    RationalNumber rn4 = rn1;
    cout << rn4 << endl;

    RationalNumber rn5 = rn2;
    cout << rn5 << endl;

    RationalNumber rn6("45");
    cout << rn6 << endl;

    return 0;
}
