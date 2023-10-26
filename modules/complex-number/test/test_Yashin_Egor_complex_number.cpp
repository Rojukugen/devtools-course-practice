// Copyright 2023 Yashin Egor

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Yashin_Egor_Co1mplexNumberTest, Default_Constructor) {
    ComplexNumber number;
    ASSERT_EQ(number.getIm(), 0);
    ASSERT_EQ(number.getRe(), 0);
}
TEST(Yashin_Egor_ComplexNumberTest, Setters) {
    ComplexNumber number;
    number.setRe(8);
    number.setIm(9);
    ASSERT_EQ(number.getRe(), 8);
    ASSERT_EQ(number.getIm(), 9);
}
TEST(Yashin_Egor_ComplexNumberTest, Modified_Sum_Conjugate) {
    ComplexNumber num1(42, 24);
    ComplexNumber num2(42, -24);
    ComplexNumber num3 = num1 + num2;
    ASSERT_EQ(num3.getRe(), 84);
    ASSERT_EQ(num3.getIm(), 0);
}