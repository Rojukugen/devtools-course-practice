// Copyright 2023 Yashin Egor

#include <string>
#include <stdexcept>

#include "../include/string_calculator.h"
#include "../include/string_calculator_app.h"

String_Calculator_App::String_Calculator_App() {}

std::string String_Calculator_App::operator() (int argc, const char** argv) {
    if (argc != 2) {
        return this->argument_error();
    }

    std::string arg = std::string(argv[1]);
    if (arg == "--help" || arg == "-h") {
        return this->help();
    }

    try {
        Calc_String_Calculator sc;
        sc.set_Calc_infix(arg);
        double result = sc.Calc_Calculate();
        return std::to_string(result);
    } catch (std::invalid_argument& e) {
        return this->calc_error(e);
    }
}

std::string String_Calculator_App::help() {
    std::string help = std::string("")
        +  "Glad to see you in the string calculator app!\n"
        +  "Please, provide mathematical expression to be calculated\n"
        +  "Generally you can type something like (111+4)/5*6^2 \n"
        +  "Supported operations are: '+' '-' '/' '*' '^'";
    return help;
}

std::string String_Calculator_App::argument_error() {
    std::string error = std::string("")
    + "Invalid argument amount, try --help or -h command";
    return error;
}

std::string String_Calculator_App::calc_error(const std::invalid_argument& e) {
    std::string error = std::string("")
    + "Calculation error!";
    return error;
}
