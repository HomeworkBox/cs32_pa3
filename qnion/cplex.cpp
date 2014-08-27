//
//  cplex.cpp
//  pa3x
//
//  Created by FT: Felicia Truong & Tyler Weimin Ouyang on 8/25/14.
//  Copyright (c) 2014 Tyler Weimin Ouyang. All rights reserved.
//
#include <math.h>
#include <iostream>
#include "cplex.h"

using namespace algebra;
using std::istream;
using std::ostream;
using std::cout;

cplex::cplex()
	: _real(0), _imag(0) {
}

cplex::cplex(double real, double imag)
	: _real(real), _imag(imag) {
}

cplex::cplex(double real)
	: _real(real), _imag(0) {
}

double cplex::real() const {
    return _real;
}

void cplex::real(double real) {
    _real = real;
}

double cplex::imag() const {
    return _imag;
 }

void cplex::imag(double imag) {
    _imag = imag;
}

double cplex::abs() const {
    return sqrt(_real*_real + _imag*_imag);
}

cplex cplex::operator-() const {
    cplex temp;
    temp.imag(-1*_imag);
    temp.real(-1*_real);
    return temp;
}

cplex cplex::operator~() const {
    cplex temp;
    temp.imag(-1*_imag);
    temp.real(_real);
    return temp;
}

cplex algebra::operator+(const cplex &left, const cplex &right) {
    cplex temp;
    temp.real( left.real() + right.real());
    temp.imag( left.imag() + right.imag());
    return temp;

}

cplex algebra::operator-(const cplex &left, const cplex &right) {
    cplex temp;
    temp.real( left.real() - right.real());
    temp.imag( left.imag() - right.imag());
    return temp;
}

cplex algebra::operator*(const cplex &left, const cplex &right) {
    cplex temp;
    temp.real( left.real() * right.real() -
              left.imag() * right.imag());
    temp.imag( left.real() * right.imag() +
              left.imag() * right.real());
    return temp;
}

bool algebra::operator==(const cplex &left, const cplex &right) {
    if (left.imag() == right.imag() &&
        left.real() == right.real()) {
        return true;
    }
    return false;
}

 bool algebra::operator!=(const cplex &left, const cplex &right){
     if (left.imag() != right.imag() ||
         left.real() != right.real()) {
         return true;
     }
     return false;
 }

ostream& algebra::operator<<(ostream &os, const cplex &c) {
	return os << "(" << c.real() << ", " << c.imag() << ")";
}

istream& algebra::operator>>(istream &is, cplex &c) {
	double temp;
	is >> temp;
	c.real(temp);
	is >> temp;
	c.imag(temp);
	return is;
}
