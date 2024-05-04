/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:39:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/04 20:14:45 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
}

Fixed::Fixed(const int value) {
	fixedPointValue = (value * (1 << fractionalBits));
}

Fixed::Fixed(const float value) {
	fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &obj) { 
	*this = obj;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
	return fixedPointValue;
}

void Fixed::setRawBits(const int raw) {
	fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return fixedPointValue / (static_cast<float>(1 << fractionalBits));
}

float Fixed::toInt(void) const {
	return fixedPointValue / (1 << fractionalBits);
}

const Fixed &Fixed::operator=(const Fixed &obj) {
	if (this != &obj) {
		fixedPointValue = obj.getRawBits(); 
	}
	return *this;
}

std::ostream &operator<<(std::ostream &osObj, const Fixed &obj) {
	osObj << obj.toFloat();
	return osObj;
}

bool operator>(const Fixed &obj1, const Fixed &obj2) {
	if (obj1.fixedPointValue > obj2.fixedPointValue)
		return true;
	else	
		return false;
}

bool operator<(const Fixed &obj1, const Fixed &obj2) {
	if (obj1.fixedPointValue < obj2.fixedPointValue)
		return true;
	else	
		return false;
}

bool operator<=(const Fixed &obj1, const Fixed &obj2) {
	if (obj1.fixedPointValue <= obj2.fixedPointValue)
		return true;
	else	
		return false;
}

bool operator>=(const Fixed &obj1, const Fixed &obj2) {
	if (obj1.fixedPointValue >= obj2.fixedPointValue)
		return true;
	else	
		return false;
}

bool operator!=(const Fixed &obj1, const Fixed &obj2) {
	if (obj1.fixedPointValue != obj2.fixedPointValue)
		return true;
	else	
		return false;
}

bool operator==(const Fixed &obj1, const Fixed &obj2) {
	if (obj1.fixedPointValue == obj2.fixedPointValue)
		return true;
	else	
		return false;
}

Fixed operator+(const Fixed &obj1, const Fixed &obj2) {
	return Fixed(obj1.toFloat() + obj2.toFloat());
}

Fixed operator-(const Fixed &obj1, const Fixed &obj2) {
	return Fixed(obj1.toFloat() - obj2.toFloat());
}

Fixed operator*(const Fixed &obj1, const Fixed &obj2) {
	return Fixed(obj1.toFloat() * obj2.toFloat());
}

Fixed operator/(const Fixed &obj1, const Fixed &obj2) {
	return Fixed( obj1.toFloat() / obj2.toFloat());
}

Fixed operator++(Fixed &obj) {
	obj.fixedPointValue++;
	return obj;
}

Fixed operator++(Fixed &obj, int) {
	Fixed temp;

	temp = obj;
	obj.fixedPointValue++;
	return temp;
}

Fixed operator--(Fixed &obj) {
	obj.fixedPointValue--;
	return obj;
}

Fixed operator--(Fixed &obj, int) {
	Fixed temp;

	temp = obj;
	obj.fixedPointValue--;
	return temp;
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2) {
	return obj1 > obj2 ? obj1 : obj2;
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2) {
	return obj1 < obj2 ? obj1 : obj2;
}

