/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:49:33 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/16 14:12:26 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria (std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "[AMateria] copy constructor called" << std::endl;
	*this = copy;
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] destructor called" << std::endl;
}



std::string const &AMateria::getType() const
{
	return(this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* shoots Materia at " << target.getName()<< " *" << std::endl;
}