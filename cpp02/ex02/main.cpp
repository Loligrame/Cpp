/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:51:35 by armohame          #+#    #+#             */
/*   Updated: 2025/03/10 11:29:37 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void testComparison()
{
    std::cout << yellow << "\n--- Testing Comparison Operators ---" << reset << std::endl;
    Fixed a(5.05f);
    Fixed b(2);
    Fixed c(5.05f);

    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    std::cout << bold << "a > b : " << reset <<(a > b) << std::endl;
    std::cout << bold << "a < b : " << reset << (a < b) << std::endl;
    std::cout << bold << "a >= c : " << reset << (a >= c) << std::endl;
    std::cout << bold << "a <= c : " << reset << (a <= c) << std::endl;
    std::cout << bold << "a == c : " << reset << (a == c) << std::endl;
    std::cout << bold << "a != b : " << reset << (a != b) << std::endl;
}

void testMinMax()
{
    std::cout << yellow <<"\n--- Testing Min/Max Functions ---" << reset << std::endl;
    Fixed a(1);
    Fixed b(3);

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << bold << "Min(a, b) : " << reset << Fixed::min(a, b) << std::endl;
    std::cout << bold << "Max(a, b) : " << reset <<  Fixed::max(a, b) << std::endl;
}

int main( void ) 
{
    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << yellow <<"\n--- Test Main obligatoire ---" << reset << std::endl;
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;

    testMinMax();
    testComparison();
    
    return 0;
}