/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:25:43 by armohame          #+#    #+#             */
/*   Updated: 2025/02/28 15:01:28 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB:: HumanB(std::string name) : name_(name), Weapon_(NULL)
{
}

HumanB:: ~HumanB()
{
}

void HumanB:: attack()
{
    std::cout << this->name_ << " attacks with their " << Weapon_->getType() << std::endl;
}

void    HumanB:: setWeapon(Weapon& NewWeapon)
{
    this->Weapon_ = &NewWeapon;
}