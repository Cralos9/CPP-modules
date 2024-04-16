/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:21:02 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/16 14:14:29 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "[Ice] constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	std::cout << "[Ice] copy constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "[Ice] destructor called" << std::endl;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an Ice Bolt at " << target.getName()<< " *" << std::endl;
}

AMateria *Ice::clone() const
{
	return(new Ice);
}