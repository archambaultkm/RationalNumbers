#include "../inc/RationalNumber.h"

int main() {

    //driver program to exercise RationalNumber class

    while (true) {

        string input;
        bool valid = false;
        //decimals, 0 as denominator, / without denominator, and non-numeric entries won't be accepted
        regex acceptableInput(R"([-]?\d+([\/][-]?[1-9]+)*)");

        cout << "\nRATIONAL NUMBER CALCULATOR" << endl;

        //---------------------------------Read and Validate Input--------------------------------------------//

        while (!valid) {

            cout << "Enter your first rational number (format x/x or x, no decimals or letters): " << endl;
            cin >> input;

            valid = regex_match(input, acceptableInput);
        }

        RationalNumber rn1(input);

        valid = false;
        while (!valid) {

            cout << "Enter a second rational number (format x/x or x, no decimals or letters): " << endl;
            cin >> input;

            valid = regex_match(input, acceptableInput);
        }

        RationalNumber rn2(input);

        cout << "\nYou entered: " << rn1 << " and " << rn2 << endl;

        //---------------------------------Math Operators--------------------------------------------//

        cout << "\nDemonstrating overloaded math operators using your entered numbers: " << endl;

        cout << "\n" << rn1 << " + " << rn2 << " = " << rn1 + rn2 << endl;
        cout << "\n" << rn1 << " - " << rn2 << " = " << rn1 - rn2 << endl;
        cout << "\n" << rn1 << " * " << rn2 << " = " << rn1 * rn2 << endl;
        cout << "\n" << rn1 << " / " << rn2 << " = " << rn1 / rn2 << endl;

        cout << "\n" << rn1 << " += " << rn2 << " = ";
        rn1 += rn2;
        cout << rn1 << endl;

        cout << "\n" << rn1 << " -= " << rn2 << " = ";
        rn1 -= rn2;
        cout << rn1 << endl;

        cout << "\n" << rn1 << " *= " << rn2 << " = ";
        rn1 *= rn2;
        cout << rn1 << endl;

        cout << "\n" << rn1 << " /= " << rn2 << " = ";
        rn1 /= rn2;
        cout << rn1 << endl;

        //---------------------------------Comparison Operators--------------------------------------------//

        cout << "\nComparing first fraction to second to demonstrate overloaded <, >, or ==:" << endl;

        if (rn1 < rn2) {
            cout << rn1 << " is less than " << rn2 << endl;
        } else if (rn1 > rn2) {
            cout << rn1 << " is greater than " << rn2 << endl;
        } else if (rn1 == rn2) {
            cout << rn1 << " equals " << rn2 << endl;
        }

        //---------------------------------Other Constructors--------------------------------------------//

        cout << "\nTo demonstrate other constructors: " << endl;

        RationalNumber rn3(3);
        cout << "Constructor given one argument(3): " << rn3 << endl;

        RationalNumber rn4(1,2);
        cout << "Constructor given two arguments(1,2): " << rn4 << endl;

        RationalNumber rn5;
        rn5 = rn3;
        cout << "Assignment operator used with previous fraction: " << rn5 << endl;

        cout << endl;
    }

    return 0;
}
