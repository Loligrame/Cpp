/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:14:03 by armohame          #+#    #+#             */
/*   Updated: 2025/02/20 11:23:06 by armohame         ###   ########.fr       */
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
    if(!isdigit(phone[0]))
        return false;
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
    std::cout << " |     " << index + 1
              << " | " << std::setw(10) << Truncate(first_name)
              << " | " << std::setw(10) << Truncate(last_name)
              << " | " << std::setw(10) << Truncate(nickname) << " | " 
              << std::endl;
    std::cout << " +-------+------------+------------+------------+" << std::endl;
}

void PhoneBook::DisplayAll()
{
    int i = 0;
    std::cout << " +-------+------------+------------+------------+" << std::endl;
    std::cout << " | index | first_name | last_name  |  nickname  | " << std::endl;
    std::cout << " +-------+------------+------------+------------+" << std::endl;
    while(i < 8)
    {
        _Contact[i].Display(i);
        i++;
    }
}

static std::string getContactline(int index, std::string instruction)
{
    
    std::string input = "";
    while(!std::cin.eof())
    {
        if(std::cin.eof())
            break;
        std::cout << index << bold << instruction << reset << std::endl;
        std::getline(std::cin, input);
        if(!input.empty())
            break;
    }
    return input;
}
    
void Contact:: WriteContact(int i)
{
        this-> first_name = getContactline(i + 1, " Enter your first_name : ");
        this-> last_name = getContactline(i + 1, " Enter your last_name : ");
        this-> nickname = getContactline(i + 1, " Enter your nickname : ");
        do {
            if(std::cin.eof())
                break;
            std::cout << i + 1 << " Enter Phone : " << std::endl;
            std::getline(std::cin, phone);
            if(!isValidPhoneNum(phone))
            std::cout << red <<"Enter a valid phone number" << reset << std::endl;
        }while(!isValidPhoneNum(phone));
        this-> secret = getContactline(i + 1, " Enter your darkest secret : ");
        if(!std::cin.eof())
            std::cout << green << "Contact added !" << reset << std::endl;
        return;
}

void PhoneBook:: AddContact(int index)
{
        contact_num = index;
        _Contact[contact_num].WriteContact(contact_num);
        return;
}

void PhoneBook:: SearchContact()
{
        std::string index;
        
        DisplayAll();
        std::cout << "Enter an index between 1 and 8 :";
        std::getline(std::cin, index);
        if(index.length() == 1 && std::isdigit(index[0]))
        {
            int idx = index[0] - '0' - 1;
            if (idx >= 0 && idx < 8)
            {
                std::cout << blue << " First_name : " << reset << _Contact[idx].GetFirstName() << std::endl;
                std::cout << blue << " Last_name : " << reset << _Contact[idx].GetLastName() << std::endl;
                std::cout << blue << " Nickname : " << reset << _Contact[idx].GetNickname() << std::endl;
                std::cout << blue << " Phone : " << reset << _Contact[idx].GetPhone() << std::endl;
                std::cout << blue << " Darkest secret : "  << reset << _Contact[idx].GetSecret() << std::endl;
            }
            else             
                std::cout << red << "Enter an index between 1 and 8 please" << reset << std::endl;
        }
}

int main()
{   
    PhoneBook add;
    std::string input;
    int index = 0;

    while (!std::cin.eof())
    {
        index = index % 8; 
        std::cout << "Enter a command : ADD, SEARCH or EXIT " << std::endl;
        std::getline(std::cin, input);          
        if (std::cin.eof() || input == "EXIT")
        {
            std::cout << yellow << "Exiting program..." << reset << std::endl;
            break;
        }
        else if(input == "ADD")
            add.AddContact(index++);
        else if(input == "SEARCH")
            add.SearchContact();
        else if(!input.empty())
            std::cout << red << "Wrong command" << reset << std::endl;
    }
    return 0;
}