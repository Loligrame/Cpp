/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:53:18 by armohame          #+#    #+#             */
/*   Updated: 2025/03/05 15:30:37 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed:: Fixed()
{
}

Fixed:: Fixed(const Fixed& value)
{
   this->value_ = value; 
}

Fixed & Fixed::operator=(const Fixed& ting)
{
    
}

Fixed:: ~Fixed()
{
}