/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:20:25 by armohame          #+#    #+#             */
/*   Updated: 2025/02/28 15:00:03 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA:: HumanA( std::string name, Weapon& club ) : name_(name), Weapon_(club) 
{
}

HumanA:: ~HumanA( void )
{
}

void HumanA:: attack()
{
    std::cout << name_ << " attacks with their " << Weapon_.getType() << std::endl;
}