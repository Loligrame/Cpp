/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:14:03 by armohame          #+#    #+#             */
/*   Updated: 2025/02/12 15:00:28 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cctype>

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
void Contact::Display()
{
        std::cout << " name : " << name  << std::endl;
        std::cout << " phone : " << phone << std::endl;
        std::cout << " secret : " << secret << std::endl;
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
        for(int i = 0; i < 2; i++)
            _Contact[i].WriteContact();
        for(int i = 0; i < 2; i++)
            _Contact[i].Display();
}

int main()
{   
    PhoneBook add;
    // Contact con[2];
    // int i = 0;
    add.AddContact();
    // con[i++].Display();
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