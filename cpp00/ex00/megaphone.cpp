/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:30:30 by armohame          #+#    #+#             */
/*   Updated: 2025/02/21 09:23:06 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> 
#include <string> 

int main(int ac, char **av)
{
    for(int i = 1; i < ac; i++)
    {
        for(int j = 0; av[i][j]; j++)
            av[i][j] = std::toupper(av[i][j]);
        std::cout << av[i];
    }
    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}