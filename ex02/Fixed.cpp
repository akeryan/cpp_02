/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:39:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/07 17:15:39 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <limits.h>
#include "Fixed.hpp"

// ---------------------- CONSTRUCTORS (WITH PROTECTIONS) ---------------------

Fixed::Fixed() : fixedPointValue(0) {
}

Fixed::Fixed(const int value) {
	if (value > (INT_MAX / (1 << fractionalBits))) {
		std::cerr << "Error: overflow in the IntConstructor" << std::endl;
		exit(1);	
	}
	if (value < (INT_MIN / (1 << fractionalBits))) {
		std::cerr << "Error: underflow in the IntConstructor" << std::endl;
		exit(1);	
	}
	fixedPointValue = (value * (1 << fractionalBits));
}

Fixed::Fixed(const float value) {
	if (value > (INT_MAX / static_cast<float>(1 << fractionalBits) - 0.01)) {
		std::cerr << "Error: overflow in the Float Constructor" << std::endl;
		exit(1);	
	}
	if (value < (INT_MIN / static_cast<float>(1 << fractionalBits) - 0.01)) {
		std::cerr << "Error: underflow in the Float Constructor" << std::endl;
		exit(1);	
	}
	fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &obj) { 
	*this = obj;
}

// --------------------------- DESTRUCTORS -------------------------------------

Fixed::~Fixed() {
	return ;
}

// ----------------------------- GETTERS ---------------------------------------

int Fixed::getRawBits(void) const {
	return fixedPointValue;
}

// ------------------------- SETTERS (WITH PROTECTIONS) ------------------------

void Fixed::setRawBits(const int raw) {
	if (raw > INT_MAX || raw < INT_MIN) {
		std::cout << "WARNING: setRawBits(): entered value is beyond 'int' capacity" << std::endl;
		return ;
	}
	fixedPointValue = raw;
}

// ----------------------- OVERLOADED OPERATORS --------------------------------

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

// Comparison operators -------------------------

bool Fixed::operator>(const Fixed &obj) const {
	if (this->getRawBits() > obj.getRawBits())
		return true;
	else	
		return false;
}

bool Fixed::operator<(const Fixed &obj) const {
	if (this->getRawBits() < obj.getRawBits())
		return true;
	else	
		return false;
}

bool Fixed::operator<=(const Fixed &obj) const {
	if (this->getRawBits() <= obj.getRawBits())
		return true;
	else	
		return false;
}

bool Fixed::operator>=(const Fixed &obj) const {
	if (this->getRawBits() >= obj.getRawBits())
		return true;
	else	
		return false;
}

bool Fixed::operator!=(const Fixed &obj) const {
	if (this->getRawBits() != obj.getRawBits())
		return true;
	else	
		return false;
}

bool Fixed::operator==(const Fixed &obj) const {
	if (this->getRawBits() == obj.getRawBits())
		return true;
	else	
		return false;
}

// Arithmetic operators --------------------------

Fixed Fixed::operator+(const Fixed &obj) const {
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) const {
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const {
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const {
	return Fixed(this->toFloat() / obj.toFloat());
}

// Pre-increment operators -----------------------

Fixed Fixed::operator++() {
	if (this->fixedPointValue < INT_MAX)
		this->fixedPointValue++;
	else 
		std::cout << "WARNING: pre-increment operator (++) wan't applied, otherwise OVERFLOW would occur" << std::endl;
	return *this;
}


Fixed Fixed::operator--() {
	if (this->fixedPointValue > INT_MIN)
		this->fixedPointValue--;
	else 
		std::cout << "WARNING: pre-decrement operator (--) wan't applied, otherwise UNDERFLOW would occur" << std::endl;
	return *this;
}

// Post-increment operators ------------------------

Fixed Fixed::operator++(int) {
	Fixed temp;

	temp = *this;
	if (this->fixedPointValue < INT_MAX)
		this->fixedPointValue++;
	else 
		std::cout << "WARNING: post-increment operator (++) wan't applied, otherwise OVERFLOW would occur" << std::endl;
	return temp;
}
Fixed Fixed::operator--(int) {
	Fixed temp;

	temp = *this;
	if (this->fixedPointValue > INT_MIN)
		this->fixedPointValue--;
	else 
		std::cout << "WARNING: post-decrement operator (--) wan't applied, otherwise UNDERFLOW would occur" << std::endl;
	return temp;
}

// ------------------------- MIN-MAX ---------------------------------------------

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2) {
	return obj1 > obj2 ? obj1 : obj2;
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2) {
	return obj1 > obj2 ? obj1 : obj2;
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2) {
	return obj1 < obj2 ? obj1 : obj2;
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2) {
	return obj1 < obj2 ? obj1 : obj2;
}

// --------------------- OTHER PUBLIC METHODS -------------------------------------

float Fixed::toFloat(void) const {
	return fixedPointValue / (static_cast<float>(1 << fractionalBits));
}

int Fixed::toInt(void) const {
	return fixedPointValue / (1 << fractionalBits);
}