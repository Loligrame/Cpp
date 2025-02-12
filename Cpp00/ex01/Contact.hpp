/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:34:10 by armohame          #+#    #+#             */
/*   Updated: 2025/02/12 14:43:57 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H
#include "PhoneBook.hpp"

class Contact{
    private:
        std::string name;
        std::string phone;
        std::string secret;    
    public: 
    void WriteContact(void);
    void Display();
};
#endif