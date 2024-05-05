/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:39:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/05 16:37:29 by akeryan          ###   ########.fr       */
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

int Fixed::toInt(void) const {
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

bool Fixed::operator>(const Fixed &obj2) const {
	if (this->getRawBits() > obj2.getRawBits())
		return true;
	else	
		return false;
}

bool Fixed::operator<(const Fixed &obj2) const {
	if (this->getRawBits() < obj2.getRawBits())
		return true;
	else	
		return false;
}

bool Fixed::operator<=(const Fixed &obj2) const {
	if (this->getRawBits() <= obj2.getRawBits())
		return true;
	else	
		return false;
}

bool Fixed::operator>=(const Fixed &obj2) const {
	if (this->getRawBits() >= obj2.getRawBits())
		return true;
	else	
		return false;
}

bool Fixed::operator!=(const Fixed &obj2) const {
	if (this->getRawBits() != obj2.getRawBits())
		return true;
	else	
		return false;
}

bool Fixed::operator==(const Fixed &obj2) const {
	if (this->getRawBits() == obj2.getRawBits())
		return true;
	else	
		return false;
}

Fixed Fixed::operator+(const Fixed &obj2) const {
	return Fixed(this->toFloat() + obj2.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj2) const {
	return Fixed(this->toFloat() - obj2.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj2) const {
	return Fixed(this->toFloat() * obj2.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj2) const {
	return Fixed(this->toFloat() / obj2.toFloat());
}

Fixed Fixed::operator++() {
	this->fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp;

	temp = *this;
	this->fixedPointValue++;
	return temp;
}

Fixed Fixed::operator--() {
	this->fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp;

	temp = *this;
	this->fixedPointValue--;
	return temp;
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2) {
	return obj1 > obj2 ? obj1 : obj2;
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2) {
	return obj1 < obj2 ? obj1 : obj2;
}

