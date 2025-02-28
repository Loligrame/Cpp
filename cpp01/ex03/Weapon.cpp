/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:19:07 by armohame          #+#    #+#             */
/*   Updated: 2025/02/28 15:07:05 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon:: Weapon()
{
}
Weapon:: Weapon(std::string type)
{
    this->type_ = type;
}

Weapon:: ~Weapon()
{
}


const std::string& Weapon::  getType() 
{
    return type_;
}

void Weapon:: setType(std::string NewType)
{
    this->type_ = NewType;
}
