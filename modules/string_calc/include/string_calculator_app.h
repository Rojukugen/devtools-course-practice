// Copyright 2023 Yashin Egor

#ifndef MODULES_STRING_CALC_INCLUDE_STRING_CALCULATOR_APP_H_
#define MODULES_STRING_CALC_INCLUDE_STRING_CALCULATOR_APP_H_

#include <string>
#include <stdexcept>

class String_Calculator_App {
 public:
    String_Calculator_App();
    std::string operator()(int argc, const char** argv);

 private:
    std::string help();
    std::string argument_error();
    std::string calc_error(const std::invalid_argument& e);
};

#endif  // MODULES_STRING_CALC_INCLUDE_STRING_CALCULATOR_APP_H_
