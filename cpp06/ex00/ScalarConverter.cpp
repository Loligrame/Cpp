#include "ScalarConverter.hpp"

ScalarConverter:: ~ScalarConverter(){}

void ScalarConverter:: convert(const std::string &literal){
        if(isInt(literal))
            intConvert(literal);
        if(isChar(literal))
            charConvert(literal);
        else
            std::cout << "sdf\n";
}

bool isInt(const std::string &literal){
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

bool isFloat(const std::string &literal){
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
        if(literal[i] == 'f' && literal[i + 1] == 0)
            return true;
    }
    return false;
}

bool  isDouble(const std::string &literal){
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
            i++;
        }
        if(!isdigit(literal[i]))
                return false;
    }
    return has_dot;
}

bool  isChar(const std::string &literal){
    size_t i = 0;
    if(literal.size() == 3 && literal[i] == '\'' && literal[literal.size() - 1] == '\'')
        return isprint(literal[1]);
    return false;
}

bool  isPseudoLiteral(const std::string &literal){
    std::string pseudo[] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
    for(size_t i = 0;i < 6; ++i)
    {
        if(literal == pseudo[i])
            return true;
    }
    return false;
}

void intConvert(const std::string &literal){
    char* end;
    errno = 0;
    long lit =  strtol(literal.c_str(), &end, 10);
    if (errno == ERANGE)
        std::cout << "Overflow détecté ✅" << std::endl;
    if(lit < 0 || lit > 127)
        std::cout << "This is not a char" << std::endl;
    if(!isprint(literal))
        std::cout << "This char is not printable" << std::endl;
    std::cout << lit << std::endl;
    std::cout << static_cast<char>(lit) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << static_cast<double>(lit) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(lit) << "f"<< std::endl;

}

void charConvert(const std::string &literal){
    int lit = atoi(literal[1]);
    std::cout << lit << std::endl;
    std::cout << std::fixed << std::setprecision(2) << static_cast<double>(lit) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << static_cast<float>(lit) << "f"<< std::endl;
}

// static void		minInfConvert() {
// 	std::cout << BOLD_RED << "char: impossible" << RESET << std::endl;
// 	std::cout << BOLD_GREEN << "int: impossible" << RESET << std::endl;
// 	std::cout << BOLD_YELLOW << "float: " << NegativeInfinityFloat << RESET << std::endl;
// 	std::cout << BOLD_MAGENTA << "double: " << NegativeInfinity << RESET << std::endl;
// }
