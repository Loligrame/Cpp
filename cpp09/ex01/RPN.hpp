#include <iostream>
#include <algorithm>
#include <stack>
#include <exception>
#include <ctime>
#include <limits>
#include <sstream>
#include <string>
#include <cstdlib>

class RPN{
    private :
        std::stack<int> pile;
    public :
        RPN();
        RPN(const RPN& obj);
        RPN& operator=(const RPN& obj);
        ~RPN();
        void parseline(std::string op);
        void addNumber(int a);
        void operation(char sign);
};