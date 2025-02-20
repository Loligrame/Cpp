/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:30:30 by armohame          #+#    #+#             */
/*   Updated: 2025/02/20 12:38:32 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> 
#include <string> 

int main(int ac, char **av)
{
    std :: string name;

    for(int i = 1; i < ac; i++)
    {
        for(int j = 0; av[i][j]; j++)
            av[i][j] = std::toupper(av[i][j]);
        std::cout << av[i];
    }
    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    return 0;
}