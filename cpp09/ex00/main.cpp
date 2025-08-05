#include "BitcoinExchange.hpp"

int main (int ac, char **av) {
  if(ac != 2)
    std::cerr << "Put a csv file as an argument" << std::endl;

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
    return 1;
  }
  std::ifstream myinput;
  myinput.open (av[1]);
  try{
    if(!myinput.is_open())
      throw std::ios_base::failure("Impossible d’ouvrir le fichier : intput.csv");
    else
      c.getLineInput(myinput);
    myinput.close();
  }
  catch (std::exception &e){
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}