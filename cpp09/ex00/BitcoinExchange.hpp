#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <cstdlib>

class BitcoinExchange{
    private :
        int _yearData;
        int _monthData;
        int _dayData;
        int _yearInput;
        int _monthInput;
        int _dayInput;
        int _value;
        int _quantity;
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        ~BitcoinExchange();
        void getLineData(std::ifstream &myfile);
        void getLineInput(std::ifstream &myinput);
};