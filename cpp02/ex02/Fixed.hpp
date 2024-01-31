/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:40:01 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/31 10:49:25 by cacarval         ###   ########.fr       */
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
	int _fixednbr;
	static const int _nbr_bits = 8;

	public:

	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	Fixed(const int nbr);
	Fixed(const float floatnbr);
	~Fixed();

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	int getRawBits(void)const;
	float toFloat(void)const;
	int toInt(void)const;
	void setRawBits(int const raw);
	static Fixed &min(Fixed &Fixed1,Fixed &Fixed2);
	static const Fixed &min(const Fixed &Fixed1, const Fixed &Fixed2);
	static Fixed &max(Fixed &Fixed1, Fixed &Fixed2);
	static const Fixed &max(const Fixed &Fixed1, const Fixed &Fixed2);

};

std::ostream &operator<<(std::ostream &out, Fixed const &copy);

#endif