/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:39:59 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/04 14:05:29 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixednbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixednbr(other._fixednbr)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixednbr = other._fixednbr;
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	(this->_fixednbr)= nbr * (1 << Fixed::_nbr_bits);
}

Fixed::Fixed(const float floatnbr)
{
	std::cout << "Float constructor called" << std::endl;
	(this->_fixednbr)= roundf(floatnbr * (1 << Fixed::_nbr_bits));
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const
{
	return(this->_fixednbr);
}

void Fixed::setRawBits(int const raw)
{
	_fixednbr = raw;
}

int Fixed::toInt(void)const
{
	return((this->_fixednbr)/(1 << Fixed::_nbr_bits));
}

float Fixed::toFloat(void)const
{
	return(((float)this->_fixednbr/(float)(1 << Fixed::_nbr_bits)));
}

std::ostream &operator<<(std::ostream &out, Fixed const &copy)
{
	out << copy.toFloat();
	return (out);
}
