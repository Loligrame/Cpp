/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:14:03 by armohame          #+#    #+#             */
/*   Updated: 2025/02/14 14:57:03 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int isValidPhoneNum(const std::string& phone)
{
    if(phone.length() != 10)
        return false;
    for(int i = 0; i < 10; i++)
    {
        if(!isdigit(phone[i]))
            return false;
    }
    return true;
}

std::string Truncate(std::string str)
{
    if(str.length() > 10)
        str = str.substr(0, 9) + ".";
    return str;
}

void Contact::Display(int index)
{
    if (index == 0)
    {
        std::cout << " ______________________________________________ " << std::endl;
        std::cout << " | index |    name    |   secret   |   phone  | " << std::endl;
    }
    std::cout << " |     " << index + 1
              << " | " << std::setw(10) << Truncate(name)  // Truncate name to 10 chars
              << " | " << std::setw(10) << Truncate(secret) // Truncate secret to 10 chars
              << " | " << std::setw(10) << phone.substr(0, 10) << " | "  // Truncate phone to 10 chars
              << std::endl;
}
    
void Contact:: WriteContact(void)
{
        int i = 0;
        std::cout << i + 1 << " Enter name : " << std::endl;
        std::getline(std::cin, name);
        do {
            std::cout << i + 1 << " Enter Phone : " << std::endl;
            std::getline(std::cin, phone);
                if(std::cin.eof())
                    break;
                if(!isValidPhoneNum(phone))
                    std::cout << red << "Enter a valid phone number" << reset << std::endl;;
        }while(!isValidPhoneNum(phone));
        std::cout << i + 1 << " Enter Secret : " << std::endl;
        std::getline(std::cin, secret);  
}

void PhoneBook:: AddContact(void)
{ 
        for(index = 0; index < 2; index++)
            _Contact[index].WriteContact();
        for(index = 0; index < 2; index++)
            _Contact[index].Display(index);
}

int main()
{   
    PhoneBook add;
    add.AddContact();
    return 0;
}