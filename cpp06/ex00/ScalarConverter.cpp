#include "ScalarConverter.hpp"

ScalarConverter:: ~ScalarConverter(){}

static bool isInt(const std::string &literal){
    size_t i = 0;
    if(literal.empty())
        return false;
    if(literal[i] == '-' || literal[i] == '+'  )
        i++;
    if(i == literal.size())
        return false;
    for(;i < literal.size(); i++)
    {
        if(!isdigit(literal[i]))
            return false;
    }
    return true;
}

static bool isFloat(const std::string &literal){
    if(literal.empty())
        return false;
    size_t i = 0;
    if(literal[i] == '-' || literal[i] == '+' )
        i++;
    if(i == literal.size() || !isdigit(literal[i]))
        return false;
    bool has_dot = false;
    for(;i < literal.size(); ++i)
    {
        if(isdigit(literal[i]))
            continue;
        if(literal[i] == '.')
        {   
            if(i + 1 >= literal.size() ||!isdigit(literal[i + 1]))
                return false;
            if(has_dot)
                return false;
            has_dot = true;
        }
        if(literal[i] == 'f' && i == literal.size() - 1)
            return true;
    }
    return false;
}

static bool  isDouble(const std::string &literal){
    if(literal.empty())
    return false;
    size_t i = 0;
    if(literal[i] == '-' || literal[i] == '+' )
        i++;
    if(i == literal.size() || !isdigit(literal[i]))
        return false;
    bool has_dot = false;
    for(;i < literal.size(); ++i)
    {
        if(isdigit(literal[i]))
            continue;
        else if(literal[i] == '.')
        {   
            if(has_dot)
                return false;
            if(i + 1 >= literal.size() ||!isdigit(literal[i + 1]))
                return false;
            has_dot = true;
            continue;
        }
        else
            return false;
    }
    return has_dot;
}

static bool  isChar(const std::string &literal){
    if(literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
        return true;
    return false;
}

static void		nanConvert() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "double: nan" << std::endl;
	std::cout << "float: nanf" << std::endl;
}

static void		neginfConvert() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "double: -inf" << std::endl;
	std::cout << "float: -inff" << std::endl;
}

static void		infConvert() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "double: inf" << std::endl;
	std::cout << "float: inff" << std::endl;
}

static void doubleConvert(const std::string &literal){
    char* end;
    errno = 0;
    double lit =  strtod(literal.c_str(), &end);
    if (errno == ERANGE || std::isinf(lit) || lit > DBL_MAX || lit < -DBL_MAX) {
        std::cout << "Double : Overflow détecté ✅" << std::endl;
        return;
    }
    if(lit < 0 || lit > 127)
        std::cout << "This is not a char" << std::endl;
    else if(!isprint(lit))
        std::cout << "This char is not printable" << std::endl;
    else
        std::cout << "Char : " << static_cast<char>(lit) << std::endl;
    if (lit <= INT_MAX && lit >= INT_MIN)
        std::cout << "Int : " << static_cast<int>(lit) << std::endl;
    else
        std::cout << "Int : Overflow" << std::endl;
    std::cout << "Double : " << std::fixed << std::setprecision(1) << lit << std::endl;
    float f = static_cast<float>(lit);
    if (std::isinf(f))
        std::cout << "Float : Overflow" << std::endl;
    else
        std::cout << "Float : " << std::fixed << std::setprecision(1) << static_cast<float>(lit) << "f"<< std::endl;
}

static void floatConvert(const std::string &literal){
    char* end;
    errno = 0;
    float lit =  strtof(literal.c_str(), &end);
    if (errno == ERANGE) {
        std::cout << "Double : Overflow détecté ✅" << std::endl;
        return;
    }
    if(lit < 0 || lit > 127)
        std::cout << "This is not a char" << std::endl;
    else if(!isprint(lit))
        std::cout << "This char is not printable" << std::endl;
    else
        std::cout << "Char : " << static_cast<char>(lit) << std::endl;
    if (static_cast<int>(lit) < INT_MAX && static_cast<int>(lit) > INT_MIN)
        std::cout << "Int : " << static_cast<int>(lit) << std::endl;
    else
        std::cout << "Int :  Overflow" << std::endl;
    std::cout << "Double : " << std::fixed << std::setprecision(1) << static_cast<double>(lit) << std::endl;
    std::cout << "Float : " << std::fixed << std::setprecision(1) << lit << "f"<< std::endl;
}

static void intConvert(const std::string &literal){
    char* end;
    errno = 0;
    long lit =  strtol(literal.c_str(), &end, 10);
    if (errno == ERANGE)
    {
        std::cout << "Overflow détecté ✅" << std::endl;
        return;
    }
    if(lit < 0 || lit > 127)
        std::cout << "This is not a char" << std::endl;
    else if(!isprint(lit))
        std::cout << "This char is not printable" << std::endl;
    else
        std::cout << "Char : " << static_cast<char>(lit) << std::endl;
    if (lit < INT_MAX && lit > INT_MIN)
        std::cout << "Int : " << static_cast<int>(lit) << std::endl;
    else
        std::cout << "Int :  Overflow" << std::endl;
    std::cout << "Double : " << std::fixed << std::setprecision(1) << static_cast<double>(lit) << std::endl;
    if (static_cast<float>(lit) > FLT_MAX || static_cast<float>(lit) < -FLT_MAX)
        std::cout << "Is Float: Overflow" << std::endl;
    else
        std::cout << "Float : " << std::fixed << std::setprecision(1) << static_cast<float>(lit) << "f"<< std::endl;
}

static void charConvert(const std::string &literal){
    char c = literal[0];
    if(c < 0 || c > 127)
        std::cout << "This is not a char" << std::endl;
    else if(!isprint(c))
        std::cout << "This char is not printable" << std::endl;
    else
        std::cout << "Char : " << c << std::endl;
    if (static_cast<int>(c) < INT_MAX && static_cast<int>(c) > INT_MIN)
        std::cout << "Int : " << static_cast<int>(c) << std::endl;
    else
        std::cout << "Int :  Overflow" << std::endl;
    std::cout << "Double : " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
    if (static_cast<float>(c) > FLT_MAX || static_cast<float>(c) < -FLT_MAX)
        std::cout << "Is Float: Overflow" << std::endl;
    else
        std::cout << "Float : " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f"<< std::endl;
}

void ScalarConverter:: convert(const std::string &literal){
        if(isInt(literal))
            intConvert(literal);
        else if(isChar(literal))
            charConvert(literal);
        else if(isFloat(literal))
            floatConvert(literal);
        else if(isDouble(literal))
            doubleConvert(literal);
        else if (literal == "nan" || literal == "nanf") 
            nanConvert();
        else if (literal == "-inf" || literal == "-inff") 
            neginfConvert();
        else if (literal == "+inf" || literal == "+inff") 
            infConvert();
        else
            std::cerr << "Not a valid value" << std::endl;
}
