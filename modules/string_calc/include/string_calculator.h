// Copyright 2023 Yashin Egor

#ifndef MODULES_STRING_CALC_INCLUDE_STRING_CALCULATOR_H_
#define MODULES_STRING_CALC_INCLUDE_STRING_CALCULATOR_H_

#include <stack>
#include <string>

class Calc_String_Calculator {
 private:
    std::string Calc_infix_, Calc_postfix_;
    std::stack<char> Calc_charStack_;
    std::stack<double> Calc_doubleStack_;

    bool Calc_Check();
    int Calc_Priority(const char& el);
    void Calc_To_Postfix();

 public:
    void set_Calc_infix(const std::string str);
    void set_Calc_postfix(const std::string str);
    void set_Calc_stacks(int n);
    std::string get_Calc_infix();
    std::string get_Calc_postfix();
    int get_Calc_priority(const char& el);
    double Calc_Calculate();
};

#endif  // MODULES_STRING_CALC_INCLUDE_STRING_CALCULATOR_H_