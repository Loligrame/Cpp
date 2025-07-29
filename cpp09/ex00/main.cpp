#include "BitcoinExchange.hpp"

int main () {
  std::ifstream myfile;
  myfile.open ("data.csv");
  try{
    if(!myfile.is_open())
        throw std::ios_base::failure("Impossible d’ouvrir le fichier : ");
  }
  catch (std::exception &e){
    std::cerr << e.what() << std::endl;
  }
  
  std::string line;
  while(std::getline(myfile, line))
    std::cout << line << std::endl;
  myfile.close();
  return 0;
}
