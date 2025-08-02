#include "BitcoinExchange.hpp"

int main () {
  BitcoinExchange c;

  std::ifstream myfile;
  myfile.open ("data.csv");
  try{
    if(!myfile.is_open())
      throw std::ios_base::failure("Impossible d’ouvrir le fichier : data.csv");
    else
      c.getLineData(myfile);
    myfile.close();
  }
  catch (std::exception &e){
    std::cerr << e.what() << std::endl;
  }
  std::cout << "e.what()" << std::endl;

  //

  std::ifstream myinput;
  myinput.open ("input.csv");
  try{
    if(!myinput.is_open())
      throw std::ios_base::failure("Impossible d’ouvrir le fichier : intput.csv");
    else
      c.getLineInput(myinput);
    myinput.close();
  }
  catch (std::exception &e){
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
