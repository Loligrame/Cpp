/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:07:38 by armohame          #+#    #+#             */
/*   Updated: 2025/02/27 11:49:44 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int Horde = 3;
    Zombie* Horde_member = zombieHorde( Horde, "Joe");
    for(int i = 0; i < Horde; i++)
    {
        std::cout << "Number " << i + 1 << " ";
        Horde_member[i].announce();
    }
    delete[] Horde_member;
    return 0;
}