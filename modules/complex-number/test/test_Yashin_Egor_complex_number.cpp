// Copyright 2023 Yashin Egor

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Yashin_Egor_ComplexNumberTest, Can_Get_Im) {
    double re = 2.0;
    double im = 3.0;
    ComplexNumber z(re, im);
    EXPECT_DOUBLE_EQ(im, z.getIm());
}
TEST(Yashin_Egor_ComplexNumberTest, TEST_SUB) {
    ComplexNumber a(123.0, 50.0),
        b(30.0, 14.0),
        expected(93.0, 36.0);

    ComplexNumber result = a - b;

    ASSERT_EQ(expected, result);
}
TEST(Yashin_Egor_ComplexNumberTest, Sum_Conjugate) {
    ComplexNumber num1(42, 24);
    ComplexNumber num2(42, -24);

    ComplexNumber num3(84, 0);

    ASSERT_EQ(num1 + num2, num3);
}