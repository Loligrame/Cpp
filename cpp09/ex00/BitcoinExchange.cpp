#include "BitcoinExchange.hpp"

BitcoinExchange:: BitcoinExchange() {}

BitcoinExchange:: BitcoinExchange (const BitcoinExchange &obj){
    if(this != &obj){
    }
}

BitcoinExchange&  BitcoinExchange:: operator=(const BitcoinExchange &obj){
    if(this != &obj){
    }
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

void BitcoinExchange:: getLineData(std::ifstream &myfile) {
  std::string line;
  while(std::getline(myfile, line)){
    std::istringstream ss(line);
    std::string DateData;
    std::string ValueLine;
    std::getline(ss, DateData, ',');
    try{
      if(!isValidDate(DateData))
        throw std::invalid_argument("Invalid date, expected format : YYYY-MM-DD\n");
    }
    catch(const std::exception &e){
      std::cerr << e.what() << std::endl;
    }
    std::getline(ss, ValueLine);
    float value = strtof(ValueLine.c_str(), NULL);
    try{
      if(value < 0)
        throw std::invalid_argument("Invalid value\n");
    }
    catch(const std::exception &e){
      std::cerr << e.what() << std::endl;
    }
    database.insert(std::make_pair(DateData, value));
  }
}

void BitcoinExchange:: valueCalculator(std::string DateInput, float Quantity){
  
  std::map<std::string, float>::iterator it = database.lower_bound(DateInput);
  if(it == database.begin())
    std::cerr << "Erreur : aucune date avant " << DateInput << " dans la database.\n";
  else
    --it;
  float money = it->second * Quantity;
  std::cout << DateInput << "  => " << Quantity << " = "<< money << "\n\n";
}

bool isHeader(const std::string& line) {
    return line.find("date") != std::string::npos;
}

void BitcoinExchange:: getLineInput(std::ifstream &myinput) {
  std::string line;
  int line_count = 0;
  while(std::getline(myinput, line)){
    std::istringstream ss(line);
    std::string DateInput;
    float Quantity;
    char pipe = '\0';
    ss >> DateInput >> pipe >> Quantity;
    try{
      if(line_count == 0 && !isHeader(line))
        std::getline(myinput, line);
      else if(!isValidDate(DateInput))
        throw std::invalid_argument("Invalid date, expected format : YYYY-MM-DD\n");
    }
    catch(const std::exception &e){
      std::cerr << e.what() << std::endl;
    }
    // std::cout << "Quantity : " << Quantity << std::endl ;
    if(pipe != '|')
      throw std::invalid_argument("Invalid line\n");
    try{
      if(Quantity < 0 || Quantity > 1000  )
        throw std::invalid_argument("Invalid Quantity\n");
    }
    catch(const std::exception &e){
      std::cerr << e.what() << std::endl;
    }
    valueCalculator(DateInput, Quantity);
    line_count++;
  }
}