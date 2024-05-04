/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:39:31 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/04 17:50:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <sstream>

class Fixed {
		friend std::ostream &operator<<(std::ostream &osObj, const Fixed &obj);
		friend bool operator>(const Fixed &obj1, const Fixed &obj2);
		friend bool operator<(const Fixed &obj1, const Fixed &obj2);
		friend bool operator>=(const Fixed &obj1, const Fixed &obj2);
		friend bool operator<=(const Fixed &obj1, const Fixed &obj2);
		friend bool operator==(const Fixed &obj1, const Fixed &obj2);
		friend bool operator!=(const Fixed &obj1, const Fixed &obj2);
		friend Fixed operator+(const Fixed &obj1, const Fixed &obj2);
		friend Fixed operator-(const Fixed &obj1, const Fixed &obj2);
		friend Fixed operator*(const Fixed &obj1, const Fixed &obj2);
		friend Fixed operator/(const Fixed &obj1, const Fixed &obj2);
		friend Fixed operator++(Fixed &obj);
		friend Fixed operator++(Fixed &obj, int u);
		friend Fixed operator--(Fixed &obj);
		friend Fixed operator--(Fixed &obj, int u);
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &obj);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		float toInt(void) const;
		static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
		static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
		const Fixed &operator=(const Fixed &obj);
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
};

#endif