#include "ScalarConverter.hpp"

int main(int argc, char** argv){

        if (argc != 2){
        std::cerr << "Wrong arg number" << std::endl;
        return 1;
    }
    std::string pop = argv[1];
    ScalarConverter::convert(pop);
    return 0;
}