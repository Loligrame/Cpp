#include "BitcoinExchange.hpp"

BitcoinExchange:: BitcoinExchange() {}

BitcoinExchange:: BitcoinExchange (const BitcoinExchange &obj){
    if(this != &obj)
      this->database = obj.database;
}

BitcoinExchange&  BitcoinExchange:: operator=(const BitcoinExchange &obj){
    if(this != &obj)
      this->database = obj.database;
    return *this;
}

BitcoinExchange:: ~BitcoinExchange(){}

static bool isValidDate(std::string DateLine){
  if(DateLine.length() != 10)
    return false;
  if(DateLine[4] != '-' || DateLine[7] != '-' )
    return false;
  for(size_t i = 0; i < 10; ++i){
    if(DateLine[4] == '-' && DateLine[7] == '-' )
      continue;
    if(!std::isdigit(DateLine[i]))
          return false;
  }
  int year = std::atoi(DateLine.substr(0, 4).c_str());
  int month = std::atoi(DateLine.substr(5, 2).c_str());
  int day = std::atoi(DateLine.substr(8, 2).c_str());
  if (year < 2008 || year > 2025)
      return false;
  if (month < 1 || month > 12)
      return false;
  if (day < 1 || day > 31)
      return false;
  return true;
}

bool isHeader(const std::string& line) {
    return line.find("date") != std::string::npos;
}

void BitcoinExchange:: getLineData(std::ifstream &myfile) {
  std::string line;
  while(std::getline(myfile, line)){
    if(isHeader(line))
      continue;
    std::istringstream ss(line);
    std::string DateData;
    std::string ValueLine;
    std::getline(ss, DateData, ',');
      if(!isValidDate(DateData))
        throw std::invalid_argument("Error: Invalid Data date, expected format YYYY-MM-DD\n");
    std::getline(ss, ValueLine);
    float value = strtof(ValueLine.c_str(), NULL);
      if(value < 0)
        throw std::invalid_argument("Data Error: not a positive number.\n");
    database.insert(std::make_pair(DateData, value));
  }
}

void BitcoinExchange:: valueCalculator(std::string DateInput, float Quantity){
  
  std::map<std::string, float>::iterator it = database.lower_bound(DateInput);
  if(it == database.begin())
    std::cerr << "Error: no date before " << DateInput << " in the database.\n";
  else
    --it;
  float money = it->second * Quantity;
  std::cout << DateInput << "  => " << std::fixed << std::setprecision(2) << Quantity << " = "<< money << "\n";
}

static bool isValidLine(const std::string& date, char pipe, float quantity) {
  if (!isValidDate(date)) {
    std::cerr << "Error: Invalid date\n";
    return false;
  }
  if (pipe != '|') {
    std::cerr << "Error: invalid separator\n";
    return false;
  }
  if (quantity > 1000) {
    std::cerr << "Error: too large a number.\n";
    return false;
  }
  if (quantity < 0) {
    std::cerr << "Error: not a positive number.\n";
    return false;
  }
  return true;
}

void BitcoinExchange:: getLineInput(std::ifstream &myinput) {
  std::string line;
  while(std::getline(myinput, line)){
    if(isHeader(line))
      continue;
    std::istringstream ss(line);
    std::string DateInput;
    float Quantity;
    char pipe = '\0';
    ss >> DateInput >> pipe >> Quantity;
    if(isValidLine(DateInput, pipe, Quantity))
      valueCalculator(DateInput, Quantity);
  }
}