//
// Created by Kaitlyn Archambault on 2023-03-09.
//
#include "../inc/RationalNumber.h"

//------------------------------------Constructors--------------------------------------------//

//default constructor
RationalNumber::RationalNumber() {

    cout <<"Default constructor fired" << endl;

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

    cout << "String constructor fired" << endl;

    //if there is a / in the string, the user entered a numerator and denominator
    if (rationalString.find('/') != string::npos) {

        vector<int> intVals = stringToRational(rationalString);

        numerator = intVals.at(0);
        denominator = intVals.at(1);

    } else {

        numerator = stoi(rationalString);
        denominator = 1;
    }
}

//default destructor
RationalNumber::~RationalNumber() {

    cout << "Destructor fired" << endl;
}

//------------------------------------Member Functions--------------------------------------------//

//below method adapted from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
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

int RationalNumber::getGCD(int numerator, int denominator) {

    if (denominator == 0)
        return numerator;

    //recursive function will keep going until the numerator is the gcd
    return getGCD(denominator, numerator % denominator);
}

void RationalNumber::reduce(RationalNumber& rn) {

    int gcd = getGCD(rn.numerator, rn.denominator);
    rn.numerator /= gcd;
    rn.denominator /= gcd;

    //if the fraction is negative, only represent it in numerator
    //(or cancel it out if both numerator and denominator are negative)
    if (rn.denominator < 0) {

        rn.numerator *= -1;
        rn.denominator *= -1;
    }
}

RationalNumber& RationalNumber::operator=(const RationalNumber& rn) {

    cout << "Custom assignment operator fired" << endl;
    numerator = rn.numerator;
    denominator = rn.denominator;

    return *this;
}

//------------------------------------Math Operators--------------------------------------------//

//make and return a new RationalNumber in the operator overloads so arithmetic on the same fraction objects multiple times is possible

RationalNumber RationalNumber::operator+(const RationalNumber& rn) {

    RationalNumber result;

    result.numerator = (this->numerator * rn.denominator) + (rn.numerator * this->denominator);
    result.denominator = this->denominator * rn.denominator;

    reduce(result);

    return result;
}

RationalNumber& RationalNumber::operator+=(const RationalNumber& rn) {

    this->numerator = (this->numerator * rn.denominator) + (rn.numerator * this->denominator);
    this->denominator *= rn.denominator;

    reduce(*this);

    return *this;
}

RationalNumber RationalNumber::operator-(const RationalNumber& rn) {

    RationalNumber result;

    result.numerator = (this->numerator * rn.denominator) - (rn.numerator * this->denominator);
    result.denominator = this->denominator * rn.denominator;

    reduce(result);

    return result;
}

RationalNumber& RationalNumber::operator-=(const RationalNumber& rn) {

    this->numerator = (this->numerator * rn.denominator) - (rn.numerator * this->denominator);
    this->denominator *= rn.denominator;

    reduce(*this);

    return *this;
}

RationalNumber RationalNumber::operator*(const RationalNumber& rn) {

    RationalNumber result;

    result.numerator = this->numerator * rn.numerator;
    result.denominator = this->denominator * rn.denominator;

    reduce(result);

    return result;
}

RationalNumber& RationalNumber::operator*=(const RationalNumber& rn) {

    this->numerator *= rn.numerator;
    this->denominator *= rn.denominator;

    reduce(*this);

    return *this;
}

RationalNumber RationalNumber::operator/(const RationalNumber& rn) {

    RationalNumber result;

    result.numerator = this->numerator * rn.denominator;
    result.denominator = this->denominator * rn.numerator;

    reduce(result);

    return result;
}

RationalNumber& RationalNumber::operator/=(const RationalNumber& rn) {

    this->numerator *= rn.denominator;
    this->denominator *= rn.numerator;

    reduce(*this);

    return *this;
}

//------------------------------------Comparison Operators--------------------------------------------//

bool RationalNumber::operator<(const RationalNumber& rn) {
    return (this->numerator * rn.denominator) < (rn.numerator * this->denominator);
}

bool RationalNumber::operator<=(const RationalNumber& rn) {
    return (this->numerator * rn.denominator) <= (rn.numerator * this->denominator);
}

bool RationalNumber::operator>(const RationalNumber& rn) {
    return (this->numerator * rn.denominator) > (rn.numerator * this->denominator);
}

bool RationalNumber::operator>=(const RationalNumber& rn) {
    return (this->numerator * rn.denominator) >= (rn.numerator * this->denominator);
}

bool RationalNumber::operator==(const RationalNumber& rn) {
    return (this->numerator * rn.denominator) == (rn.numerator * this->denominator);
}

bool RationalNumber::operator!=(const RationalNumber& rn) {
    return (this->numerator * rn.denominator) != (rn.numerator * this->denominator);
}

//------------------------------------Friend Functions--------------------------------------------//

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