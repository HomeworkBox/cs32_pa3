#include <iostream>
#include "qnion.h"

using namespace std;

int main() {
	using algebra::qnion;

    algebra::cplex d(1, -1);
    d=-d;
    d=~d;
    
    
	qnion a, b;
	cout << "Input first q-nion (e.g., 3 0 5.8 -2): ";
	cin >> a;
	cout << "Input second q-nion: ";
	cin >> b;

	qnion x = -a + a * ~b;
	qnion y = ~(-a) + b * ~a;

	cout << "x = " << x << "\n";
	cout << "y = " << y << "\n";
	
	qnion alpha = x - y;
	qnion beta = x - ~y;
	qnion qzero;
	cout << "alpha == qzero? '" << (alpha == qzero ? "yes" : "no") << "'\n";
	cout << "beta == qzero? '" << (beta == qzero ? "yes" : "no") << "'\n";

	return 0;
}
