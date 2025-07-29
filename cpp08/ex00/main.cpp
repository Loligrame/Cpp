#include "easyfind.hpp"

int main(){
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(45);
    vec.push_back(8);

    int nb = easyfind(vec, 45);
    if(nb == -1)
        std::cerr << "Number not present\n";
    else
        std::cout << "Number is present at index : " << nb << std::endl; 
    return 0;
}
