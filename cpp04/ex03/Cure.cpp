/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:29:05 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/17 15:20:58 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "[Cure] constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	// std::cout << "[Cure] copy constructor called" << std::endl;
}

Cure::~Cure()
{
	// std::cout << "[Cure] destructor called" << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() <<"’s wounds *"<< std::endl;
}

AMateria *Cure::clone() const
{
	return(new Cure);
}