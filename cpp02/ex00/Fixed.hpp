/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:53:13 by armohame          #+#    #+#             */
/*   Updated: 2025/03/06 13:38:28 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed{
    private :
        static const int fractionalBits_ = 8;
        int rawValue_;
    public :
        Fixed();
        Fixed(const Fixed& value);
        Fixed &operator=(const Fixed& ting);
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );  
};