/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:14:03 by armohame          #+#    #+#             */
/*   Updated: 2025/02/12 11:42:59 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <cctype>

int isValidPhoneNum(const std::string& phone)
{
    if(phone.length() != 10)
    {
        std::cout << "is not valid" << std::endl;
        return false;
    }
    for(int i = 0; i < 10; i++)
    {
        std::cout << "is a valid phone number" << std::endl;
        if(!isdigit(phone[i]))
            return false;
    }
    std::cout << "is a valid phone number" << std::endl;
    return true;
}

int main()
{
    PhoneBook *contact = new PhoneBook[2];
    
    for(int i = 0;  i < 2; i++)
    {
        std::cout << i + 1 << " Enter name : " << std::endl;
        std::getline(std::cin, contact[i].name);
        do {
            std::cout << i + 1 << " Enter Phone : " << std::endl;
            std::getline(std::cin, contact[i].phone);
                if(!std::cin.eof())
                {
                    std::cout << std::endl;
                    break;
                }
                if(!isValidPhoneNum(contact[i].phone))
                {
                    std::cout << "Enter a valid phone number" << std::endl;
                }
        }while(!isValidPhoneNum(contact[i].phone));
        std::cout << i + 1 << " Enter Secret : " << std::endl;
        std::getline(std::cin, contact[i].secret);  
    }
    for(int i = 0;  i < 2; i++)
    {
        contact[i].display();
    }
    delete[] contact;
    return 0;
}

// int main()
// {
//     PhoneBook p1("Sophie", "010", "Je me touche" );
//     PhoneBook p2("Bertrand", "011", "Moi aussi" );
    
//     std::cin >> "Enter name :";
//     p1.display();
//     p2.display();
// }