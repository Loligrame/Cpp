/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:34:10 by armohame          #+#    #+#             */
/*   Updated: 2025/02/20 11:26:19 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H
#include "PhoneBook.hpp"

class Contact{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;   
        std::string phone;
        std::string secret;    
    public:
        void WriteContact(int index);
        void Display(int index);
        std::string GetFirstName() const { return first_name; }
        std::string GetLastName() const { return last_name; }
        std::string GetNickname() const { return nickname; }
        std::string GetPhone() const { return phone; }
        std::string GetSecret() const { return secret; }
};
#endif