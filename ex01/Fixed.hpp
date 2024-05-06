/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:38:30 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/06 09:31:11 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <sstream>

class Fixed {
	public:
	// Constructors
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &obj);
	
	// Destructors
		~Fixed();

	// Getters
		int		getRawBits(void) const;
	
	// Setters
		void	setRawBits(int const raw);

	// Overloaded operators
		const Fixed &operator=(const Fixed &obj);
	
	// Other public methods
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &osObj, const Fixed &obj);

#endif