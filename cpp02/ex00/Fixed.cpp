/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:53:18 by armohame          #+#    #+#             */
/*   Updated: 2025/03/06 13:25:22 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed:: Fixed() : rawValue_ (0)
{
   std::cout << "Default constructor called" << std::endl;
}

Fixed:: Fixed(Fixed const &obj)
{
   std::cout << "Copy constructor called" << std::endl;
   *this = obj;
}

Fixed & Fixed::operator=(const Fixed& obj)
{
   std::cout << "Copy assignment operator called" << std::endl;
   this->rawValue_ = obj.getRawBits();
	return (*this);
}

Fixed:: ~Fixed()
{
   std::cout << "Destructor called" << std::endl;
}

int Fixed:: getRawBits( void ) const
{
   std::cout << "getRawBits member function called" << std::endl;
   return this->rawValue_;
}

void Fixed:: setRawBits( int const raw )
{
   std::cout << "setRawBits member function called" << std::endl;
   this->rawValue_ = raw;
}