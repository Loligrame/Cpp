// #include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <cstdlib>

void getDate(std::ifstream &myfile) {
  std::string line;
  while(std::getline(myfile, line)){
    int year = 0;
    int month = 0;
    int day = 0;
    
    char sep_1 = 0;
    char sep_2 = 0;
    char comma = 0;
    
    std::istringstream ss(line);
    try{
      ss >> year >> sep_1 >> month >> sep_2 >> day;
      if(ss.fail() || sep_1 != '-' || sep_2 != '-')
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
    ss >> comma;
    std::string str_value;
    std::getline(ss , str_value);
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
  }
}

int main () {
  std::ifstream myfile;
  myfile.open ("data.csv");
  try{
    if(!myfile.is_open())
      throw std::ios_base::failure("Impossible d’ouvrir le fichier : ");
    else
      getDate(myfile);
    myfile.close();
  }
  catch (std::exception &e){
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
