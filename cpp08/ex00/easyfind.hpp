/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:55:46 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/07 11:19:45 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream> 

class NoNumberFound : public std::exception
{
	public:
		const char *what() const throw()
		{
			return("Number Not found");
		}
};

template <typename T> 
void easyfind(T container, int n)
{
	typename T::const_iterator i = std::find(container.begin(), container.end(), n);

	if (i != container.end())
		std::cout <<"Number " << n << " found" << std::endl;
	else
		throw NoNumberFound();
}

#endif