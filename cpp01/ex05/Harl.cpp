/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:36:33 by armohame          #+#    #+#             */
/*   Updated: 2025/03/04 10:56:12 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl:: debug( void )
{
    std::cout << std::endl << bold << "DEBUG :" << reset << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl:: error( void )
{
    std::cout << std::endl << red << "ERROR :" << reset << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl:: warning( void )
{
    std::cout << std::endl << yellow << "WARNING :" << reset << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl:: info( void )
{
    std::cout << std::endl << blue << "INFO :" << reset << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl:: complain( std::string level )
{
    std::string type[4] = {"DEBUG", "ERROR", "WARNING", "INFO"};
    void (Harl::*funct[4])() = {&Harl::debug, &Harl::error, &Harl::warning, &Harl::info};

    for(int i = 0; i < 4; i++)
    {
        if(!level.compare(type[i]))
        {
            (this->*funct[i])();
        }
    }
}
