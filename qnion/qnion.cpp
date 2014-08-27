//
//  qnion.cpp
//  pa3x
//
//  Created by FT: Felicia Truong & Tyler Weimin Ouyang on 8/25/14.
//  Copyright (c) 2014 Tyler Weimin Ouyang. All rights reserved.
//
#include <iostream>
#include "qnion.h"

using namespace algebra;
using std::ostream;
using std::istream;

qnion::qnion()
	: _a(0), _b(0) {
}

qnion::qnion(const cplex &a, const cplex &b)
	: _a(a), _b(b) {
}

cplex qnion::a() const {
    return _a;
}

void qnion::a(const cplex &a) {
    _a = a;
}

cplex qnion::b() const {
    return _b ;
}

void qnion::b(const cplex &b) {
    _b = b;
}

qnion qnion::operator-() const {
    qnion temp;
    temp.a(-(_a));
    temp.b(-(_b));
    return temp;
}

qnion qnion::operator~() const {
    qnion temp;
    temp.a(~(_a));
    temp.b(-(_b));
    return temp;
}

qnion algebra::operator+(const qnion &left, const qnion &right) {
    qnion temp;
    temp.a(left.a() + right.a());
    temp.b(left.b() + right.b());
    return temp;
}

qnion algebra::operator-(const qnion &left, const qnion &right) {
    qnion temp;
    temp.a(left.a() - right.a());
    temp.b(left.b() - right.b());
    return temp;
}
 
qnion algebra::operator*(const qnion &left, const qnion &right) {
    qnion temp;
    temp.a(left.a() * right.a() -
              left.b() * ~(right.b()));
    temp.b(left.a() * right.b() +
              left.b() * ~(right.a()));
    return temp;
}

bool algebra::operator==(const qnion &left, const qnion &right) {
    if (left.a() == right.a() &&
        left.b() == right.b()) {
        return true;
    }
    return false;
}

bool algebra::operator!=(const qnion &left, const qnion &right) {
    if (left.a() != right.a() ||
        left.b() != right.b()) {
        return true;
    }
    return false;

}

ostream& algebra::operator<<(ostream& os, const qnion &q) {
	return os << "{" << q.a() << q.b() << "}";
}

istream& algebra::operator>>(istream& is, qnion &q) {
	cplex temp;
	is >> temp;
	q.a(temp);
	is >> temp;
	q.b(temp);
	return is;
}
