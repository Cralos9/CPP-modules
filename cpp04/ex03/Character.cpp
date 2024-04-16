/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:39:18 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/16 15:45:34 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->_inventoryCount = 0;
}

Character::Character(std::string name)
{
	this->_name = name;
	this->_inventoryCount = 0;
	this->azul = new t_test();
	this->head = this->azul;
}

Character::Character(const Character &copy)
{
	std::cout << "[Character] copy constructor was called" << std::endl;
	*this = copy;
}

Character::~Character()
{
	t_test *tmp;
	this->azul = this->head;
	for (int i = 0; i < this->_inventoryCount; i++)
		delete this->_inventory[i];
	while(this->azul)
	{
		std::cout << this->azul<< std::endl;
		tmp = this->azul;
		this->azul = this->azul->next;
		delete tmp->atum;
		delete tmp;
	}
}

std::string const &Character::getName() const
{
	return(this->_name);
}

Character &Character::operator = (Character const & src)
{
	if (this != &src)
	{
		this->_inventoryCount = src._inventoryCount;
		this->cleanspace();
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = src._inventory[i]->clone();
	}
	return(*this);
}

void Character::equip(AMateria *m)
{
	if (this->_inventoryCount < 3)
	{
		// std::cout << this->_name << " equiped " << m->getType() << std::endl;
		if (this->_inventoryCount == 0 || this->_inventory[--this->_inventoryCount] != m)
			this->_inventory[this->_inventoryCount++] = m;
		else
			std::cout << "Materia is already equiped"<< std::endl;
	}
	else
		std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if(idx >= 0 && idx <= this->_inventoryCount)
	{
		std::cout << "Unequipped" << std::endl;
		this->azul->atum = this->_inventory[idx];
		this->_inventory[idx] = NULL;
		this->azul = this->azul->next;
		this->azul = new t_test();
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= this->_inventoryCount)
		this->_inventory[idx]->use(target);
	else
		std::cout << "No Materia on this index" << std::endl;
}

void Character::cleanspace()
{
	for(int i = 0; i < 4 ; i++)
		delete this->_inventory[i];
}