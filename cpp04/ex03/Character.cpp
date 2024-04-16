/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:39:18 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/08 12:18:17 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


ICharacter::ICharacter(std::string name)
{
	this->_name = name;
}

ICharacter::~ICharacter()
{
	
}

std::string const &ICharacter::getName() const
{
	return(this->_name);
}

void ICharacter::equip(AMateria *m)
{
	
}

void ICharacter::unequip(int idx)
{

}

void ICharacter::use(int idx, ICharacter& target)
{

}