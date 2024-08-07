/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:23:00 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/07 14:30:55 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span()
{
	this->_list_size = 0;
}

Span::~Span()
{

}

Span::Span(unsigned int n)
{
	this->_list_size = n;
}

Span::Span(Span const &cpy)
{
	*this = cpy;
}

Span &Span::operator=(Span const &cpy)
{
	if (this == &cpy)
		return (*this);
	this->_list_size = cpy._list_size;
	this->vec = cpy.vec;
	return (*this);
}

void Span::addNumber(int n)
{
	if (vec.size() < _list_size)
		vec.push_back(n);
	else
		throw MaxThrow();
}

int Span::shortestSpan()
{
	if (vec.size() < 2)
		throw NoSpan();
	std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());
    int minSpan = sortedVec[1] - sortedVec[0];
    for (std::vector<int>::iterator i = sortedVec.begin(); i != sortedVec.end() - 1; ++i) 
	{
        int span = *(i + 1) - *i;
        if (span < minSpan) 
            minSpan = span;
    }
    return (abs(minSpan));
}

int Span::longestSpan()
{
	if (vec.size() < 2)
		throw NoSpan();
	return (abs(*std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end())));
}


const char *Span::MaxThrow::what() const throw()
{
	return("Can't add more numbers to Span, Limit Reached");
}

const char *Span::NoSpan::what() const throw()
{
	return("Not enough numbers to get Span");
}