/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:53:18 by armohame          #+#    #+#             */
/*   Updated: 2025/03/07 11:28:47 by armohame         ###   ########.fr       */
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

Fixed:: Fixed(const int value)
{
   std::cout << "Int constructor called" << std::endl;
    this->rawValue_ = value << this->fractionalBits_;
}

Fixed:: Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->rawValue_ = roundf(value * (1 << this->fractionalBits_));
}

float Fixed::toFloat(void) const
{
	float	floatResult = this->rawValue_ / (float)(1 << this->fractionalBits_);
	return (floatResult);
}

int Fixed::toInt(void) const
{
	int	intResult = this->rawValue_ / (1 << this->fractionalBits_);
	return (intResult);
}

std::ostream & operator<<(std::ostream &o, Fixed const &obj)
{
    o << obj.toFloat();
    return (o);
}

Fixed& Fixed::operator+=(const Fixed& other) {
   this->rawValue_ += other.getRawBits();
   return *this;
}
