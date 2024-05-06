/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:29:26 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/06 09:30:17 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
	// Constructors
		Fixed();
		Fixed(const Fixed &obj);

	// Destructors
		~Fixed();
	
	// Overloaded operators
		const Fixed &operator=(const Fixed &obj);
	
	// Getters and setters
		int getRawBits(void) const;
		void setRawBits(int const raw);
	
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
};

#endif