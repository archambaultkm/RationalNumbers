//
// Created by Kaitlyn Archambault on 2023-03-09.
//

#ifndef RATIONALNUMBERS_RATIONALNUMBERS_H
#define RATIONALNUMBERS_RATIONALNUMBERS_H

#include <string>
#include <regex>
#include <sstream>
#include <utility>
using namespace std;

class RationalNumber {
private:
    int numerator;
    int denominator;

public:

    //default constructor
    RationalNumber() {

        cout <<"default constructor fired" << endl;

        numerator = 0;
        denominator = 0;
    }

    //whole number/ one argument constructor
    RationalNumber(int numerator) {

        cout <<"1arg constructor fired" << endl;

        this->numerator = numerator;
        denominator = 1;
    }

    //two argument constructor
    RationalNumber(int numerator, int denominator) {

        cout <<"2arg constructor fired" << endl;

        this->numerator = numerator;
        this->denominator = denominator;
    }

    //constructor for number passed as string
    //not sure if validation should be here or in the implementation to make sure it's a valid string ((-)num/(-)num)
    RationalNumber(const string& rationalString) {

        cout <<"string constructor fired" << endl;

        vector<int> intVals = stringToRational(rationalString);

        numerator = intVals.at(0);
        denominator = intVals.at(1);
    }

    friend ostream &operator<<(ostream &output, const RationalNumber &rn) {
        output << rn.numerator << "/" << rn.denominator;
        return output;
    }

    //below method adapted from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
    //in this context the delimiter will always be "/"
    vector<int> stringToRational(const string &input) {

        vector<int> result;
        stringstream ss(input);
        string token; //not a real token but
        char delim = '/';

        while (getline (ss, token, delim)) {
            result.push_back (stoi(token));
        }

        return result;
    }
};

#endif //RATIONALNUMBERS_RATIONALNUMBERS_H
