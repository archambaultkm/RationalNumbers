#include <iostream>
#include "../inc/RationalNumber.h"

int main() {

    while (true) {

        string input;
        bool valid = false;
        regex acceptableInput(R"([-]?\d+([\/][-]?\d+)*)");

        cout << "RATIONAL NUMBER CALCULATOR" << endl;

        while (!valid) {

            cout << "Enter your first rational number (format x/x or x, no decimals or letters): " << endl;
            cin >> input;

            valid = regex_match(input, acceptableInput);
        }

        //when a string is passed, add validation ((-)num[/(-)num]?)
        RationalNumber rn1(input);

        valid = false;

        while (!valid) {

            cout << "Enter a second rational number (format x/x or x, no decimals or letters): " << endl;
            cin >> input;

            valid = regex_match(input, acceptableInput);
        }

        //when a string is passed, add validation ((-)num[/(-)num]?)
        RationalNumber rn2(input);

        cout << "\nYou entered: " << rn1 << " and " << rn2 << endl;

        cout << "\n" << rn1 << " + " << rn2 << ": " << rn1 + rn2 << endl;
        cout << "\n" << rn1 << " - " << rn2 << ": " << rn1 - rn2 << endl;
        cout << "\n" << rn1 << " * " << rn2 << ": " << rn1 * rn2 << endl;
        cout << "\n" << rn1 << " / " << rn2 << ": " << rn1 / rn2 << endl;

        cout << "\nTo demonstrate overloaded <, >, and ==:" << endl;

        if (rn1 < rn2) {
            cout << rn1 << " is less than " << rn2 << endl;
        } else if (rn1 > rn2) {
            cout << rn1 << " is greater than " << rn2 << endl;
        } else if (rn1 == rn2) {
            cout << rn1 << " equals " << rn2 << endl;
        }

        cout << "\nTo demonstrate other constructors: " << endl;

        RationalNumber rn3(1);
        cout << rn3 << endl;

        RationalNumber rn4(1,2);
        cout << rn4 << endl;

        RationalNumber rn5;
        rn5 = rn3;
        cout << rn5 << endl;

        cout << "\nTo demonstrate other overloaded operators (ex. +=)" << endl;
        rn5 += rn4;
        cout << rn5 << endl;

    }

    return 0;
}
