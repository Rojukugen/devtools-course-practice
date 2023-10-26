// Copyright 2023 Yashin Egor

#include <gtest/gtest.h>

#include <string>

#include "../include/string_calculator.h"

TEST(Calc_String_Calculator, Can_Set_Calc_Infix1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+3";

    // Assert
    ASSERT_NO_THROW(sc.set_Calc_infix(str));
}

TEST(Calc_String_Calculator, Correct_Set_Calc_Infix1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+3";

    // Act
    sc.set_Calc_infix(str);
    std::string tmp = sc.get_Calc_infix();

    // Assert
    EXPECT_EQ(tmp, str);
}

TEST(Calc_String_Calculator, Can_Transform_To_Calc_Postfix1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+3";
    std::string tmp = "3 3+";

    // Act
    sc.set_Calc_infix(str);
    sc.CalcCalculate();
    str = sc.get_Calc_postfix();

    // Assert
    EXPECT_EQ(str, tmp);
}

TEST(Calc_String_Calculator, Can_Add_Two_Nums1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+3";

    // Act
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 6);
}

TEST(Calc_String_Calculator, Can_Subtract1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3 - 2";

    // Act
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 1);
}

TEST(Calc_String_Calculator, Can_Multiply1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3 * 3";

    // Act
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 9);
}

TEST(Calc_String_Calculator, Can_Divide1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "6 / 2";

    // Act
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 3);
}

TEST(Calc_String_Calculator, Can_Not_Divide_By_Zero1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3 / 0";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Rase_To_A_Power1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3^2";

    // Act
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 9);
}

TEST(Calc_String_Calculator, Can_Return_Num_Without_Signs1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "333";

    // Act
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 333);
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Plus_Begin1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "+33";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Plus_End1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+3+";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Minus_Begin1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "-3+3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Minus_End1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+3-";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Mult_Begin1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "*3+3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Mult_End1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+3*";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Divide_Begin1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "/3+3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Divide_End1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+3/";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Power_Begin1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "^3+3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Power_End1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+3^";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Two_Pluses1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3++3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Pluse_Near_Multyple1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+*3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Pluse_Near_Pow1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+^3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Two_Minuses1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3--3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Minus_Near_Multiple1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3*-3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Minus_Near_Pow1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3^-3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Two_Multiple1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3**3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Multiple_Near_Plus1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3*+3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Multiple_Near_Pow1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3*^3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Two_Divide1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3//3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Divide_Near_Plus1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+/3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Divide_Near_Pow1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3^/3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Two_Pows1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3^^3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Pow_Near_Plus1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3^+3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Pow_Near_Multiple1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3^*3";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Correct_Calc_Priority1) {
    // Arrange
    CalcStringCalculator sc;

    // Act
    int a = sc.get_Calc_priority('+');

    // Assert
    EXPECT_EQ(a, 1);
}

TEST(Calc_String_Calculator, Exception_In_Calc_Priority1) {
    // Arrange
    CalcStringCalculator sc;

    // Act
    int a = sc.get_Calc_priority('c');

    // Assert
    EXPECT_EQ(a, -1);
}

TEST(Calc_String_Calculator, Can_Calc_Calculate_Fraction1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3.5 + 3.5";

    // Act
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 7);
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_Mismatched_Brackets1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = ")3+3(";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_More_Open_Brackets1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "(((((3+3)";

    // Act
    sc.set_Calc_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}

TEST(Calc_String_Calculator, Can_CalcCalculate_With_Different_Priorities1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3 + 3 * 3";

    // Act
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 12);
}

TEST(Calc_String_Calculator,
            Can_Calc_Calculate_Long_Expression_Without_Brackets1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3 + 3 ^ 3 + 3 * 3 - 6 / 3";

    // Act
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 37);
}

TEST(Calc_String_Calculator,
            Can_Calc_Calculate_Long_Expression_With_Brackets1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "(3 + 3) * 3 - 3 ^ 3 / 9";

    // Act
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 15);
}

TEST(Calc_String_Calculator, Can_Calc_Calculate_Not_Empty_Stacks1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "(3 + 3) * 3 - 3 ^ 3 / 9";

    // Act
    sc.set_Calc_stacks(4);
    sc.set_Calc_infix(str);
    double res = sc.CalcCalculate();

    // Assert
    EXPECT_EQ(res, 15);
}

TEST(Calc_String_Calculator, Can_Not_Calc_Calculate_With_One_Num1) {
    // Arrange
    CalcStringCalculator sc;
    std::string str = "3+";

    // Act
    sc.set_Calc_postfix(str);

    // Assert
    ASSERT_ANY_THROW(sc.CalcCalculate());
}
