/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:26:36 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/06 12:26:54 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>


template <class T> class Array
{
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(Array const &cpy);
		Array &operator=(Array const &cpy);
		unsigned int size() const;
		T &operator[](unsigned int i);
		class OutofBounds : public std::exception
		{
			const char *what() const throw();
		};
	private:
		T *_array;
		unsigned int _size;
	
};


#include "Array.tpp"

#endif