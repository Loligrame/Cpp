/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:53:13 by armohame          #+#    #+#             */
/*   Updated: 2025/03/07 12:17:06 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private :
        static const int fractionalBits_ = 8;
        int rawValue_;
    public :
        Fixed();
        Fixed(const Fixed& obj);
        Fixed(const int value);
        Fixed(const float value);
        Fixed &operator=(const Fixed& obj);
        Fixed& operator+=(const Fixed& other);
        ~Fixed();

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream &	operator<<(std::ostream &o, Fixed const &obj);

#endif