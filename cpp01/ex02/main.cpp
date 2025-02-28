/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:07:38 by armohame          #+#    #+#             */
/*   Updated: 2025/02/27 13:10:26 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#define yellow "\033[1m\033[33m"
#define bold "\033[1m"
#define reset "\033[0m"

int main()
{
    int width = 40; 
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;
    
    std::cout << std::setw((width + brain.length()) / 2) << yellow << "--ADRESSES--" << reset << std::endl;

    std::cout << bold << "The memory address of the string variable : " << reset << &brain << std::endl;
    std::cout << bold << "The memory address held by stringPTR : " << reset << stringPTR << std::endl;
    std::cout << bold << "The memory address held by stringREF : " << reset << &stringREF << std::endl;

    std::cout << std::endl << std::setw((width + brain.length()) / 2) << yellow << "--VALUES--" << reset << std::endl;
    std::cout << bold << "The value of the string variable : " << reset << brain << std::endl;
    std::cout << bold << "The value pointed to by stringPTR : " << reset << *stringPTR << std::endl;
    std::cout << bold << "The value pointed to by stringREF : " << reset << stringREF << std::endl;
    return 0;
}