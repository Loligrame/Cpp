/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:14:03 by armohame          #+#    #+#             */
/*   Updated: 2025/02/26 12:50:53 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name_(name)
{
    
}

Zombie::~Zombie( void )
{
    std::cout << "Destructor called" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}