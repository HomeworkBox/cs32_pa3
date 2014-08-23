#ifndef __QNION_H__
#define __QNION_H__

#include "cplex.h"

namespace algebra {

class qnion {
private:
	cplex _a;
	cplex _b;
public:
	qnion();
	qnion(const cplex &a, const cplex &b);

	cplex a() const;
	void a(const cplex &a);
	cplex b() const;
	void b(const cplex &b);

	qnion operator-() const;
	qnion operator~() const;
};

qnion operator+(const qnion &left, const qnion &right);
qnion operator-(const qnion &left, const qnion &right);
qnion operator*(const qnion &left, const qnion &right);
bool operator==(const qnion &left, const qnion &right);
bool operator!=(const qnion &left, const qnion &right);
ostream& operator<<(ostream& os, const qnion &q);
istream& operator>>(istream& is, qnion &q);

}

#endif // __QNION_H__
