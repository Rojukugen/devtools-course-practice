// Copyright 2023 Yashin Egor

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Yashin_Egor_ComplexNumberTest, can_add_large_complex_numbers) {
    ComplexNumber num1(1.0e6, 2.0e6);
    ComplexNumber num2(-0.5e6, -0.5e6);
    ComplexNumber sum = num1 + num2;
    ASSERT_NEAR(sum.getRe(), 0.5e6, 1e-6);
    ASSERT_NEAR(sum.getIm(), 1.5e6, 1e-6);
}

TEST(Yashin_Egor_ComplexNumberTest, can_multiply_complex_numbers_with_imaginary_units) {
    ComplexNumber i(0.0, 1.0);
    ComplexNumber result = i * i;
    ASSERT_NEAR(result.getRe(), -1.0, 1e-6);
    ASSERT_NEAR(result.getIm(), 0.0, 1e-6);
}



TEST(Yashin_Egor_ComplexNumberTest, can_copy_construct_complex_number) {
    ComplexNumber num(3.0, 4.0);
    ComplexNumber copy = num;
    ASSERT_EQ(copy.getRe(), 3.0);
    ASSERT_EQ(copy.getIm(), 4.0);
}

TEST(Yashin_Egor_ComplexNumberTest, can_assign_complex_number) {
    ComplexNumber num1(1.0, 2.0);
    ComplexNumber num2(3.0, 4.0);
    num1 = num2;
    ASSERT_EQ(num1.getRe(), 3.0);
    ASSERT_EQ(num1.getIm(), 4.0);
}

TEST(Yashin_Egor_ComplexNumberTest, can_compare_complex_numbers) {
    ComplexNumber num1(2.0, 3.0);
    ComplexNumber num2(2.0, 3.0);
    ComplexNumber num3(4.0, 5.0);
    ASSERT_TRUE(num1 == num2);
    ASSERT_FALSE(num1 == num3);
}

