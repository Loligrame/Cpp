#pragma once
#include <cctype>
#include <iostream>
#include <algorithm> 
#include <string>
#include <iomanip>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cmath>

class ScalarConverter{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);        
        ScalarConverter &operator=(const ScalarConverter &obj);  
        ~ScalarConverter();
    public:
        static void convert(const std::string &literal);
};