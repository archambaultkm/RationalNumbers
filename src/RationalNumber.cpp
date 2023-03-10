//
// Created by Kaitlyn Archambault on 2023-03-09.
//

#include "../inc/RationalNumber.h"

//default constructor
RationalNumber::RationalNumber() {

    cout <<"default constructor fired" << endl;

    numerator = 0;
    denominator = 1;
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

    if (rationalString.find('/') != string::npos) {

        vector<int> intVals = stringToRational(rationalString);

        numerator = intVals.at(0);
        denominator = intVals.at(1);

    } else {

        numerator = stoi(rationalString);
        denominator = 1;
    }
}

//member functions

RationalNumber& RationalNumber::operator+(const RationalNumber& rn) {

    denominator = denominator * rn.denominator;
    numerator = (numerator * rn.denominator) + (rn.numerator * denominator); //really important that you do numerator first

    int gcd = getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    return *this;
}

RationalNumber& RationalNumber::operator-(const RationalNumber& rn) {

    numerator = (numerator * rn.denominator) - (rn.numerator * denominator); //really important that you do numerator first
    denominator = denominator * rn.denominator;

    int gcd = getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    return *this;
}

RationalNumber& RationalNumber::operator*(const RationalNumber& rn) {

    numerator = (numerator * rn.denominator) / (rn.numerator * denominator); //really important that you do numerator first
    denominator = denominator * rn.denominator;

    int gcd = getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    return *this;
}

RationalNumber& RationalNumber::operator/(const RationalNumber& rn) {

    numerator = (numerator * rn.denominator) * (rn.numerator * denominator); //really important that you do numerator first
    denominator = denominator * rn.denominator;

    int gcd = getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    return *this;
}

RationalNumber& RationalNumber::operator=(const RationalNumber& rn) {

    cout << "custom assignment operator fired" << endl;
    numerator = rn.numerator;
    denominator = rn.denominator;
}

int RationalNumber::getGCD(int numerator, int denominator) {

    if (denominator == 0)
        return numerator;

    return getGCD(denominator, numerator % denominator);
}

//below method adapted from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
//needs to be able to take a whole number too... maybe check with a contains("/")
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

//friend functions

ostream& operator<<(ostream &output, const RationalNumber &rn) {

    if (rn.numerator == rn.denominator) {
        output << 1;
    } else if (rn.numerator == 0) {
        output << 0;
    } else if (rn.denominator == 1) {
        output << rn.numerator;
    } else {
        output << rn.numerator << "/" << rn.denominator;
    }

    return output;
}