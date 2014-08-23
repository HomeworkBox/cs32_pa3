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

// cplex qnion::a() const { ... }

// void qnion::a(const cplex &a) { ... }

// cplex qnion::b() const { ... }

// void qnion::b(const cplex &b) { ... }

// qnion qnion::operator-() const { ... }

// qnion qnion::operator~() const { ... }

// qnion algebra::operator+(const qnion &left, const qnion &right) { ... }

// qnion algebra::operator-(const qnion &left, const qnion &right) { ... }
 
// qnion algebra::operator*(const qnion &left, const qnion &right) { ... }

// bool algebra::operator==(const qnion &left, const qnion &right) { ... }

// bool algebra::operator!=(const qnion &left, const qnion &right) { ... }

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
