/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:36:48 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/06 12:49:25 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T> Array<T>::Array()
{
	std::cout << "Array default constructor called" << std::endl;
	this->_array = new T[0];
	this->_size = 0;
}

template <class T> Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
    delete[] (this->_array);
}

template <class T> Array<T>::Array(unsigned int n)
{
	std::cout << "Array Int constructor called" << std::endl;
	this->_array = new T[n];
	this->_size = n;
}

template <class T> Array<T>::Array(Array const &cpy)
{
	std::cout << "Array copy constructor called" << std::endl;
	this->_array = NULL;
	*this = cpy;
}

template <class T> Array<T> &Array<T>::operator=(Array const &cpy)
{
	std::cout << "Array copy assignment operator called" << std::endl;
	if (this == &cpy)
		return (*this);
	delete[] (this->_array);
	this->_array = new T[cpy._size];
	for (unsigned int i = 0; i < cpy._size; i++)
		this->_array[i] = cpy._array[i];
	this->_size = cpy._size;
	return(*this);
}

template  <class T> T &Array<T>::operator[](unsigned int n)
{
	/* std::cout << "[] overload operator" << std::endl; */
	if(n >= this->_size)
		throw OutofBounds();
	return(this->_array[n]);
}

template <class T> unsigned int  Array<T>::size() const
{
	return(this->_size);
}

template <class T> const char *Array<T>::OutofBounds::what() const throw()
{
	return ("Index out of Bounds");
}