/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:08:01 by armohame          #+#    #+#             */
/*   Updated: 2025/02/28 14:54:08 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon{
    private:
        std::string type_;
    public:
        Weapon();
        ~Weapon();
        Weapon(std::string type);
        const std::string& getType();
        void setType(std::string NewType);
};

# endif