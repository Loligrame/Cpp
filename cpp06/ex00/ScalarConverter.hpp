#pragma once
#include <cctype>
#include <iostream>
#include <algorithm> 
#include <string>
#include <iomanip>
#include <cerrno>
#include <climits>

class ScalarConverter{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);        
        ScalarConverter &operator=(const ScalarConverter &obj);  
    public:
        ~ScalarConverter();
        static void convert(const std::string &literal);
};
bool isDouble(const std::string &literal);
bool isInt(const std::string &literal);
bool isFloat(const std::string &literal);
bool isChar(const std::string &literal);
bool isPseudoLiteral(const std::string &literal);
void intConvert(const std::string &literal);
void charConvert(const std::string &literal);