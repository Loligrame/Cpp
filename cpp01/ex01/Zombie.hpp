/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:14:11 by armohame          #+#    #+#             */
/*   Updated: 2025/02/27 11:45:01 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#define red "\033[1m\033[31m"
#define bold "\033[1m"
#define green "\033[1m\033[32m"
#define yellow "\033[1m\033[33m"
#define blue "\033[1m\033[34m"
#define reset "\033[0m"

#include <iostream>

class Zombie{
    private:
        std::string name_;
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie();
        void announce( void );
        void set_name(std::string name);
};
    Zombie* zombieHorde( int N, std::string name);
    Zombie* newZombie( std::string name );
# endif