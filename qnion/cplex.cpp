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

// double cplex::real() const { ... }

// void cplex::real(double real) { ... }

// double cplex::imag() const { ... }

// void cplex::imag(double imag) { ... }

// double cplex::abs() const { ... }

// cplex cplex::operator-() const { ... }

// cplex cplex::operator~() const { ... }

// cplex algebra::operator+(const cplex &left, const cplex &right) { ... }

// cplex algebra::operator-(const cplex &left, const cplex &right) { ... }

// cplex algebra::operator*(const cplex &left, const cplex &right) { ... }

// bool algebra::operator==(const cplex &left, const cplex &right) { ... }

// bool algebra::operator!=(const cplex &left, const cplex &right) { ... }

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
