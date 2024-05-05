/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:39:41 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/05 16:36:47 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed (2));
	Fixed c;

	c = Fixed(3.2f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a,b) << std::endl;

	std::cout << "div: " << b / Fixed(2.1f) << std::endl;
	std::cout << "div: " << b * Fixed(2) << std::endl;
	std::cout << "add: " << b + b << std::endl;
	std::cout << "subtr: " << b - c << std::endl;
	std::cout << "greater: " << (a < b) << std::endl;
	Fixed f = b + c;
	std::cout << "assign: " << f << std::endl;

	return 0;
}
