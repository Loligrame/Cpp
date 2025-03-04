/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:36:37 by armohame          #+#    #+#             */
/*   Updated: 2025/03/04 09:42:01 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl msg;

    msg.complain("DEBUG");
    msg.complain("INFO");
    msg.complain("WARNING");
    msg.complain("ERROR");
    msg.complain("");
    msg.complain("Incorrect string");
}