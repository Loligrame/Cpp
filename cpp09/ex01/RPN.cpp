#include "RPN.hpp"

RPN:: RPN(){}

RPN:: RPN(const RPN &obj){
    this->pile = obj.pile;
}

RPN& RPN:: operator=(const RPN& obj){
    if(this != &obj){
        this->pile = obj.pile;
    }
    return *this;
}

RPN:: ~RPN(){}

void RPN:: operation(char sign){
    
    if(pile.size() < 2){
        std::cerr << "Not enough int's" << std::endl;
        return;
    }
    int b = pile.top();
    pile.pop();
    int a = pile.top();
    pile.pop();
    int result = 0;
    if(sign == '+')
        result = a + b;
    else if(sign == '/'){
        if(b == 0){
            std::cerr << "Division by zero is invalid" << std::endl;
            return;
        }
        result = a / b;
    }
    else if(sign == '-')
        result = a - b;
    else if(sign == '*')
        result = a * b;
    pile.push(result);
}

void RPN:: parseline(std::string op){
    for(int i = 0; op[i]; ++i){
        if(isdigit(op[i]) && op[i + 1] == ' ')
            addNumber(op[i] - '0');
        else if((op[i] == '+' || op[i] == '/' || op[i] == '*' || op[i] == '-') && pile.size() > 1)
            operation(op[i]);
        else if(op[i] == ' ')
            continue;
        else
            throw std::invalid_argument("Error\n");
    }
    if(pile.size() == 1)
        std::cout << pile.top() << std::endl;
    else
        std::cerr << "Invalid RPN expression: remaining items in stack\n";
}

void RPN:: addNumber(int a){
    pile.push(a);
}
