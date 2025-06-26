#include "ScalarConverter.hpp"

int main(int argc, char** argv){
    if (argc != 2)
        return 1;
    std::string pop = argv[1];
    std::cout << "Is Double "<< isDouble(pop) << std::endl;
    std::cout << "Is Float " << isFloat(pop) << std::endl;
    std::cout << "Is Char " << isChar(pop) << std::endl;
    std::cout << "Is Pseudo literal " << isPseudoLiteral(pop) << std::endl;
    std::cout << "Is int " << isInt(pop) << std::endl;
    ScalarConverter::convert(pop);
}