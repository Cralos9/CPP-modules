/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:53:21 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/07 15:31:43 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T> class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		~MutantStack(){}
		MutantStack(MutantStack const &cpy) : std::stack<T>()
		{
			*this = cpy;
			}
		MutantStack &operator=(MutantStack const &cpy)
		{
			if (this != &cpy) 
			{
				std::stack<T>::operator =(cpy);
			}
			return *this;
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){return (std::stack<T>::c.begin());}
		iterator end(){return (std::stack<T>::c.end());}
};



#endif