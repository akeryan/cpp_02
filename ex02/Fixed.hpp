/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:39:31 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/05 16:34:06 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <sstream>

class Fixed {
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &obj);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
		static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
		const Fixed &operator=(const Fixed &obj);
		bool operator>(const Fixed &obj2) const;
		bool operator<(const Fixed &obj2) const;
		bool operator>=(const Fixed &obj2) const;
		bool operator<=(const Fixed &obj2) const;
		bool operator==(const Fixed &obj2) const;
		bool operator!=(const Fixed &obj2) const;
		Fixed operator+(const Fixed &obj2) const;
		Fixed operator-(const Fixed &obj2) const;
		Fixed operator*(const Fixed &obj2) const;
		Fixed operator/(const Fixed &obj2) const;
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &osObj, const Fixed &obj);

#endif