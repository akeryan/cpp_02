/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:39:31 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/07 17:02:42 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <sstream>

class Fixed {
	public:
	// Constructors
		Fixed();
		Fixed(const Fixed &obj);
		Fixed(const int value);
		Fixed(const float value);

	// Destructors
		~Fixed();

	// Setters
		void setRawBits(int const raw);

	// Getters
		int getRawBits(void) const;

	// Overloaded operators
		const Fixed &operator=(const Fixed &obj);

		// comparison operators
		bool operator>(const Fixed &obj2) const;
		bool operator<(const Fixed &obj2) const;
		bool operator>=(const Fixed &obj2) const;
		bool operator<=(const Fixed &obj2) const;
		bool operator==(const Fixed &obj2) const;
		bool operator!=(const Fixed &obj2) const;

		// arithmetic operators
		Fixed operator+(const Fixed &obj2) const;
		Fixed operator-(const Fixed &obj2) const;
		Fixed operator*(const Fixed &obj2) const;
		Fixed operator/(const Fixed &obj2) const;

		// pre-increment operators
		Fixed operator++();
		Fixed operator--();

		// post-increment operators
		Fixed operator++(int);
		Fixed operator--(int);

	// Other public methods
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed &max(Fixed &obj1, Fixed &obj2);
		static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
		static Fixed &min(Fixed &obj1, Fixed &obj2);
		static const Fixed &min(const Fixed &obj1, const Fixed &obj2);

	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
};

// Overloaded non-member operators
std::ostream &operator<<(std::ostream &osObj, const Fixed &obj);

#endif