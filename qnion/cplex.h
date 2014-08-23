#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>

namespace algebra {

using std::istream;
using std::ostream;

class cplex {
private:
	double _real;
	double _imag;
public:
	cplex();
	cplex(double real, double imag);
	cplex(double number);

	double real() const;
	void real(double real);
	double imag() const;
	void imag(double imag);

	double abs() const;

	cplex operator-() const;
	cplex operator~() const;
};

cplex operator+(const cplex &left, const cplex &right);
cplex operator-(const cplex &left, const cplex &right);
cplex operator*(const cplex &left, const cplex &right);
bool operator==(const cplex &left, const cplex &right);
bool operator!=(const cplex &left, const cplex &right);
ostream& operator<<(ostream &os, const cplex &c);
istream& operator>>(istream &is, cplex &c);

}

#endif // __COMPLEX_H__
