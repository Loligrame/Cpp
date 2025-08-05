#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange{
    private :
        std::map<std::string, float> database;
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        ~BitcoinExchange();
        void valueCalculator(std::string DateInput, float value);
        void getLineData(std::ifstream &myfile);
        void getLineInput(std::ifstream &myinput);
};