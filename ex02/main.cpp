/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:39:41 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/07 17:05:56 by akeryan          ###   ########.fr       */
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

	Fixed e1, e2;
	e1 = Fixed (8388607);
	e2 = Fixed (0.74f);

	// post-increment test
	int i = 260;
	while (i) {
		e1++;
		i--;
	}
	std::cout << "result3: " << e1.getRawBits() << std::endl;

	//comparison test
	std::cout << "Greater: " << (e1 > e2) << std::endl;
	std::cout << "Lesser or equal: " << (e1 <= e2) << std::endl;

	const Fixed a1(10);
	const Fixed a2(20);
	
	//min-max test
	std::cout << "max: " << std::fixed << Fixed::max(e1, e2) << std::endl;
	std::cout << "min: " << Fixed::min(a1, a2) << std::endl;

	return 0;
}
