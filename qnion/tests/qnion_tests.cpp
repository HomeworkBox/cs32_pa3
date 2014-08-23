#include "../qnion.h"
#include "gtest/gtest.h"

using namespace algebra;

TEST(qnion_tests, bigtest) {
	qnion a(cplex(1, 2), cplex(3, 4));
	qnion b(cplex(-1, 0), cplex(7, -2));

	qnion x = -a + a * ~b;
	qnion y = ~(-a) + b * ~a;
	
	qnion alpha = x - y;
	qnion beta = x - ~y;
	qnion qzero;
	
	ASSERT_NE(qzero, alpha) << "invalid alpha";
	ASSERT_EQ(qzero, beta) << "invalid beta";
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
