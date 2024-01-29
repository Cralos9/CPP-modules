/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:40:01 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/29 15:23:52 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

class Fixed
{
	private:
	int fixednbr;
	static const int nbr_bits = 8;

	public:

	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	Fixed(const int nbr);
	Fixed(const float floatnbr);
	~Fixed();

	int getRawBits(void)const;
	float toFloat(void)const;
	int toInt(void)const;

	void setRawBits(int const raw);

};

std::ostream &operator<<(std::ostream &out, Fixed const &copy);

#endif