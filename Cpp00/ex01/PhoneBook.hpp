/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:14:11 by armohame          #+#    #+#             */
/*   Updated: 2025/02/20 11:12:50 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#define red "\033[1m\033[31m"
#define bold "\033[1m"
#define green "\033[1m\033[32m"
#define yellow "\033[1m\033[33m"
#define blue "\033[1m\033[34m"
#define reset "\033[0m"

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook{
    private:
        int contact_num;
        Contact _Contact[8];
    public:
        PhoneBook() : contact_num(0) {}
        void AddContact(int index);
        void SearchContact();
        void DisplayAll();
};

# endif