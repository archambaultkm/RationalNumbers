#include <iostream>
#include "../inc/RationalNumber.h"

int main() {

    //if a string is passed, validate ((-)num/(-)num))

    //to test that constructors work:
    RationalNumber rn1(2,3);
    cout << rn1 << endl;

    RationalNumber rn5(1,3);

    RationalNumber rn6 = rn1 / rn5;
    cout << rn6 << endl;

    return 0;
}
