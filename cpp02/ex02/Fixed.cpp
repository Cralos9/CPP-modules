/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:39:59 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/31 11:17:54 by cacarval         ###   ########.fr       */
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
	// this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	(this->_fixednbr)= nbr<< this->_nbr_bits;
}

Fixed::Fixed(const float floatnbr)
{
	std::cout << "Float constructor called" << std::endl;
	(this->_fixednbr)= (floatnbr) * float(1 << this->_nbr_bits) + (floatnbr >= 0 ? 0.5 : -0.5);
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

bool Fixed::operator>(const Fixed &other)const
{
	return(this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
	return(this->toFloat() < other.toFloat());
}
bool Fixed::operator>=(const Fixed &other) const
{
	return(this->toFloat() >= other.toFloat());
}
bool Fixed::operator<=(const Fixed &other) const
{
	return(this->toFloat() <= other.toFloat());
}
bool Fixed::operator==(const Fixed &other) const
{
	return(this->toFloat() == other.toFloat());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return(this->toFloat() != other.toFloat());
}
Fixed Fixed::operator+(const Fixed &other) const
{
	return(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const
{
	return(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const
{
	return(this->toFloat() / other.toFloat());
}
Fixed &Fixed::operator++()
{
	this->_fixednbr++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return(temp);
}

Fixed &Fixed::operator--()
{
	this->_fixednbr--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return(temp);

}

Fixed &Fixed::min(Fixed &Fixed1,Fixed &Fixed2)
{
	if (Fixed1 < Fixed2)
		return(Fixed1);
	return(Fixed2);
}

const Fixed &Fixed::min(const Fixed &Fixed1, const Fixed &Fixed2)
{
	if (Fixed1 < Fixed2)
		return(Fixed1);
	return(Fixed2);
}

Fixed &Fixed::max(Fixed &Fixed1, Fixed &Fixed2)
{
	if (Fixed1 < Fixed2)
		return(Fixed2);
	return(Fixed1);
}

const Fixed &Fixed::max(const Fixed &Fixed1, const Fixed &Fixed2)
{
	if (Fixed1 < Fixed2)
		return(Fixed2);
	return(Fixed1);
}


std::ostream &operator<<(std::ostream &out, Fixed const &copy)
{
	out << copy.toFloat();
	return (out);
}
