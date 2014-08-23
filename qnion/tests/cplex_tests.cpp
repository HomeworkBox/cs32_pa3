#include "../cplex.h"
#include "gtest/gtest.h"

using namespace algebra;

TEST(cplex_tests, creation_test) {
	cplex x;
	ASSERT_EQ(0, x.real()) << "invalid real part";
	ASSERT_EQ(0, x.imag()) << "invalid imag part";

	cplex y(-1.3, 2);
	ASSERT_EQ(-1.3, y.real()) << "invalid real part";
	ASSERT_EQ(2, y.imag()) << "invalid imag part";
	
	const double pi = 3.14159265;
	cplex z(pi);
	ASSERT_EQ(pi, z.real()) << "invalid real part";
	ASSERT_EQ(0, z.imag()) << "invalid imag part";
}

TEST(cplex_tests, get_set_test) {
	cplex x;
	x.real(-0.5);
	x.imag(3.7);
	ASSERT_EQ(-0.5, x.real()) << "invaid real part";
	ASSERT_EQ(3.7, x.imag()) << "invalid imag part";
}

TEST(cplex_tests, abs_test) {
	double eps = 10e-8;
	cplex x(-1.7, 3.5);
	double res = x.abs();
	ASSERT_GT(res, 0) << "abs value cannot be negative";
	ASSERT_LE(abs(res * res - (1.7 * 1.7 + 3.5 * 3.5)), eps) << "invalid abs value";
}

TEST(cplex_tests, unary_minus_test) {
	cplex x(-1, 2);
	cplex y(-x);
	ASSERT_EQ(1, y.real()) << "invalid real part";
	ASSERT_EQ(-2, y.imag()) << "invalid imag part";
}

TEST(cplex_tests, conjugation_test) {
	cplex x(-3.9, 5.5);
	cplex y(~x);
	ASSERT_EQ(-3.9, y.real()) << "invalid real part";
	ASSERT_EQ(-5.5, y.imag()) << "invalid imag part";
}

TEST(cplex_tests, operator_plus_test) {

	cplex x(-3, 5);
	cplex y(1, -5);
	cplex z(x + y);
	ASSERT_EQ(-2, z.real()) << "invalid real part";
	ASSERT_EQ(0, z.imag()) << "invalid imag part";
}

TEST(cplex_tests, operator_minus_test) {
	cplex x(-3, 3);
	cplex y(1, -5);
	cplex z(x - y);
	ASSERT_EQ(-4, z.real()) << "invalid real part";
	ASSERT_EQ(8, z.imag()) << "invalid imag part";
}

TEST(cplex_tests, operator_mult_test) {
	const double eps = 10e-8;
	cplex x(3, -7);
	cplex y(-2, 3.3);
	cplex z(x * y);
	ASSERT_LE(abs(17.1 - z.real()), eps) << "invalid real part";
	ASSERT_LE(abs(23.9 - z.imag()), eps) << "invalid imag part";
}

TEST(cplex_tests, operator_eqcmp_test) {
	cplex w(3, -7);
	cplex x(3, -7);
	cplex y(3, 7);
	cplex z(1, -7);
	ASSERT_TRUE(w == x);
	ASSERT_FALSE(w == y);
	ASSERT_FALSE(w == z);
	ASSERT_FALSE(x == y);
	ASSERT_FALSE(x == z);
	ASSERT_FALSE(y == z);
}

TEST(cplex_tests, operator_istream_test) {
	std::stringstream ss;
	ss << "1 2 3 4";

	cplex x, y;
	ss >> x >> y;
	ASSERT_EQ(1, x.real()) << "invalid real part of x";
	ASSERT_EQ(2, x.imag()) << "invalid imag part of x";
	ASSERT_EQ(3, y.real()) << "invalid real part of y";
	ASSERT_EQ(4, y.imag()) << "invalid imag part of y";
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
