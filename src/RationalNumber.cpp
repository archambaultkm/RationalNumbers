//
// Created by Kaitlyn Archambault on 2023-03-09.
//

#include "../inc/RationalNumber.h"

//default constructor
RationalNumber::RationalNumber() {

    cout <<"default constructor fired" << endl;

    numerator = 0;
    denominator = 0;
}

//whole number/ one argument constructor
RationalNumber::RationalNumber(int numerator) {

    cout <<"1arg constructor fired" << endl;

    this->numerator = numerator;
    denominator = 1;
}

//two argument constructor
RationalNumber::RationalNumber(int numerator, int denominator) {

    cout <<"2arg constructor fired" << endl;

    this->numerator = numerator;
    this->denominator = denominator;
}

//constructor for number passed as string
RationalNumber::RationalNumber(const string& rationalString) {

    cout << "string constructor fired" << endl;

    vector<int> intVals = stringToRational(rationalString);

    numerator = intVals.at(0);
    denominator = intVals.at(1);
}

ostream& operator<<(ostream &output, const RationalNumber &rn) {
    output << rn.numerator << "/" << rn.denominator;
    return output;
}

//below method adapted from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
//in this context the delimiter will always be "/"
vector<int> RationalNumber::stringToRational(const string &input) {

    vector<int> result;
    stringstream ss(input);
    string token; //not a real token but
    char delim = '/';

    while (getline (ss, token, delim)) {
        result.push_back (stoi(token));
    }

    return result;
}