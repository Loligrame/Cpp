#include "easyfind.hpp"


int main(){
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(45);
    vec.push_back(8);


    if(easyfind(vec, 8) == -1)
        std::cerr << "Number not present\n";
    else
        std::cout << "Number is present at index : " << easyfind(vec, 8) << std::endl; 
    return 0;
}