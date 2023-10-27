// Copyright 2023 Yashin Egor

#include <string>
#include <iostream>

#include "include/string_calculator_app.h"

int main(int argc, const char** argv) {
    StringCalculatorApp app;
    std::string result = app(argc, argv);
    std::cout << result << std::endl;
    return 0;
}
