/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:53:13 by armohame          #+#    #+#             */
/*   Updated: 2025/03/05 15:19:50 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed{
    private :
        static const int fractionalValue_ = 8;
        int value_;
    public :
        Fixed();
        Fixed(const Fixed& value);
        Fixed &operator=(const Fixed& ting)
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );  
};