// Copyright 2023 Yashin Egor

#include <gtest/gtest.h>

#include "include/complex_number.h"


// Test power method to the first power (identity)
TEST(Yashin_EGOR_ComplexNumberTest, PowerIdentity) {
	ComplexNumber z(2.0, -3.0);
	ComplexNumber identity = z.power(1);
	EXPECT_EQ(identity.getRe(), 2.0);
	EXPECT_EQ(identity.getIm(), -3.0);
}

// Test power method to the zero power
TEST(Yashin_EGOR_ComplexNumberTest, PowerZero) {
	ComplexNumber z(2.0, -3.0);
	ComplexNumber zeroPower = z.power(0);
	EXPECT_EQ(zeroPower.getRe(), 1.0);
	EXPECT_EQ(zeroPower.getIm(), 0.0);
}

// Test power method to a negative power
TEST(Yashin_EGOR_ComplexNumberTest, PowerNegative) {
	ComplexNumber z(2.0, -3.0);
	ComplexNumber negativePower = z.power(-2);
	EXPECT_DOUBLE_EQ(negativePower.getRe(), -0.045454545454545456);
	EXPECT_DOUBLE_EQ(negativePower.getIm(), 0.06818181818181819);
}

// Test power method to a fractional power
TEST(Yashin_EGOR_ComplexNumberTest, PowerFractional) {
	ComplexNumber z(2.0, -3.0);
	ComplexNumber fractionalPower = z.power(0.5);
	EXPECT_DOUBLE_EQ(fractionalPower.getRe(), 1.5010595677132415);
	EXPECT_DOUBLE_EQ(fractionalPower.getIm(), -0.9039072313340563);
}