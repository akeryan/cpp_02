/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:38:17 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/04 14:38:22 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default contructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int contructor called" << std::endl;
	fixedPointValue = (value * (1 << fractionalBits));
}

Fixed::Fixed(const float value) {
	std::cout << "Float contructor called" << std::endl;
	fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &obj) { 
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return fixedPointValue;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return fixedPointValue / (static_cast<float>(1 << fractionalBits));
}

float Fixed::toInt(void) const {
	return fixedPointValue / (1 << fractionalBits);
}

const Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		fixedPointValue = obj.getRawBits(); 
	}
	return *this;
}

std::ostream &operator<<(std::ostream &osObj, const Fixed &obj) {
	osObj << obj.toFloat();
	return osObj;
}

