/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:30:30 by armohame          #+#    #+#             */
/*   Updated: 2025/02/04 13:29:54 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main(int ac, char **av)
{
    std :: string name;

    for(int i = 1; i < ac; i++)
    {
        for(int j = 0; av[i][j]; j++)
            av[i][j] = toupper(av[i][j]);
        std::cout << av[i];
    }
    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    return 0;
}


// int main(int ac, char **av)
// {
//     std :: string name;
//     int age;

//     std::cout << "name is : ";
//     std::cin >> name;
//     std::cout << "age is : ";
//     std::cin >> age;
//     for(char &c : name)
//         c = std::toupper(c);
//     std::cout << "age is : " << age << " name :" << name ;
//     return 0;
// }