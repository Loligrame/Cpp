/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:34:10 by armohame          #+#    #+#             */
/*   Updated: 2025/02/14 15:34:13 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H
#include "PhoneBook.hpp"

class Contact{
    private:
        std::string name;
        std::string nickname;    
        std::string phone;
        std::string secret;    
    public:
        Contact();
        ~Contact();
        void WriteContact(void);
        void Display(int index);
};
#endif