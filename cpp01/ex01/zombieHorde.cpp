/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:04:03 by armohame          #+#    #+#             */
/*   Updated: 2025/02/27 11:21:58 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    if(N <= 0)
        std::cout << "Wrong number of Zombies" << std::endl;
    Zombie* horde_member = new Zombie[N];
    while (N-- > 0)
        horde_member[N].set_name(name);
    return horde_member;
}