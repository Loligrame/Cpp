/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:14:11 by armohame          #+#    #+#             */
/*   Updated: 2025/02/11 13:44:14 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstring>

class PhoneBook
{
    public:
        std::string name;
        std::string phone;
        std::string secret;    
        // PhoneBook(std::string n, std::string p, std::string s)
        // {
        //     name = n;
        //     phone = p;
        //     secret = s;
        // }
    void display()
    {
        std::cout << " name : " << name  << std::endl;
        std::cout << " phone : " << phone << std::endl;
        std::cout << " secret : " << secret << std::endl;
    }
};

# endif