/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:49:33 by cacarval          #+#    #+#             */
/*   Updated: 2024/06/06 15:10:49 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria (std::string const &type)
{
	this->type = type;
	this->flag = 0;
}

AMateria::AMateria(const AMateria &copy)
{
	// std::cout << "[AMateria] copy constructor called" << std::endl;
	*this = copy;
	this->flag = 0;
}

AMateria::~AMateria()
{
	// std::cout << "[AMateria] destructor called" << std::endl;
}



std::string const &AMateria::getType() const
{
	return(this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* shoots Materia at " << target.getName()<< " *" << std::endl;
}