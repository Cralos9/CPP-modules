/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:39:59 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/29 15:24:29 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixednbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixednbr(other.fixednbr)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	(this->fixednbr)= nbr * (1 << Fixed::nbr_bits);
}

Fixed::Fixed(const float floatnbr)
{
	std::cout << "Float constructor called" << std::endl;
	(this->fixednbr)= roundf(floatnbr * (1 << Fixed::nbr_bits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		fixednbr = other.fixednbr;
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const
{
	return(this->fixednbr);
}

void Fixed::setRawBits(int const raw)
{
	fixednbr = raw;
}

int Fixed::toInt(void)const
{
	return((this->fixednbr)/(1 << Fixed::nbr_bits));
}

float Fixed::toFloat(void)const
{
	return(((float)this->fixednbr/(float)(1 << Fixed::nbr_bits)));
}

std::ostream &operator<<(std::ostream &out, Fixed const &copy)
{
	out << copy.toFloat();
	return (out);
}
