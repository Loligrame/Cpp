/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:14:11 by armohame          #+#    #+#             */
/*   Updated: 2025/02/14 13:41:54 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#define red "\033[1m\033[31m"
#define reset "\033[0m"

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook{
    private:
        int index;
        Contact _Contact[8];
    public:
        void AddContact(void);
};

# endif