/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:22:58 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/07 12:05:41 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span
{
private:
	unsigned int _list_size;
	std::vector<int> vec;
public:
	Span();
	~Span();
	Span(unsigned int n);
	Span(Span const &cpy);
	Span &operator=(Span const &cpy);
	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
	class MaxThrow : public std::exception
	{
		const char *what() const throw();
	};
	class NoSpan : public std::exception
	{
		const char *what() const throw();
	};
};






#endif