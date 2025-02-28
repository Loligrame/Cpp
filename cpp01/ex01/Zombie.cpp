/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:05:33 by armohame          #+#    #+#             */
/*   Updated: 2025/02/27 11:50:04 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
    
}

Zombie::Zombie( std::string name ) : name_(name)
{
    
}

Zombie::~Zombie( void )
{
    std::cout << this->name_ << " Destructor called" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name( std::string name )
{
    this->name_ = name;
    return ;
}

Zombie* newZombie( std::string name )
{
    Zombie *New_z = new Zombie(name);
    return New_z;
}