//
// Created by Kaitlyn Archambault on 2023-03-09.
//

#ifndef RATIONALNUMBERS_RATIONALNUMBERS_H
#define RATIONALNUMBERS_RATIONALNUMBERS_H

#include <string>
#include <regex>
#include <sstream>
#include <utility>
#include <iostream>
using namespace std;

class RationalNumber {
private:
    int numerator;
    int denominator;

public:
    //constructors
    RationalNumber();
    explicit RationalNumber(int numerator);
    RationalNumber(int numerator, int denominator);
    explicit RationalNumber(const string& rationalString);

    //member functions
    RationalNumber& operator+(const RationalNumber& rn);
    RationalNumber& operator-(const RationalNumber& rn);
    RationalNumber& operator*(const RationalNumber& rn);
    RationalNumber& operator/(const RationalNumber& rn);
    vector<int> stringToRational(const string &input);
    int getGCD(int numerator, int denominator);

    //friend functions
    friend ostream& operator<<(ostream &output, const RationalNumber &rn);
};

#endif //RATIONALNUMBERS_RATIONALNUMBERS_H
