/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:13:43 by armohame          #+#    #+#             */
/*   Updated: 2025/02/28 14:46:42 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB{
    private:
        std::string     name_;
        Weapon       *Weapon_;
    public:
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon& NewWeapon);
        void attack();
};

# endif