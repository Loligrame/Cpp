#include "RPN.hpp"

int main(int ac, char **av){
  if(ac != 2){
    std::cerr << "Put an argument" << std::endl;
    return 1;
  }
  RPN c;
  try { c.parseline(av[1]);}
  catch(std::exception &e){
    std::cout << e.what();
  }
  return 0;
}