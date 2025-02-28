/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:07:38 by armohame          #+#    #+#             */
/*   Updated: 2025/02/26 12:49:52 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *newZom = newZombie("Arshe");
    randomChump("Yoro");
    newZom->announce();
    delete newZom;
    return 0;
}