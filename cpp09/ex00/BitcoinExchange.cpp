#include "BitcoinExchange.hpp"


BitcoinExchange:: BitcoinExchange() : _yearData(0), _monthData(0), _dayData(0),  
_yearInput(0), _monthInput(0), _dayInput(0), _value(0), _quantity(0){}

BitcoinExchange:: BitcoinExchange (const BitcoinExchange &obj){
    if(this != &obj){
        this->_yearData = obj._yearData;
        this->_monthData = obj._monthData;
        this->_dayData = obj._dayData;
        this->_value = obj._value;
        this->_yearInput = obj._yearInput;
        this->_monthInput = obj._monthInput;
        this->_dayInput = obj._dayInput;
        this->_quantity = obj._quantity;
    }
}

BitcoinExchange&  BitcoinExchange:: operator=(const BitcoinExchange &obj){
    if(this != &obj){
        this->_yearData = obj._yearData;
        this->_monthData = obj._monthData;
        this->_dayData = obj._dayData;
        this->_value = obj._value;
        this->_yearInput = obj._yearInput;
        this->_monthInput = obj._monthInput;
        this->_dayInput = obj._dayInput;
        this->_quantity = obj._quantity;
    }
    return *this;
}

BitcoinExchange:: ~BitcoinExchange(){}

void BitcoinExchange:: getLineData(std::ifstream &myfile) {
  std::string line;
  while(std::getline(myfile, line)){
    int year = 0;
    int month = 0;
    int day = 0;
    
    char sep_1 = 0;
    char sep_2 = 0;
    char comma = 0;
    
    std::istringstream DataLine(line);
    try{
      DataLine >> year >> sep_1 >> month >> sep_2 >> day;
      if(DataLine.fail() || sep_1 != '-' || sep_2 != '-')
          throw std::invalid_argument("Invalid date format: expected YYYY-MM-DD\n");
      if(year < 2008 || year > 2025)
        throw std::invalid_argument("Invalid year, bitcoin did not exist at that time\n");
      if(month < 1 || month > 12)
        throw std::invalid_argument("Invalid month\n");
      if(day < 1 || day > 31)
        throw std::invalid_argument("Invalid day\n");
    }
    catch(const std::exception &e){
      std::cerr << e.what() << std::endl;
    }
    DataLine >> comma;
    std::string str_value;
    std::getline(DataLine , str_value);
    float value = strtof(str_value.c_str(), NULL);
    try{
      if(value < 0)
        throw std::invalid_argument("Not a valid value number\n");
    }
    catch(const std::exception &e){
      std::cerr << e.what() << std::endl;
    }
    std::cout << year << sep_1 << month << sep_2 << day << 
    comma << value << std::endl;
    this->_yearData = year;
    this->_monthData = month;
    this->_dayData = day;
    this->_value = value;
  }
}

void BitcoinExchange:: getLineInput(std::ifstream &myinput) {
  std::string line;
  while(std::getline(myinput, line)){
    int year = 0;
    int month = 0;
    int day = 0;
    
    char sep_1 = 0;
    char sep_2 = 0;
    char comma = 0;
    
    std::istringstream InputLine(line);
    try{
      InputLine >> year >> sep_1 >> month >> sep_2 >> day;
      if(InputLine.fail() || sep_1 != '-' || sep_2 != '-')
          throw std::invalid_argument("Invalid date format: expected YYYY-MM-DD\n");
      if(year < 2008 || year > 2025)
        throw std::invalid_argument("Invalid year, bitcoin did not exist at that time\n");
      if(month < 1 || month > 12)
        throw std::invalid_argument("Invalid month\n");
      if(day < 1 || day > 31)
        throw std::invalid_argument("Invalid day\n");
    }
    catch(const std::exception &e){
      std::cerr << e.what() << std::endl;
    }
    InputLine >> comma;
    std::string str_quantity;
    std::getline(InputLine , str_quantity);
    float quantity = strtof(str_quantity.c_str(), NULL);
    try{
      if(quantity < 0 || quantity > 1000)
        throw std::invalid_argument("Not a valid quantity number\n");
    }
    catch(const std::exception &e){
      std::cerr << e.what() << std::endl;
    }
    std::cout << year << sep_1 << month << sep_2 << day << 
    comma << quantity << std::endl;
    this->_yearInput = year;
    this->_monthInput = month;
    this->_dayInput = day;
    this->_quantity = quantity;
  }
}

// bool  BitcoinExchange:: isClosestDate(){

// }