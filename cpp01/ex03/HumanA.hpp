/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:15:46 by armohame          #+#    #+#             */
/*   Updated: 2025/02/28 14:47:04 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanA{
    private:
        std::string         name_;
        Weapon&           Weapon_;
    public:
        HumanA( std::string name_, Weapon& club );
        ~HumanA();
        void attack();
};

# endif