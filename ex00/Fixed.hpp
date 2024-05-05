/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:29:26 by akeryan           #+#    #+#             */
/*   Updated: 2024/05/05 13:53:43 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
		int					fixedPointValue;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		const Fixed &operator=(const Fixed &obj);
};

#endif