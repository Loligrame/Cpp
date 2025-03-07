/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:51:35 by armohame          #+#    #+#             */
/*   Updated: 2025/03/07 12:15:28 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );

Fixed sum(0.0f);

// Add 0.1 a hundred times with fix
for (int i = 0; i < 1000; ++i) {
    sum += Fixed(0.1f);
}

float float_sum = 0.1;

// Add 0.1 a hundred times with float
for (int i = 0; i < 1000; ++i) {
    float_sum += 0.1;
    std::cout << float_sum  << std::endl;
    
}

// Print the result
std::cout << "Expected sum: 10.0" << std::endl;
std::cout << "Actual sum: " << sum.toFloat() << std::endl;
std::cout << "Actual float_sum: " << float_sum  << std::endl;

std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;

std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;

return 0;
}