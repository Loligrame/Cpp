/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:51:35 by armohame          #+#    #+#             */
/*   Updated: 2025/03/07 15:38:10 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    Fixed c(5);   // rawValue_ = 5 << 8 = 1280
    Fixed d(10);  // rawValue_ = 10 << 8 = 2560
    Fixed e(20);  // rawValue_ = 20 << 8 = 5120
    Fixed g(5);   // rawValue_ = 5 << 8 = 1280
    Fixed h(10);  // rawValue_ = 10 << 8 = 2560
    Fixed i(20);  // rawValue_ = 20 << 8 = 5120

    std::cout << "Non-const reference min result (modifies):\n";
    Fixed& minRef = d.min(d, e);  // Will modify d or e
    std::cout << "Min : " << minRef.getRawBits() << std::endl;  // Should print 2560 (since 10 < 20)
    std::cout << "d rawValue_ after minRef: " << d.getRawBits() << std::endl;  // Should print 2560

    std::cout << "\nConst reference min result (const):\n";
    const Fixed& minConstRef = d.min(d, c);  // Will NOT modify d or e
    std::cout << "Min const: " << minConstRef.getRawBits() << std::endl;  // Should print 1280 (since 5 < 10)
    std::cout << "d rawValue_ after minCons: " << d.getRawBits() << std::endl;
    
    std::cout << "\nNon-const reference max result (modifies):\n";
    Fixed& maxRef = h.max(h, i);  // Will modify h or i
    std::cout << "Max : " << maxRef.getRawBits() << std::endl;  // Should print 5120 (since 20 > 10)
    std::cout << "h rawValue after max: " << h.getRawBits() << std::endl;  // Should print 5120
    
    std::cout << "\nConst reference max result (const):\n";
    const Fixed& maxConstRef = h.max(g, h);  // Will NOT modify h or g
    std::cout << "Max const: " << maxConstRef.getRawBits() << std::endl;  // Should print 2560 (since 10 > 5)
    std::cout << "h rawValue_ after maxConst: " << h.getRawBits() << std::endl;
    
    std::cout << a + a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}