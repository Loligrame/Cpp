/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:14:11 by armohame          #+#    #+#             */
/*   Updated: 2025/02/12 14:44:20 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#define red "\033[1m\033[31m"
#define reset "\033[0m"

#include <iostream>
#include <string>
#include <cstring>
#include "Contact.hpp"

class PhoneBook
{
    public:
    int index;
    Contact _Contact[8];
    void AddContact(void);
};

# endif